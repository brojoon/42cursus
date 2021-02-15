/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:05:47 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 11:45:46 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_img				*ft_image_new(t_cub3d *cub, int wid, int hei)
{
	t_img			*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return ((void *)0);
	ft_util_bzero(img, sizeof(t_img));
	if (!(img->img = mlx_new_image(cub->mlx, wid, hei)))
		return (0);
	img->dat = mlx_get_data_addr(img->img, &img->bpp, &img->siz, &img->end);
	img->wid = wid;
	img->hei = hei;
	return (img);
}

void				ft_image_color(t_cub3d *cub, t_lin *lin, int clr)
{
	int				y;
	int				ymax;

	y = (lin->py0 < lin->py1) ? lin->py0 : lin->py1;
	ymax = (lin->py0 < lin->py1) ? lin->py1 : lin->py0;
	if (y >= 0)
	{
		while (y < ymax)
		{
			ft_image_pixel_img(clr, lin->pox, y, cub->img);
			++y;
		}
	}
}

void				ft_image_pixel_img(int clr, int pox, int poy, t_img *img)
{
	unsigned char	*src;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	src = (unsigned char *)&clr;
	r = src[0];
	g = src[1];
	b = src[2];
	img->dat[poy * img->siz + pox * img->bpp / 8] = r;
	img->dat[poy * img->siz + pox * img->bpp / 8 + 1] = g;
	img->dat[poy * img->siz + pox * img->bpp / 8 + 2] = b;
}

void				ft_image_lin_txt_clr(t_cub3d *cub, t_ray *ray, t_lin *lin,
	t_img *txt)
{
	int				ymax;

	lin->poy = (lin->py0 < lin->py1) ? lin->py0 : lin->py1;
	ymax = (lin->py0 < lin->py1) ? lin->py1 : lin->py0;
	if (lin->poy >= 0)
	{
		while (lin->poy < ymax)
		{
			ft_image_texture_on_img(cub, ray, lin, txt);
			++lin->poy;
		}
	}
}

void				ft_image_texture_on_img(t_cub3d *cub, t_ray *ray,
	t_lin *lin, t_img *txt)
{
	int				d;

	d = lin->poy * txt->siz - (cub->hei * cub->pos->cam) *
		txt->siz / 2 + ray->hei * txt->siz / 2;
	lin->txy = ((d * txt->hei) / ray->hei) / txt->siz;
	cub->img->dat[lin->poy * cub->img->siz + lin->pox * cub->img->bpp / 8] =
		txt->dat[lin->txy * txt->siz + lin->txx * (txt->bpp / 8)];
	cub->img->dat[lin->poy * cub->img->siz + lin->pox * cub->img->bpp / 8 + 1] =
		txt->dat[lin->txy * txt->siz + lin->txx * (txt->bpp / 8) + 1];
	cub->img->dat[lin->poy * cub->img->siz + lin->pox * cub->img->bpp / 8 + 2] =
		txt->dat[lin->txy * txt->siz + lin->txx * (txt->bpp / 8) + 2];
}
