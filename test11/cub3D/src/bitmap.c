/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:22:19 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 11:00:02 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_bitmap_save(t_img *img, char *nam)
{
	int				fil;
	int				siz;
	int				pix;

	nam = ft_util_strjoin(nam, ".bmp");
	fil = open(nam, O_CREAT | O_RDWR);
	siz = 14 + 40 + 4 + (img->wid * img->hei) * 4;
	pix = 14 + 40 + 4;
	write(fil, "BM", 2);
	write(fil, &siz, 4);
	write(fil, "\0\0\0\0", 4);
	write(fil, &pix, 4);
	ft_bitmap_info_header(img, fil);
	ft_bitmap_verti(img);
	ft_bitmap_data(img, fil);
	close(fil);
	free(nam);
	return (1);
}

int					ft_bitmap_info_header(t_img *img, int fil)
{
	int				siz;
	int				num;
	int				cnt;

	siz = 40;
	num = 1;
	write(fil, &siz, 4);
	write(fil, &img->wid, 4);
	write(fil, &img->hei, 4);
	write(fil, &num, 2);
	write(fil, &img->bpp, 2);
	cnt = 0;
	while (cnt < 28)
	{
		write(fil, "\0", 1);
		++cnt;
	}
	return (1);
}

int					ft_bitmap_verti(t_img *img)
{
	int				lin;
	int				idx;
	int				jdx;

	lin = 0;
	while (lin < img->hei)
	{
		idx = 0;
		jdx = img->siz;
		while (idx < jdx && idx != jdx)
		{
			ft_bitmap_verti_sub(img, lin, &idx, jdx);
			jdx -= 4;
		}
		++lin;
	}
	return (1);
}

void				ft_bitmap_verti_sub(t_img *img, int lin, int *idx, int jdx)
{
	char			sav;
	int				kdx;

	kdx = 3;
	while (kdx >= 0)
	{
		sav = img->dat[*idx + (lin * img->siz)];
		img->dat[*idx + (lin * img->siz)] =
			img->dat[jdx - kdx + (lin * img->siz - 1)];
		img->dat[jdx - kdx + (lin * img->siz - 1)] = sav;
		--kdx;
		*idx = *idx + 1;
	}
}

int					ft_bitmap_data(t_img *img, int fil)
{
	int				idx;

	idx = img->wid * img->hei - 1;
	while (idx >= 0)
	{
		write(fil, &img->dat[idx * img->bpp / 8], 4);
		--idx;
	}
	return (1);
}
