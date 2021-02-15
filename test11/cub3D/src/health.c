/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   health.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:12:10 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:12:11 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_health_change(t_cub3d *cub, int opt, int amt)
{
	int				now;

	now = (int)(clock() / CLOCKS_PER_SEC);
	if (opt == _MIN && now >= cub->pos->last_hurt + 2)
	{
		system("afplay -v 0.30 sound/oof.mp3 &>/dev/null &");
		cub->pos->last_hurt = now;
		if (cub->pos->hel - amt <= 0)
			ft_tool_exit(0, cub, 2, "GAME OVER!");
		else
			cub->pos->hel -= amt;
	}
	if (opt == _PLS && now >= cub->pos->last_eat + 2 && cub->pos->left_food > 0)
	{
		system("afplay -v 0.30 sound/eat.mp3 &>/dev/null &");
		cub->pos->last_eat = now;
		--cub->pos->left_food;
		cub->pos->hun += amt;
		if (cub->pos->hun >= 10)
			cub->pos->hun = 10;
	}
}

void				ft_health_draw(t_cub3d *cub)
{
	int				wid;
	int				hdx;

	wid = 10;
	hdx = 0;
	while (hdx < cub->pos->hel)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, cub->txt[4]->img,
			wid, cub->hei - 40);
		wid += 35;
		++hdx;
	}
	while (hdx < 10)
	{
		mlx_put_image_to_window(cub->mlx, cub->win, cub->txt[5]->img,
			wid, cub->hei - 40);
		wid += 35;
		++hdx;
	}
}
