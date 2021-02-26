/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deplacements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:55:52 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/26 18:09:38 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_deplacement_left_next(t_env *e)
{
	if (e->mvt.rot_left == 1)
	{
		e->mvt.old_dir_x = e->orientation.dir_x;
		e->orientation.dir_x = e->orientation.dir_x * cos(-e->mvt.vit_rot)
			- e->orientation.dir_y * sin(-e->mvt.vit_rot);
		e->orientation.dir_y = e->mvt.old_dir_x * sin(-e->mvt.vit_rot)
			+ e->orientation.dir_y * cos(-e->mvt.vit_rot);
		e->mvt.old_plan_x = e->map.plan_x;
		e->map.plan_x = e->map.plan_x * cos(-e->mvt.vit_rot) -
			e->map.plan_y * sin(-e->mvt.vit_rot);
		e->map.plan_y = e->mvt.old_plan_x * sin(-e->mvt.vit_rot) +
			e->map.plan_y * cos(-e->mvt.vit_rot);
	}
}

void		ft_deplacement_left(t_env *e)
{
	if (e->mvt.left == 1)
	{
		if ((e->map.tab_map[(int)(e->map.pos_n_y - e->map.plan_y * 0.03)]
				[(int)(e->map.pos_n_x)] != '1') &&
				(e->map.tab_map[(int)(e->map.pos_n_y - e->map.plan_y * 0.03)]
				[(int)(e->map.pos_n_x)] != '2'))
			e->map.pos_n_y -= e->map.plan_y * 0.03;
		if ((e->map.tab_map[(int)(e->map.pos_n_y)]
					[(int)(e->map.pos_n_x - e->map.plan_x * 0.03)] != '1')
					 && (e->map.tab_map[(int)(e->map.pos_n_y)]
					[(int)(e->map.pos_n_x - e->map.plan_x * 0.03)] != '2'))
			e->map.pos_n_x -= e->map.plan_x * 0.03;
	}
	ft_deplacement_left_next(e);
}

void		ft_deplacement_right_next(t_env *e)
{
	if (e->mvt.right == 1)
	{
		if ((e->map.tab_map[(int)(e->map.pos_n_y)][(int)(e->map.plan_x * 0.03 +
					e->map.pos_n_x)] != '1') &&
		((e->map.tab_map[(int)(e->map.pos_n_y)][(int)(e->map.plan_x * 0.03 +
					e->map.pos_n_x)] != '2')))
			e->map.pos_n_x += e->map.plan_x * 0.03;
		if ((e->map.tab_map[(int)(e->map.pos_n_y + e->map.plan_y * 0.03)]
				[(int)(e->map.pos_n_x)] != '1') &&
				((e->map.tab_map[(int)(e->map.pos_n_y + e->map.plan_y * 0.03)]
					[(int)(e->map.pos_n_x)] != '2')))
			e->map.pos_n_y += e->map.plan_y * 0.03;
	}
}

void		ft_deplacement_right(t_env *e)
{
	if (e->mvt.rot_right == 1)
	{
		e->mvt.old_dir_x = e->orientation.dir_x;
		e->orientation.dir_x = e->orientation.dir_x * cos(e->mvt.vit_rot) -
			e->orientation.dir_y * sin(e->mvt.vit_rot);
		e->orientation.dir_y = e->mvt.old_dir_x * sin(e->mvt.vit_rot) +
			e->orientation.dir_y * cos(e->mvt.vit_rot);
		e->mvt.old_plan_x = e->map.plan_x;
		e->map.plan_x = e->map.plan_x * cos(e->mvt.vit_rot) -
			e->map.plan_y * sin(e->mvt.vit_rot);
		e->map.plan_y = e->mvt.old_plan_x * sin(e->mvt.vit_rot) +
			e->map.plan_y * cos(e->mvt.vit_rot);
	}
	ft_deplacement_right_next(e);
}

void		ft_deplacement_down(t_env *e)
{
	if (e->mvt.down == 1)
	{
		if ((e->map.tab_map[(int)(e->map.pos_n_y - e->orientation.dir_y * 0.03)]
				[(int)(e->map.pos_n_x)] != '1')
		&& (e->map.tab_map[(int)(e->map.pos_n_y - e->orientation.dir_y * 0.03)]
				[(int)(e->map.pos_n_x)] != '2'))
			e->map.pos_n_y -= e->orientation.dir_y * 0.03;
		if ((e->map.tab_map[(int)(e->map.pos_n_y)]
				[(int)(e->map.pos_n_x - e->orientation.dir_x * 0.03)] != '1')
		&& (e->map.tab_map[(int)(e->map.pos_n_y)]
				[(int)(e->map.pos_n_x - e->orientation.dir_x * 0.03)] != '2'))
			e->map.pos_n_x -= e->orientation.dir_x * 0.03;
	}
}
