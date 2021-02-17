/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 00:20:05 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/17 19:44:51 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_sprite_distance(t_env *e)
{
    int     i;

    i = 0;
    while (i < e->map.nbr_sprite)
    {
        e->sprite[i].sprite_order = i;
        e->sprite[e->sprite[i].sprite_order].sprite_distance =
            ft_power(e->map.pos_n_x - e->sprite[e->sprite[i].
                    sprite_order].coord.x, 2) +
            ft_power(e->map.pos_n_y - e->sprite[e->sprite[i].
                    sprite_order].coord.y, 2);
        i++;
    }
}

void    ft_swap_sprite(t_env *e)
{
    int     i;
    int     tmp;

    i = 0;
    while (i + 1 < e->map.nbr_sprite)
    {
        if (e->sprite[e->sprite[i].sprite_order].sprite_distance <
                e->sprite[e->sprite[i + 1].sprite_order].sprite_distance)
        {
            tmp = e->sprite[i].sprite_order;
            e->sprite[i].sprite_order = e->sprite[i + 1].sprite_order;
            e->sprite[i + 1].sprite_order = tmp;
            ft_swap_sprite(e);
        }
        i++;
    }
}

void    ft_get_color(t_env *e, int i)
{
    if (e->spt.tex_y > 0)
    {
        if (e->sprite[i].image.get_data[e->spt.tex_x + e->spt.tex_y
                * e->sprite[i].image.w] != 0)
        {
            e->sprite[i].image.color = e->sprite[i].image.get_data
                [e->spt.tex_x + e->spt.tex_y * e->sprite[i].image.w];
        }
        else
        {
            e->sprite[i].image.color = 0xBFD195;
        }
    }
}

void    ft_free_sprite(t_env *e)
{
    if (e->spt.dist_wall)
    {
        free(e->spt.dist_wall);
        e->spt.dist_wall = NULL;
    }
}

void    ft_check_wall_again(t_env *e)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < e->raycasting.y)
    {
        while (e->map.tab_map[i][j])
            j++;
        j--;
        if (e->map.tab_map[i][j] != '1' && e->map.tab_map[i][j] != 'X')
        {
            ft_putstr_fd("Error map\nOnly 1 on the edges of your map", 1);
            ft_exit(e);
        }
        i++;
        j = 0;
    }
}