/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orientation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:56:00 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/25 19:56:02 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_orientation(t_env *e, int i, int j)
{
	if (e->map.tab_map[i][j] == 'N' || e->map.tab_map[i][j] == 'S' ||
					e->map.tab_map[i][j] == 'E' || e->map.tab_map[i][j] == 'W')
	{
		if (e->identifier.perso == 1)
		{
			ft_exit("Error multi perso", -1);
		}
		e->orientation.orientation_perso = e->map.tab_map[i][j];
		return (1);
	}
	else
		return (0);
}

void	ft_orientation_perso(t_env *e)
{
	if (e->orientation.orientation_perso == 'N')
	{
		e->orientation.dir_x = 0;
		e->orientation.dir_y = -1;
	}
	if (e->orientation.orientation_perso == 'S')
	{
		e->orientation.dir_x = 0;	
		e->orientation.dir_y = 1;
	}
	if (e->orientation.orientation_perso == 'W')
	{
		e->orientation.dir_x = -1;
		e->orientation.dir_y = 0;
	}
	if (e->orientation.orientation_perso == 'E')
	{
		e->orientation.dir_x = 1;
		e->orientation.dir_y = 0;
	}
	e->map.plan_x = -0.66 * e->orientation.dir_y;
	e->map.plan_y = 0.66 * e->orientation.dir_x;
}

void	ft_initialize_color_wall(t_env *e)
{
	e->colors.color_north = 1644825;
	e->colors.color_south = 16718107;
	e->colors.color_east = 1654015;
	e->colors.color_west = 16727070;
}

void	ft_color_wall(t_env *e)
{
	ft_initialize_color_wall(e);
	if (e->raycasting.side == 0 && e->map.ray_dir_x > 0)
		e->colors.wall = e->colors.color_north;
	else if (e->raycasting.side == 0 && e->map.ray_dir_x < 0)
		e->colors.wall = e->colors.color_south;
	else if (e->raycasting.side == 1 && e->map.ray_dir_y > 0)
		e->colors.wall = e->colors.color_east;
	else
		e->colors.wall = e->colors.color_west;
}
