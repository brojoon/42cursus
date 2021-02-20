/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 17:43:45 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/19 23:03:15 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char        *ft_recup_root(char *line, int i)
{
    char    **tmp;
    char    *ret;

    i = 0;
    if (!(tmp = ft_split(line, ' ')))
    {
        ft_putstr_fd("Error\n", 1);
        exit(0);
    }
    if (!(ret = ft_strdup(tmp[1])) && ret[i] != '.' && ret[i + 1] != '/')
    {
        ft_putstr_fd("Error\n", 1);
        exit(0);
    }
    if (tmp[2])
    {
        ft_putstr_fd("Error\nWrong .cub", 1);
        exit(0);
    }
    i = 0;
    while (tmp[i])
        free(tmp[i++]);
    free(tmp[i]);
    free(tmp);
    return (ret);
}

int     ft_recup_color(char *line, t_env *e, int i)
{
    int     color;
    i = 1;
    ft_space(line, &i);
    color = ft_rgb_color(line, &i) * 65536;
    color += ft_rgb_color(line, &i) * 256;
    if (ft_atoi(&line[i]) < 0 || ft_atoi(&line[i]) > 255)
        exit(0);
    color += ft_atoi(&line[i]);
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
    i++;
    e->axes.axe_x = ft_atoi(&line[i]);
    ft_space(line, &i);
    while (ft_isdigit(line[i]))
        i++;
    e->axes.axe_y = ft_atoi(&line[i]);
    ft_space(line, &i);
    while (ft_isdigit(line[i]))
        i++;
    ft_space(line, &i);
    if (line[i])
    {
        ft_putstr_fd("Error\nWrong .cub", 1);
        exit(0);
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