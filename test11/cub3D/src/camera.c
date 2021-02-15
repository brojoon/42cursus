/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:55:26 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:10:08 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_camera_set_start(t_cub3d *cub, double dix, double plx,
	double ply)
{
	cub->pos->dix = dix;
	cub->pos->plx = plx;
	cub->pos->ply = ply;
}

void				ft_camera_turn_left_right(t_cub3d *cub, int opt)
{
	double			old_dix;
	double			old_plx;
	double			rot_spd;

	old_dix = cub->pos->dix;
	old_plx = cub->pos->plx;
	rot_spd = (opt == 0) ? cub->pos->rot * -1 : cub->pos->rot;
	cub->pos->dix = cub->pos->dix * cos(rot_spd) - cub->pos->diy * sin(rot_spd);
	cub->pos->diy = old_dix * sin(rot_spd) + cub->pos->diy * cos(rot_spd);
	cub->pos->plx = cub->pos->plx * cos(rot_spd) - cub->pos->ply * sin(rot_spd);
	cub->pos->ply = old_plx * sin(rot_spd) + cub->pos->ply * cos(rot_spd);
}

void				ft_camera_turn_up_down(t_cub3d *cub, int opt)
{
	double			rot_spd;

	rot_spd = (opt == 0) ? cub->pos->rot : cub->pos->rot * -1;
	if (cub->pos->cam + rot_spd < 2)
		cub->pos->cam += rot_spd;
}
