/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:45:25 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:39 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_wall_next(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = e->raycasting.y - 1;
	while (i < e->raycasting.x)
	{
		if (e->map.tab_map[j][i] != '1' && e->map.tab_map[j][i] != 'X')
		{
			ft_exit("Error map edges check_wall_next", -1);
		}
		i++;
	}
	ft_check_wall_again(e);
}

void	ft_check_wall(t_env *e)
{
	int		i;

	i = 0;
	while (i < e->raycasting.x)
	{
		if (e->map.tab_map[0][i] != '1' && e->map.tab_map[0][i] != 'X')
		{
			ft_exit("Error map edges check_wall", -1);
		}
		i++;
	}
	i = 0;
	while (i < e->raycasting.y)
	{
		if (e->map.tab_map[i][0] != '1' && e->map.tab_map[i][0] != 'X')
		{
			ft_exit("Error map edges check_wall", -1);
		}
		i++;
	}
	ft_check_wall_next(e);
}

void	ft_check_resolution_next(t_env *e)
{
	int		sizex;
	int		sizey;

	sizex = 0;
	sizey = 0;
	if (!(mlx_get_screen_size(e->mlx.ptr, &sizex, &sizey)))
	{
		ft_exit("Error mlx_get_screen", -1);
	}
	if (e->window.x > sizex)
		e->window.x = sizex;
	if (e->window.y > sizey)
		e->window.y = sizey;
	if (e->window.x <= 0 || e->window.y <= 0)
	{
		ft_exit("Error resolution <= 0", -1);
	}
}

int		ft_rgb_color(char *line, int *i)
{
	int		ret;

	if (ft_atoi(&line[*i]) < 0 || ft_atoi(&line[*i]) > 255)
		ft_exit("Error rgb", -1);
	ret = ft_atoi(&line[*i]);
	while (ft_isdigit(line[*i]))
		(*i)++;
	if (line[*i] != ',')
		exit(0);
	(*i)++;
	ft_space(line, i);
	return (ret);
}
