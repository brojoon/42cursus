/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 00:29:45 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:38 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_header(unsigned char *header, int param)
{
	header[0] = (unsigned char)(param);
	header[1] = (unsigned char)(param >> 8);
	header[2] = (unsigned char)(param >> 16);
	header[3] = (unsigned char)(param >> 24);
}

void	ft_image_bmp(t_env *e, t_bmp *bmp)
{
	int i;
	int j;
	int x;
	int y;

	j = -1;
	while (++j < e->window.y)
	{
		i = -1;
		while (++i < e->window.x)
		{
			x = i;
			y = e->window.y - 1 - j;
			bmp->color = e->mlx.get_data[x + y * e->window.x];
			write(bmp->fd, &bmp->color, 3);
		}
		i = -1;
		while (++i < (4 - (e->window.x * 3) % 4) % 4)
			write(bmp->fd, &bmp->pad, 1);
	}
}

void	ft_complete_header(t_env *e, t_bmp *bmp)
{
	int	i;

	i = 0;
	while (i < 14)
		bmp->header[i++] = 0;
	bmp->header[0] = 'B';
	bmp->header[1] = 'M';
	bmp->header[10] = 54;
	i = 0;
	while (i < 40)
		bmp->info[i++] = 0;
	bmp->info[0] = 40;
	bmp->info[12] = 1;
	bmp->info[14] = 24;
	i = 0;
	while (i < 3)
		bmp->pad[i++] = 0;
	set_header(&bmp->header[2], bmp->size);
	set_header(&bmp->info[4], e->window.x);
	set_header(&bmp->info[8], e->window.y);
	write(bmp->fd, bmp->header, 14);
	write(bmp->fd, bmp->info, 40);
}

void	ft_bmp(t_env *e)
{
	t_bmp	bmp;

	if ((bmp.fd = open("image.bmp", O_CREAT | O_WRONLY, S_IRWXU)) == -1)
	{
		exit(0);
	}
	ft_complete_header(e, &bmp);
	ft_image_bmp(e, &bmp);
	free(bmp.image);
	close(bmp.fd);
}

void	ft_push_bmp(t_env *e)
{
	e->mlx.ptr = mlx_init();
	if (!(e->sprite = (t_sprite *)ft_calloc(sizeof(t_sprite),
			e->map.nbr_sprite)))
	{
		ft_exit("Error push_bmp func malloc sprite", -1);
	}
	ft_textures(e);
	ft_coord_sprite(e);
	e->mlx.new_image = mlx_new_image(e->mlx.ptr, e->window.x, e->window.y);
	e->mlx.get_data = (int *)mlx_get_data_addr(e->mlx.new_image,
			&e->mlx.bits_per_pixel, &e->mlx.size_line, &e->mlx.endian);
	if (!(e->spt.dist_wall = ft_calloc(sizeof(double), e->window.x)))
	{
		ft_exit("Error malloc e->spt.dist_wall", -1);
	}
	ft_raycasting(e);
	ft_sprite(e);
	ft_bmp(e);
	ft_exit("Created BMP", 0);
}
