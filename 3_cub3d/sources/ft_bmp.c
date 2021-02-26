/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 00:29:45 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/26 09:58:58 by hyungjki         ###   ########.fr       */
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
	while (++j < e->axes.axe_y)
	{
		i = -1;
		while (++i < e->axes.axe_x)
		{
			x = i;
			y = e->axes.axe_y - 1 - j;
			bmp->color = e->mlx.get_data[x + y * e->axes.axe_x];
			write(bmp->fd, &bmp->color, 3);
		}
		i = -1;
		while (++i < (4 - (e->axes.axe_x * 3) % 4) % 4)
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
	set_header(&bmp->info[4], e->axes.axe_x);
	set_header(&bmp->info[8], e->axes.axe_y);
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

void	ft_check_space(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < e->raycasting.y)
	{
		while (j < e->raycasting.x)
		{
			if (e->map.tab_map[i][j] == 'X' &&
			((j != 0 && e->map.tab_map[i][j - 1] == '0') ||
			((j < e->raycasting.x - 1) && e->map.tab_map[i][j + 1] == '0') ||
			((i < e->raycasting.y - 1) && e->map.tab_map[i + 1][j] == '0') ||
			(i != 0 && e->map.tab_map[i - 1][j] == '0')))
			{
				ft_exit("Error map edges dd", -1);
			}
			j++;
		}
		i++;
		j = 0;
	}
}
