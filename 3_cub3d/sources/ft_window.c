/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_window.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:07:53 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:59 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_init_image(t_env *e)
{
	if (!(e->mlx.new_image = mlx_new_image(e->mlx.ptr,
				e->window.x, e->window.y)))
	{
		ft_exit("Error mlx_new_image", -1);
	}
	if (!(e->mlx.get_data = (int *)mlx_get_data_addr(e->mlx.new_image,
			&e->mlx.bits_per_pixel, &e->mlx.size_line, &e->mlx.endian)))
	{
		ft_exit("Error mlx_get_data_addr", -1);
	}
	if (!(e->spt.dist_wall = ft_calloc(sizeof(double), e->window.x)))
	{
		ft_exit("Error malloc e->spt.dist_wall", -1);
	}
	ft_raycasting(e);
	ft_sprite(e);
	mlx_put_image_to_window(e->mlx.ptr, e->mlx.win_ptr,
			e->mlx.new_image, 0, 0);
	mlx_do_sync(e->mlx.ptr);
	mlx_destroy_image(e->mlx.ptr, e->mlx.new_image);
}

int			ft_deplacement(t_env *e)
{
	e->mvt.vit_rot = 0.020;
	ft_mv_up(e);
	ft_mv_down(e);
	ft_mv_left(e);
	ft_mv_right(e);
	ft_init_image(e);
	return (0);
}

void		ft_init_window(t_env *e)
{
	if (!(e->mlx.ptr = mlx_init()))
	{
		ft_exit("Error mlx_init", -1);
	}
	ft_check_resolution_next(e);
	if (!(e->mlx.win_ptr = mlx_new_window(e->mlx.ptr, e->window.x,
			e->window.y, "cub3D")))
	{
		ft_exit("Error mlx_new_window", -1);
	}
	ft_sprite_malloc(e);
	ft_textures(e);
	ft_coord_sprite(e);
	ft_check_wall(e);
	ft_check_space(e);
	mlx_do_key_autorepeatoff(e->mlx.ptr);
	mlx_hook(e->mlx.win_ptr, 2, 1, &ft_key_down, e);
	mlx_hook(e->mlx.win_ptr, 3, 2, &ft_key_up, e);
	mlx_hook(e->mlx.win_ptr, 33, 0, ft_exit, "ESC");
	mlx_loop_hook(e->mlx.ptr, &ft_deplacement, e);
	mlx_loop(e->mlx.ptr);
}
