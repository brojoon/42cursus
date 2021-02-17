/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 22:50:59 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/16 04:27:06 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_pos_sprite_next(t_env *e)
{
    if (e->spt.start_y < 0)
        e->spt.start_y = 0;
    e->spt.end_y = e->spt.height / 2 + e->axes.axe_y / 2;
    if (e->spt.end_y >= e->axes.axe_y)
        e->spt.end_y = e->axes.axe_y - 1;
    e->spt.width = abs((int)(e->axes.axe_y / e->spt.transform_y));
    e->spt.start_x = -e->spt.width / 2 + e->spt.screen_x;
    if (e->spt.start_x < 0)
        e->spt.start_x = 0;
    e->spt.end_x = e->spt.width / 2 + e->spt.screen_x;
    if (e->spt.end_x >= e->axes.axe_x)
        e->spt.end_x = e->axes.axe_x - 1;
}

void    ft_pos_sprite(t_env *e, int i)
{
    e->spt.x = e->sprite[e->sprite[i].sprite_order].coord.x - e->map.pos_n_x;
    e->spt.y = e->sprite[e->sprite[i].sprite_order].coord.y - e->map.pos_n_y;
    e->spt.inv_det = 1.0 / (e->map.plan_x * e->orientation.dir_y -
            e->orientation.dir_x * e->map.plan_y);
    e->spt.transform_x = e->spt.inv_det * (e->orientation.dir_y *
            e->spt.x - e->orientation.dir_x * e->spt.y);
    e->spt.transform_y = e->spt.inv_det * (-e->map.plan_y * e->spt.x
            + e->map.plan_x * e->spt.y);
    e->spt.screen_x = (int)((e->axes.axe_x / 2) * (1.0 + e->spt.transform_x /
            e->spt.transform_y));
    e->spt.height = abs((int)(e->axes.axe_y / e->spt.transform_y));
    e->spt.start_y = -e->spt.height / 2 + e->axes.axe_y / 2;
    ft_pos_sprite_next(e);
}

void    ft_sprite_next(t_env *e, int x, int i)
{
    int     y;
    int     d;

    y = e->spt.start_y;
    while (y < e->spt.end_y)
    {
        d = (y * 256 - e->axes.axe_y * 128 + e->spt.height * 128);
        e->spt.tex_y = (d * e->sprite[i].image.h / e->spt.height) / 256;
        ft_get_color(e, i);
        if (e->sprite[i].image.color != 0xBFD195 &&
                e->spt.transform_y < e->spt.dist_wall[x])
        {
            if (x >= 0 && x < e->axes.axe_x && y >= 0 && y < e->axes.axe_y)
                e->mlx.get_data[x + y * (e->mlx.size_line
                        / 4)] = e->sprite[i].image.color;
        }
        y++;
    }
}

void    ft_sprite(t_env *e)
{
    int i;
    int x;
    
    i = 0;
    ft_sprite_distance(e);
    ft_swap_sprite(e);
    while (i < e->map.nbr_sprite)
    {
        ft_pos_sprite(e, i);
        x = e->spt.start_x;
        while (x < e->spt.end_x && x < e->axes.axe_x)
        {
            e->spt.tex_x = (int)(256 * (x - (-e->spt.width / 2
                        + e->spt.screen_x)) * e->sprite[i].image.w / 
                e->spt.width) / 256;
            if (e->spt.transform_y > 0)
                ft_sprite_next(e, x, i);
            x++;
        }
        i++;
    }
    ft_free_sprite(e);
}

void    ft_init_sprite(t_env *e)
{
    int     x;
    int     y;
    int     i;

    y = 0;
    i = 0;
    while (e->map.tab_map[y])
    {
        x = 0;
        while (e->map.tab_map[y][x])
        {
            if (e->map.tab_map[y][x] == '2')
            {
                e->sprite[i].coord = (t_coord){x + 0.5, y + 0.5};
                i++;
            }
            x++;
        }
        y++;
    }
}