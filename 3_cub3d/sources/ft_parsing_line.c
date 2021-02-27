/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:35:56 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:51 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_orientation_perso(t_env *e)
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

void		ft_check_space(t_env *e)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < e->raycasting.y)
	{
		while (j < e->raycasting.x)
		{
			if (e->map.tab_map[i][j] == 'X' &&
			((j != 0 && e->map.tab_map[i][j - 1] == '0') ||
			((j < e->raycasting.x - 1) && e->map.tab_map[i][j + 1] == '0') ||
			((i < e->raycasting.y - 1) && e->map.tab_map[i + 1][j] == '0') ||
			(i != 0 && e->map.tab_map[i - 1][j] == '0')))
			{
				ft_exit("Error map edges", -1);
			}
			j++;
		}
		i++;
		j = 0;
	}
}

void		ft_parsing_check(t_env *e)
{
	if (ft_check_identifier(e) == 0)
	{
		ft_exit("Error parsing_check func", -1);
	}
	ft_recup_map_2(e);
	ft_pos_perso(e);
	ft_orientation_perso(e);
}

void		ft_read_map(char *argv, t_env *e)
{
	int		ret;
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open(argv, O_RDONLY)) == -1)
		ft_exit("Error map open", -1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		ft_parsing_line_r(e, line);
		free(line);
	}
	if (ret == -1)
		ft_exit("get_next_line Error", -1);
	ft_parsing_line_r(e, line);
	free(line);
	close(fd);
	ft_parsing_check(e);
}
