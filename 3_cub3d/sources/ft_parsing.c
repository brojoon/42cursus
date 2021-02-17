/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 16:35:56 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/17 20:58:28 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_parsing_line_again_next(t_env *e, char *line, int i)
{
    if (line[i] == '1' || line[i] == '0')
    {
          printf("hawawang");
        ft_recup_map(line, e);
        e->identifiants.m = 1;
    }
    else if (line && (line[i] != '1' || line[i] != '0' || line[i] != '\0')
            && e->identifiants.m == 1)
    {
        ft_putstr_fd("Error\nmap incorrect", 1);
        ft_exit(e);
    }
}

void    ft_parsing_line_again(t_env *e, char *line, int i)
{
    if (line[i] == 'C' && e->identifiants.m == 0 && line[i + 1] == ' ')
    {
        if (e->identifiants.c == 0)
        {
            e->colors.color_plafond = ft_recup_color(line, e, i);
            e->identifiants.c = 1;
        }
        else
        {
            ft_putstr_fd("Error\nTwo colors C, only one", 1);
            ft_exit(e);
        }
    }
    ft_parsing_line_again_next(e, line, i);
}

void    ft_parsing_line_next(t_env *e, char *line, int i)
{
    if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' '
    && e->identifiants.m == 0)
    {
        if (e->identifiants.ea == 0)
        {
            e->root_textures.east = ft_recup_root(line, e, i);
            e->identifiants.ea = 1;
        }
        else
        {
            ft_putstr_fd("Error\nTwo EA textures, only one", 1);
            ft_exit(e);
        }
    }
    ft_parsing_line_s(e, line, i);
}

void    ft_parsing_line(t_env *e, char *line)
{
    int i;

    i = 0;
    ft_space(line, &i);
    ft_parsing_line_check(e, line);
    if (line[i] == 'R' && line[i + 1] == ' ' && e->identifiants.m == 0)
    {
        if (e->identifiants.r == 0)
        {
            ft_recup_axes(e, line);
            e->identifiants.r = 1;
        }
        else
        {
            ft_putstr_fd("Error\nTwo R, Only one", 1);
            ft_exit(e);
        }
    }
    ft_parsing_line_no(e, line, i);
}

int     ft_read_map(char **argv, t_env *e)
{   
    int     ret;
    int     fd;
    char    *line;

    line = NULL;
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        ft_putstr_fd("Error\nfunction read", 1);
        ft_exit(e);
    }
    while ((ret = get_next_line(fd, &line)) == 1)
    {
        ft_parsing_line(e, line);
        ft_strdel(&line);
    }
    if (ret == -1)
    {
        ft_putstr_fd("Error\nRet == -1", 1);
        ft_exit(e);
    }
    ft_parsing_line(e, line);
    ft_strdel(&line);
    close(fd);
    ft_parsing_read(e);
    return (1);
}