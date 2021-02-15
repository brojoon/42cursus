/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:55:28 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 18:29:25 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_player_set_start(t_cub3d *cub, char dir, int cur, int u)
{
	if (dir == 'E')
	{
		cub->pos->diy = 0.0;
		ft_camera_set_start(cub, 1.0, 0.0, 0.66);
	}
	else if (dir == 'W')
	{
		cub->pos->diy = 0.0;
		ft_camera_set_start(cub, -1.0, 0.0, -0.66);
	}
	else if (dir == 'N')
	{
		cub->pos->diy = -1.0;
		ft_camera_set_start(cub, 0.0, 0.66, 0.0);
	}
	else if (dir == 'S')
	{
		cub->pos->diy = 1.0;
		ft_camera_set_start(cub, 0.0, -0.66, 0.0);
	}
	cub->pos->pox = (double)(cur - 1) + 0.5;
	cub->pos->poy = (double)u + 0.5;
}

void				ft_player_move_front_back(t_cub3d *cub, int opt)
{
	double			mvx;
	double			mvy;

	mvx = (opt == 0) ? cub->pos->dix * cub->pos->spd :
		-1 * cub->pos->dix * cub->pos->spd;
	mvy = (opt == 0) ? cub->pos->diy * cub->pos->spd :
		-1 * cub->pos->diy * cub->pos->spd;
	if (cub->map->map[(int)cub->pos->poy][(int)(cub->pos->pox + mvx)] == '0' ||
		cub->map->map[(int)cub->pos->poy][(int)(cub->pos->pox + mvx)] == '3')
	{
		ft_player_move_sound(cub, clock() / CLOCKS_PER_SEC);
		cub->pos->pox += mvx;
	}
	if (cub->map->map[(int)(cub->pos->poy + mvy)][(int)cub->pos->pox] == '0' ||
		cub->map->map[(int)(cub->pos->poy + mvy)][(int)cub->pos->pox] == '3')
	{
		ft_player_move_sound(cub, clock() / CLOCKS_PER_SEC);
		cub->pos->poy += mvy;
	}
	if (cub->map->map[(int)cub->pos->poy][(int)(cub->pos->pox + mvx)] == '2' ||
		cub->map->map[(int)(cub->pos->poy + mvy)][(int)cub->pos->pox] == '2')
		ft_health_change(cub, _MIN, 1);
}

void				ft_player_move_left_right(t_cub3d *cub, int opt)
{
	double			mvx;
	double			mvy;

	mvx = (opt == 0) ? cub->pos->plx * cub->pos->spd * -1 :
		cub->pos->plx * cub->pos->spd;
	mvy = (opt == 0) ? cub->pos->ply * cub->pos->spd * -1 :
		cub->pos->ply * cub->pos->spd;
	if (cub->map->map[(int)cub->pos->poy][(int)(cub->pos->pox + mvx)] == '0' ||
		cub->map->map[(int)cub->pos->poy][(int)(cub->pos->pox + mvx)] == '3')
	{
		ft_player_move_sound(cub, clock() / CLOCKS_PER_SEC);
		cub->pos->pox += mvx;
	}
	if (cub->map->map[(int)(cub->pos->poy + mvy)][(int)cub->pos->pox] == '0' ||
		cub->map->map[(int)(cub->pos->poy + mvy)][(int)cub->pos->pox] == '3')
	{
		ft_player_move_sound(cub, clock() / CLOCKS_PER_SEC);
		cub->pos->poy += mvy;
	}
	if (cub->map->map[(int)cub->pos->poy][(int)(cub->pos->pox + mvx)] == '2' ||
		cub->map->map[(int)(cub->pos->poy + mvy)][(int)cub->pos->pox] == '2')
		ft_health_change(cub, _MIN, 1);
}

void				ft_player_move_sound(t_cub3d *cub, int now)
{
	if (now >= cub->pos->last_walk_sound + 1)
	{
		cub->pos->last_walk_sound = now;
		system("afplay -v 0.30 sound/walk.mp3 &>/dev/null &");
	}
}
