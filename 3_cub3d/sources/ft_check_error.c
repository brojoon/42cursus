/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:45:25 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/20 21:02:23 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_check_wall_next(t_env *e)
{
    int i;
    int j;

    i = 0;
    j = e->raycasting.y - 1;
    while (e->map.tab_map[j][i])
    {
        if (e->map.tab_map[j][i] != '1' && e->map.tab_map[j][i] != 'X')
        {
            ft_putstr_fd("Error map\nOnly 1 on the edges of your map", 1);
            ft_exit(e);
        }
        i++;
    }
    ft_check_wall_again(e);
}

void    ft_check_wall(t_env *e)
{
    int i;

    i = 0;
    while (e->map.tab_map[0][i])
    {
        if (e->map.tab_map[0][i] != '1' && e->map.tab_map[0][i] != 'X')
        {
            ft_putstr_fd("Error map\nOnly 1 on the edges of your map", 1);
            ft_exit(e);
        }
        i++;
    }
    i = 0;
    while (i < e->raycasting.y)
    {
        if (e->map.tab_map[i][0] != '1' && e->map.tab_map[i][0] != 'X')
        {
            ft_putstr_fd("Error map\nOnly 1 on the edges of your map", 1);;
            ft_exit(e);
        }
        i++;
    }
    ft_check_wall_next(e);
}

void    ft_check_resolution_next(t_env *e)
{
    int     sizex;
    int     sizey;

    sizex = 0;
    sizey = 0;
    if (!(mlx_get_screen_size(e->mlx.ptr, &sizex, &sizey)))
    {
        ft_putstr_fd("Error\n mlx_get_screen", 1);
        ft_exit_before(e);
    }
    if (e->axes.axe_x > sizex)
        e->axes.axe_x = sizex;
    if (e->axes.axe_y > sizey)
        e->axes.axe_y = sizey;
    if (e->axes.axe_x <= 0 || e->axes.axe_y <= 0)
    {
        ft_putstr_fd("Error\nResolution <= 0", 1);
        ft_exit_before(e);
    }
}

int    ft_rgb_color(char *line, int *i)
{
    int ret;
    if (ft_atoi(&line[*i]) < 0 || ft_atoi(&line[*i]) > 255)
    {
        ft_putstr_fd("Error\nrgb", 1);
        exit(0);
    }
    ret = ft_atoi(&line[*i]);
    while (ft_isdigit(line[*i]))
        (*i)++;
    if (line[*i] != ',')
        exit(0);
    (*i)++;
    ft_space(line, i);
    
    return ret;
}
