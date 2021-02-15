/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hungry.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:28:35 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 18:29:44 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_hungry_draw(t_cub3d *cub)
{
	int				wid;
	int				hdx;

	wid = cub->wid - 40;
	hdx = 0;
	while (hdx < cub->pos->hun)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, cub->txt[6]->img,
			wid, cub->hei - 40);
		wid -= 35;
		++hdx;
	}
	while (hdx < 10)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, cub->txt[7]->img,
			wid, cub->hei - 40);
		wid -= 35;
		++hdx;
	}
}
