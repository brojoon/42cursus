/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_orientation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:56:00 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/26 18:06:00 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
