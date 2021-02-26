/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 18:10:32 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/26 18:28:28 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void        ft_mv_up(t_env *e)
{
    if (e->mvt.up == 1)
    {
        if ((e->map.tab_map[(int)(e->map.pos_n_y)]
                [(int)(e->map.pos_n_x + e->orientation.dir_x * 0.03)] != '1')
        && (e->map.tab_map[(int)(e->map.pos_n_y)]
                [(int)(e->map.pos_n_x + e->orientation.dir_x * 0.03)] != '2'))
            e->map.pos_n_x += e->orientation.dir_x * 0.03;
        if ((e->map.tab_map[(int)(e->map.pos_n_y + e->orientation.dir_y * 0.03)]
                [(int)(e->map.pos_n_x)] != '1')
        && (e->map.tab_map[(int)(e->map.pos_n_y + e->orientation.dir_y * 0.03)]
                [(int)(e->map.pos_n_x)] != '2'))
            e->map.pos_n_y += e->orientation.dir_y * 0.03;   
    }
}

int         ft_deplacement(t_env *e)
{
    e->mvt.vit_rot = 0.020;
    ft_mv_up(e);
    ft_deplacement_down(e);
    ft_deplacement_left(e);
    ft_deplacement_right(e);
    ft_init_image(e);
    return (0);
}

int     ft_key_down(int keycode, t_env *e)
{
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

int     ft_key_up(int keycode, t_env *e)
{
    if (keycode == 119)
        e->mvt.up = 0;
    if (keycode == 115)
        e->mvt.down = 0;
    if (keycode == 100)
        e->mvt.right = 0;
    if (keycode == 97)
        e->mvt.left = 0;
    if (keycode == 65363)
        e->mvt.rot_right = 0;
    if (keycode == 65361)
        e->mvt.rot_left = 0;
    if (keycode == 65307)
        ft_exit("ESC", 0);
    return (0);
}