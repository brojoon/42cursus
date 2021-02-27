/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_perso.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:30:22 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 21:34:54 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char			**ft_map_size(t_env *e)
{
	int			i;
	int			cnt;
	char		**tmp;

	i = -1;
	cnt = 0;
	e->raycasting.x = 0;
	while (e->map.buff[++i])
	{
		if (e->map.buff[i] == '\n')
		{
			if (e->raycasting.x < cnt)
				e->raycasting.x = cnt;
			cnt = 0;
		}
		cnt++;
	}
	if (!(tmp = (char **)malloc(sizeof(char *) * e->raycasting.y)))
		ft_exit("Error delete space func malloc fail", -1);
	i = -1;
	while (++i < e->raycasting.y)
		if (!(*(tmp + i) = (char *)malloc(e->raycasting.x)))
			ft_exit("Error delete space func malloc fail", -1);
	return (tmp);
}

void			ft_recup_map_2(t_env *e)
{
	int			i;
	char		**tmp;

	i = -1;
	tmp = ft_map_size(e);
	e->map.tab_map = ft_split(e->map.buff, '\n');
	ft_map_fill(e, tmp);
	i = 0;
	while (e->map.tab_map[i])
	{
		free(e->map.tab_map[i]);
		i++;
	}
	free(e->map.tab_map);
	e->map.tab_map = tmp;
	tmp = NULL;
}

void			ft_pos_perso_next(t_env *e, int i, int j)
{
	if (e->map.tab_map[i][j] != '1' && e->map.tab_map[i][j] != '0' &&
				e->map.tab_map[i][j] != '2' && e->map.tab_map[i][j] != 'X' &&
				(ft_check_perso(e, i, j) == 0))
	{
		ft_exit("Error wrong map pos_perso_next", -1);
	}
	if (e->map.tab_map[i][j] == '2')
		e->map.nbr_sprite += 1;
	if ((ft_check_perso(e, i, j) == 1))
	{
		e->map.pos_n_x = j + 0.5;
		e->map.pos_n_y = i + 0.5;
		e->identifier.perso = 1;
	}
}

void			ft_pos_perso(t_env *e)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < e->raycasting.y)
	{
		while (j < e->raycasting.x)
		{
			ft_pos_perso_next(e, i, j);
			j++;
		}
		i++;
		j = 0;
	}
	if (e->identifier.perso == 0)
	{
		ft_exit("Error miss perso", -1);
	}
	if (e->map.pos_n_x > e->raycasting.y && e->map.pos_n_x > e->raycasting.x)
	{
		ft_exit("Error perso out of range", -1);
	}
}

int				ft_check_perso(t_env *e, int i, int j)
{
	if (e->map.tab_map[i][j] == 'N' || e->map.tab_map[i][j] == 'S' ||
					e->map.tab_map[i][j] == 'E' || e->map.tab_map[i][j] == 'W')
	{	
		if (e->map.tab_map[i + 1][j] == 'X' || e->map.tab_map[i - 1][j] == 'X' ||
			e->map.tab_map[i][j + 1] == 'X' || e->map.tab_map[i][j - 1] == 'X')
		{
			ft_exit("Error perso no wall", -1);
		}
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
