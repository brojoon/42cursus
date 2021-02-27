/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:56:30 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:56 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sprite_malloc(t_env *e)
{
	if (!(e->sprite = (t_sprite *)ft_calloc(e->map.nbr_sprite,
		sizeof(t_sprite))))
	{
		ft_exit("Error sprite malloc failed", -1);
	}
}

void	ft_sprite_distance(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->map.nbr_sprite)
	{
		e->sprite[i].sprite_order = i;
		e->sprite[e->sprite[i].sprite_order].sprite_distance =
			ft_power(e->map.pos_n_x - e->sprite[e->sprite[i].
					sprite_order].coord.x, 2) +
			ft_power(e->map.pos_n_y - e->sprite[e->sprite[i].
					sprite_order].coord.y, 2);
		i++;
	}
}

void	ft_swap_sprite(t_env *e)
{
	int	i;
	int tmp;

	i = 0;
	while (i + 1 < e->map.nbr_sprite)
	{
		if (e->sprite[e->sprite[i].sprite_order].sprite_distance <
				e->sprite[e->sprite[i + 1].sprite_order].sprite_distance)
		{
			tmp = e->sprite[i].sprite_order;
			e->sprite[i].sprite_order = e->sprite[i + 1].sprite_order;
			e->sprite[i + 1].sprite_order = tmp;
			ft_swap_sprite(e);
		}
		i++;
	}
}

void	ft_free_sprite(t_env *e)
{
	if (e->spt.dist_wall)
	{
		free(e->spt.dist_wall);
		e->spt.dist_wall = NULL;
	}
}

void	ft_check_wall_again(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	j = e->raycasting.x - 1;
	while (i < e->raycasting.y)
	{
		if (e->map.tab_map[i][j] != '1' && e->map.tab_map[i][j] != 'X')
		{
			ft_exit("Error wrong map", -1);
		}
		i++;
	}
}
