/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:43:45 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/17 22:44:22 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char        *ft_recup_root(char *line, t_env *e, int i)
{
    char    **tab;
    char    *line2;

    i = 0;
    if (!(tab = ft_split(line, ' ')))
    {
        ft_putstr_fd("Error\n", 1);
        ft_exit(e);
    }
    if (!(line2 = ft_strdup(tab[1])) && line2[i] != '.' && line2[i + 1] != '/')
    {
        ft_putstr_fd("Error\n", 1);
        ft_exit(e);
    }
    if (tab[2])
    {
        ft_putstr_fd("Error\nWrong .cub", 1);
        ft_exit(e);
    }
    i = 0;
    while (tab[i])
        free(tab[i++]);
    free(tab[i]);
    free(tab);
    return (line2);
}

int     ft_recup_color(char *line, t_env *e, int i)
{
    int     color;

    i = 1;
    ft_space(line, &i);
    ft_check_color(e, line, i);
    color = ft_atoi(&line[i]) * 65536;
    while (ft_isdigit(line[i]))
        i++;
    ft_space(line, &i);
    color += ft_atoi(&line[++i]) * 256;
    ft_space(line, &i);
    while (ft_isdigit(line[i]))
        i++;
    ft_space(line, &i);
    color += ft_atoi(&line[++i]);
    ft_space(line, &i);
    while (ft_isdigit(line[i]))
        i++;
    ft_space(line, &i);
    if (line[i])
    {
        ft_putstr_fd("Error\nWrong .cub", 1);
        ft_exit(e);
    }
    return (color);
}

void        ft_recup_axes(t_env *e, char *line)
{
    int     i;

    i = 0;
    ft_space(line, &i);
    while (ft_isprint(line[i]) == 0)
        i++;
    i++;
    e->axes.axe_x = ft_atoi(&line[i]);
    ft_space(line, &i);
    while (ft_isdigit(line[i]))
        i++;
    while (ft_isprint(line[i]) == 0)
        i++;
    i++;
    e->axes.axe_y = ft_atoi(&line[i]);
    ft_space(line, &i);
    while (ft_isdigit(line[i]))
        i++;
    ft_space(line, &i);
    if (line[i])
    {
        ft_putstr_fd("Error\nWrong .cub", 1);
        ft_exit(e);
    }
}

int     ft_key_down(int keycode, t_env *e)
{
    printf("%d", keycode);
    if (keycode == 119)
        e->mvt.up = 1;
    if (keycode == 115)
        e->mvt.down = 1;
    if (keycode == 100)
        e->mvt.right = 1;
    if (keycode == 97)
        e->mvt.left = 1;
    if (keycode == 65363)
        e->mvt.rot_right = 1;
    if (keycode == 65361)
        e->mvt.rot_left = 1;
    return (0);
}