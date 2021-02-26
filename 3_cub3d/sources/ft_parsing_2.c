/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 18:12:22 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/25 19:56:12 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_parsing_line_s(t_env *e, char *line, int i)
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

void    ft_parsing_line_f(t_env *e, char *line, int i)
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
    ft_parsing_line_again(e, line, i);
}

void    ft_parsing_line_no(t_env *e, char *line, int i)
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

void    ft_parsing_line_so(t_env *e, char *line, int i)
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

void    ft_parsing_line_we(t_env *e, char *line, int i)
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
    ft_parsing_line_next(e, line, i);
}