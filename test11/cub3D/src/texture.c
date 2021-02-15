/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:05:33 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:56:20 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_texture_set(t_cub3d *cub, char *pth, int opt)
{
	if (!(cub->txt[opt]->img = mlx_xpm_file_to_image(cub->mlx, pth,
		&cub->txt[opt]->wid, &cub->txt[opt]->hei)))
		return (0);
	cub->txt[opt]->dat = mlx_get_data_addr(cub->txt[opt]->img,
		&cub->txt[opt]->bpp, &cub->txt[opt]->siz, &cub->txt[opt]->end);
	return (1);
}

void				ft_texture(t_cub3d *cub, t_ray *ray)
{
	t_lin			*lin;
	double			wlx;

	if (!(lin = (t_lin *)malloc(sizeof(t_lin))))
		ft_tool_exit(1, cub, 1, "Sorry! Error occurred during line malloc!");
	ft_util_bzero(lin, sizeof(t_lin));
	lin->pox = ray->pix;
	if (ray->sid == 0 || ray->sid == 1)
		wlx = cub->pos->poy + ray->perp_wd * ray->ray_diy;
	else
		wlx = cub->pos->pox + ray->perp_wd * ray->ray_dix;
	wlx -= floor(wlx);
	if (cub->map->map[ray->map_poy][ray->map_pox] == '1')
		ft_texture_side(cub, ray, lin, wlx);
	lin->py0 = 0;
	lin->py1 = ray->stt;
	ft_image_color(cub, lin, cub->clr_ceiling);
	lin->py0 = cub->hei;
	lin->py1 = ray->end;
	ft_image_color(cub, lin, cub->clr_floor);
}

void				ft_texture_side(t_cub3d *cub, t_ray *ray,
	t_lin *lin, double wlx)
{
	t_img			*img;
	int				txx;

	img = cub->txt[3];
	if (ray->sid == 1)
		img = cub->txt[2];
	if (ray->sid == 2)
		img = cub->txt[1];
	if (ray->sid == 3)
		img = cub->txt[0];
	txx = (int)(wlx * (double)img->wid);
	if (((ray->sid == 0 || ray->sid == 1) && ray->ray_dix > 0) ||
		((ray->sid == 2 || ray->sid == 3) && ray->ray_diy < 0))
		txx = img->wid - txx - 1;
	lin->py0 = ray->end;
	lin->py1 = ray->stt;
	lin->txx = txx;
	ft_image_lin_txt_clr(cub, ray, lin, img);
}
