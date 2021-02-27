/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:52:54 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 20:01:53 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_raycasting(t_env *e, int x)
{
	e->map.camera_x = 2 * x / (double)(e->window.x) - 1;
	e->map.ray_dir_x = e->orientation.dir_x + e->map.plan_x * e->map.camera_x;
	e->map.ray_dir_y = e->orientation.dir_y + e->map.plan_y * e->map.camera_x;
	e->raycasting.delta_x = fabs(1.0 / e->map.ray_dir_x);
	e->raycasting.delta_y = fabs(1.0 / e->map.ray_dir_y);
	e->raycasting.map_x = (int)e->map.pos_n_x;
	e->raycasting.map_y = (int)e->map.pos_n_y;
}

void	ft_raycasting_first(t_env *e)
{
	if (e->map.ray_dir_x < 0)
	{
		e->raycasting.step_x = -1;
		e->raycasting.side_dist_x = (e->map.pos_n_x - e->raycasting.map_x)
			* e->raycasting.delta_x;
	}
	else
	{
		e->raycasting.step_x = 1;
		e->raycasting.side_dist_x = (e->raycasting.map_x + 1.0 - e->map.pos_n_x)
			* e->raycasting.delta_x;
	}
	if (e->map.ray_dir_y < 0)
	{
		e->raycasting.step_y = -1;
		e->raycasting.side_dist_y = (e->map.pos_n_y - e->raycasting.map_y)
			* e->raycasting.delta_y;
	}
	else
	{
		e->raycasting.step_y = 1;
		e->raycasting.side_dist_y = (e->raycasting.map_y + 1.0 - e->map.pos_n_y)
			* e->raycasting.delta_y;
	}
}

void	ft_until_wall(t_env *e)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (e->raycasting.side_dist_x < e->raycasting.side_dist_y)
		{
			e->raycasting.side_dist_x += e->raycasting.delta_x;
			e->raycasting.map_x += e->raycasting.step_x;
			e->raycasting.side = 0;
		}
		else
		{
			e->raycasting.side_dist_y += e->raycasting.delta_y;
			e->raycasting.map_y += e->raycasting.step_y;
			e->raycasting.side = 1;
		}
		if (e->map.tab_map[e->raycasting.map_y][e->raycasting.map_x] == '1')
			hit = 1;
	}
}

void	ft_draw_texture(t_env *e, int x, int y)
{
	e->map.texture_line = (e->window.y / e->raycasting.perp_wall_dist);
	e->map.draw_start = -e->map.texture_line / 2 + e->window.y / 2;
	e->map.draw_end = e->map.texture_line / 2 + e->window.y / 2;
	if (e->map.draw_start < 0)
		e->map.draw_start = 0;
	if (e->map.draw_end >= e->window.y)
		e->map.draw_end = e->window.y - 1;
	ft_put_textures(e, x);
	y = 0;
	if (e->map.draw_end < 0)
		e->map.draw_end = e->window.y;
	y = e->map.draw_end;
	while (y < e->window.y)
	{
		e->mlx.get_data[x + y * (e->mlx.size_line / 4)] = e->colors.color_sol;
		e->mlx.get_data[x + (e->window.y - y - 1) * (e->mlx.size_line / 4)] =
			e->colors.color_plafond;
		y++;
	}
}

void	ft_raycasting(t_env *e)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < e->window.x)
	{
		ft_init_raycasting(e, x);
		ft_raycasting_first(e);
		ft_until_wall(e);
		if (e->raycasting.side == 0)
			e->raycasting.perp_wall_dist = (e->raycasting.map_x - e->map.pos_n_x
					+ (1 - e->raycasting.step_x) / 2) / e->map.ray_dir_x;
		else
			e->raycasting.perp_wall_dist = (e->raycasting.map_y - e->map.pos_n_y
					+ (1 - e->raycasting.step_y) / 2) / e->map.ray_dir_y;
		ft_draw_texture(e, x, y);
		e->spt.dist_wall[x] = e->raycasting.perp_wall_dist;
		x++;
	}
}
