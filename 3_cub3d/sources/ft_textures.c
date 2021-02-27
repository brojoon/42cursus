/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:56:48 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:58 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_textures		ft_info_texture(char *root_texture, t_env *e)
{
	t_textures	texture;

	ft_memset(&texture, 0, sizeof(t_textures));
	if (!(texture.win_ptr = mlx_xpm_file_to_image(e->mlx.ptr,
			root_texture, &texture.w, &texture.h)))
	{
		ft_exit("Error wrong texture info", -1);
	}
	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.win_ptr,
			&texture.bits_per_pixel, &texture.size_line, &texture.endian)))
	{
		ft_exit("Error wrong texture info2", -1);
	}
	return (texture);
}

t_mlx			ft_info_sprite(char *root_texture, t_env *e)
{
	t_mlx	texture;

	if (!(texture.win_ptr = mlx_xpm_file_to_image(e->mlx.ptr, root_texture,
			&texture.w, &texture.h)))
	{
		ft_exit("Error wrong sprite", -1);
	}
	if (!(texture.get_data = (int *)mlx_get_data_addr(texture.win_ptr,
			&texture.bits_per_pixel, &texture.size_line, &texture.endian)))
	{
		ft_exit("Error wrong sprite", -1);
	}
	return (texture);
}

void			ft_textures(t_env *e)
{
	int			i;
	char		*tmp;

	i = -1;
	e->texture_north = ft_info_texture(e->root_textures.north, e);
	e->texture_south = ft_info_texture(e->root_textures.south, e);
	e->texture_east = ft_info_texture(e->root_textures.east, e);
	e->texture_west = ft_info_texture(e->root_textures.west, e);
	while (++i < e->map.nbr_sprite)
	{
		tmp = e->root_textures.sprite;
		e->sprite[i].image = ft_info_sprite(tmp, e);
	}
}

t_textures		ft_texture_wall(t_env *e)
{
	if (e->raycasting.side == 0 && e->map.ray_dir_x > 0)
	{
		return (e->texture_east);
	}
	else if (e->raycasting.side == 0 && e->map.ray_dir_x < 0)
		return (e->texture_west);
	else if (e->raycasting.side == 1 && e->map.ray_dir_y > 0)
		return (e->texture_south);
	else
		return (e->texture_north);
}

void			ft_put_textures(t_env *e, int x)
{
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			y;
	t_textures	texture_wall;

	texture_wall = ft_texture_wall(e);
	if (e->raycasting.side == 0)
		wall_x = e->map.pos_n_y +
			e->raycasting.perp_wall_dist * e->map.ray_dir_y;
	else
		wall_x = e->map.pos_n_x +
			e->raycasting.perp_wall_dist * e->map.ray_dir_x;
	wall_x -= floor(wall_x);
	tex_x = wall_x * (double)texture_wall.w;
	y = e->map.draw_start;
	while (y++ < e->map.draw_end)
	{
		tex_y = (y - e->window.y / 2 + e->map.texture_line / 2) *
			texture_wall.h / e->map.texture_line;
		if (tex_y < 0)
			return ;
		e->mlx.get_data[x + y * (e->mlx.size_line / 4)] =
			texture_wall.get_data[tex_x + tex_y * texture_wall.w];
	}
}
