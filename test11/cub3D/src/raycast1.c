/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:36:53 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 11:42:28 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_raycasting(t_cub3d *cub)
{
	t_ray			*ray;

	if (!(ray = (t_ray *)malloc(sizeof(t_ray))))
		return (0);
	ft_util_bzero(ray, sizeof(t_ray));
	if (!(ray->z_buffr = (double *)malloc(sizeof(double) * cub->wid)))
		return (0);
	ft_util_bzero(ray->z_buffr, sizeof(double) * cub->wid);
	while (ray->pix < cub->wid)
		ft_raycasting_main(cub, ray);
	if (!ft_draw_sprite(cub, ray))
		return (0);
	if (cub->sav == 1)
	{
		cub->sav = 0;
		ft_bitmap_save(cub->img, "cub3D");
		ft_tool_exit(0, cub, 0, "");
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img->img, 0, 0);
	free(ray->z_buffr);
	free(ray);
	return (1);
}

void				ft_raycasting_main(t_cub3d *cub, t_ray *ray)
{
	ft_raycasting_main_init(cub, ray);
	ft_raycasting_main_step(cub, ray);
	ft_raycasting_main_hit_(cub, ray);
	ft_raycasting_main_perp(cub, ray);
	ray->z_buffr[ray->pix] = ray->perp_wd;
	ft_texture(cub, ray);
	ray->pix++;
}

void				ft_raycasting_main_init(t_cub3d *cub, t_ray *ray)
{
	ray->cam_pox = (2 * ray->pix) / (double)cub->wid - 1;
	ray->ray_dix = cub->pos->dix + cub->pos->plx * ray->cam_pox;
	ray->ray_diy = cub->pos->diy + cub->pos->ply * ray->cam_pox;
	ray->map_pox = (int)cub->pos->pox;
	ray->map_poy = (int)cub->pos->poy;
	ray->dlt_pox = fabs(1 / ray->ray_dix);
	ray->dlt_poy = fabs(1 / ray->ray_diy);
	ray->hit = 0;
}

void				ft_raycasting_main_step(t_cub3d *cub, t_ray *ray)
{
	if (ray->ray_dix < 0)
	{
		ray->stp_pox = -1;
		ray->sid_pox = (cub->pos->pox - ray->map_pox) * ray->dlt_pox;
	}
	else
	{
		ray->stp_pox = 1;
		ray->sid_pox = (ray->map_pox + 1.0 - cub->pos->pox) * ray->dlt_pox;
	}
	if (ray->ray_diy < 0)
	{
		ray->stp_poy = -1;
		ray->sid_poy = (cub->pos->poy - ray->map_poy) * ray->dlt_poy;
	}
	else
	{
		ray->stp_poy = 1;
		ray->sid_poy = (ray->map_poy + 1.0 - cub->pos->poy) * ray->dlt_poy;
	}
}
