/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:35:56 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/25 22:27:55 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_parsing_line_again_next(t_env *e, char *line, int i)
{
    if (line[i] == '1')
    {
        ft_recup_map(line, e);
        e->identifier.m = 1;
    }
    else if (line && (line[i] != '1' || line[i] != '\0')
            && e->identifier.m == 1)
    {
        ft_exit("Error map", -1);
    }
}

void    ft_parsing_line_again(t_env *e, char *line, int i)
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
    ft_parsing_line_again_next(e, line, i);
}

void    ft_parsing_line_next(t_env *e, char *line, int i)
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

void    ft_parsing_line(t_env *e, char *line)
{
    int i;

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

void     ft_read_map(char *argv, t_env *e)
{   
    int     ret;
    int     fd;
    char    *line;

    line = NULL;
    if ((fd = open(argv, O_RDONLY)) == -1)
        ft_exit("Error map open", -1);
    while ((ret = get_next_line(fd, &line)) == 1)
    {
        ft_parsing_line(e, line);
        free(line);
    }
    if (ret == -1)
        ft_exit("get_next_line Error", -1);
    ft_parsing_line(e, line);
    free(line);
    close(fd);
    ft_parsing_check(e);
}