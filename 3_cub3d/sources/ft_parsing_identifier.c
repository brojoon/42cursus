/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_identifier.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:35:57 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:47 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		ft_parsing_line_ea(t_env *e, char *line, int i)
{
	if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' '
	&& e->identifier.m == 0)
	{
		if (e->identifier.ea == 0)
		{
			e->root_textures.east = ft_recup_root(line, i);
			e->identifier.ea = 1;
		}
		else
			ft_exit("Error EA textures", -1);
	}
	ft_parsing_line_s(e, line, i);
}

void		ft_parsing_line_we(t_env *e, char *line, int i)
{
	if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' '
	&& e->identifier.m == 0)
	{
		if (e->identifier.we == 0)
		{
			e->root_textures.west = ft_recup_root(line, i);
			e->identifier.we = 1;
		}
		else
			ft_exit("Error WE textures", -1);
	}
	ft_parsing_line_ea(e, line, i);
}

void		ft_parsing_line_so(t_env *e, char *line, int i)
{
	if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' '
	&& e->identifier.m == 0)
	{
		if (e->identifier.so == 0)
		{
			e->root_textures.south = ft_recup_root(line, i);
			e->identifier.so = 1;
		}
		else
			ft_exit("Error SO textures", -1);
	}
	ft_parsing_line_we(e, line, i);
}

void		ft_parsing_line_no(t_env *e, char *line, int i)
{
	if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' '
	&& e->identifier.m == 0)
	{
		if (e->identifier.no == 0)
		{
			e->root_textures.north = ft_recup_root(line, i);
			e->identifier.no = 1;
		}
		else
			ft_exit("Error NO textures", -1);
	}
	ft_parsing_line_so(e, line, i);
}

void		ft_parsing_line_r(t_env *e, char *line)
{
	int			i;

	i = 0;
	ft_space(line, &i);
	ft_parsing_line_check(line);
	if (line[i] == 'R' && line[i + 1] == ' ' && e->identifier.m == 0)
	{
		if (e->identifier.r == 0)
		{
			ft_recup_axes(e, line);
			e->identifier.r = 1;
		}
		else
			ft_exit("Error R", -1);
	}
	ft_parsing_line_no(e, line, i);
}
