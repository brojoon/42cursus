/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:20:53 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/21 22:09:13 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void        ft_parsing_check(t_env *e)
{
    if (ft_check_identifier(e) == 0)
    {
        ft_putstr_fd("Error\nmap", 1);
        ft_exit(e);
    }
    ft_recup_map_2(e);
    ft_pos_perso(e);
    ft_orientation_perso(e);
}

void        ft_space(char *line, int *i)
{
    while ((line[*i] == ' ' || line[*i] == '\t' || line[*i] == '\n')
            || (line[*i] == '\r' || line[*i] == '\v' || line[*i] == '\f'))
        (*i)++;
}

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

int         ft_exit_before(t_env *e)
{
    if (e->sprite)
        free(e->sprite);
    if (e->map.buff)
        free(e->map.buff);
    ft_exit_free(e);
    exit(0);
    return (0);
}