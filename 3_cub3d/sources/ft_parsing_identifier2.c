/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_identifier2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:12:22 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:49 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		ft_parsing_line_s(t_env *e, char *line, int i)
{
	if (line[i] == 'S' && line[i + 1] == ' ' && e->identifier.m == 0)
	{
		if (e->identifier.s == 0)
		{
			e->root_textures.sprite = ft_recup_root(line, i);
			e->identifier.s = 1;
		}
		else
			ft_exit("Error S textures", -1);
	}
	ft_parsing_line_f(e, line, i);
}

void		ft_parsing_line_f(t_env *e, char *line, int i)
{
	if (line[i] == 'F' && line[i + 1] == ' ' && e->identifier.m == 0)
	{
		if (e->identifier.f == 0)
		{
			e->colors.color_sol = ft_recup_color(line, i);
			e->identifier.f = 1;
		}
		else
			ft_exit("Error two colors F", -1);
	}
	ft_parsing_line_c(e, line, i);
}

void		ft_parsing_line_c(t_env *e, char *line, int i)
{
	if (line[i] == 'C' && e->identifier.m == 0 && line[i + 1] == ' ')
	{
		if (e->identifier.c == 0)
		{
			e->colors.color_plafond = ft_recup_color(line, i);
			e->identifier.c = 1;
		}
		else
			ft_exit("Error two colors C", -1);
	}
	ft_parsing_line_m(e, line, i);
}

void		ft_parsing_line_m(t_env *e, char *line, int i)
{
	if (line[i] == '1')
	{
		ft_recup_map(line, e);
		e->identifier.m = 1;
	}
	else if (line && (line[i] != '1' || line[i] != '\0')
			&& e->identifier.m == 1)
	{
		ft_exit("Error map ", -1);
	}
}
