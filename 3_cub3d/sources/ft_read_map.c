/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:15:22 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/20 15:37:17 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char    *ft_delete_space(t_env *e)
{
    int     i;
    int     k;
    char    *tmp;

    i = -1;
    k = 0;
    while (e->map.buff[++i])
    {
        if (e->map.buff[i] == ' ')
        {
            e->map.buff[i] = 'X';
        }
    }
    if(!(tmp = (char *)malloc(sizeof(char) * (i + 1))))
        exit(0);
    i = -1;
    while (e->map.buff[++i])
            tmp[k++] = e->map.buff[i];
    tmp[k] = '\0';
    free(e->map.buff);
    return (tmp);
}

void    ft_recup_map(char *line, t_env *e)
{
    e->raycasting.y++;
    if (!e->map.buff)
        e->map.buff = ft_strdup("");
    else
        e->map.buff = ft_strjoin(e->map.buff, "\n", 1);
    e->map.buff = ft_strjoin(e->map.buff, line, 1);
}

void    ft_recup_map_2(t_env *e)
{
    int i;
    int j;
    int max;

    max = 0;
    i = 0;
    j = 0;
    e->map.buff = ft_delete_space(e);
    e->map.tab_map = ft_split(e->map.buff, '\n');
    while (e->map.tab_map[j][i])
    {
        i = 0;
        while (e->map.tab_map[j][i])
            i++;
        if (i > max)
            max = i;
        if (j < e->raycasting.y)
            j++;
        else
            break;
    }
    e->raycasting.x = max;
}

void    ft_pos_perso_next(t_env *e, int i, int j)
{
    if (e->map.tab_map[i][j] != '1' && e->map.tab_map[i][j] != '0' &&
                e->map.tab_map[i][j] != '2' && e->map.tab_map[i][j] != 'X' &&
                (ft_is_orientation(e, i, j) == 0))
    {
        ft_putstr_fd("Error\nWrong map", 1);
        ft_exit_before(e);
    }
    if (e->map.tab_map[i][j] == '2')
        e->map.nbr_sprite += 1;
    if ((ft_is_orientation(e, i, j) == 1))
    {
        e->map.pos_n_x = j + 0.5;
        e->map.pos_n_y = i + 0.5;
        e->identifier.perso = 1;
    }
}

void    ft_pos_perso(t_env *e)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    while (i < e->raycasting.y && e->map.tab_map[i])
    {
        while (e->map.tab_map[i][j])
        {
            ft_pos_perso_next(e, i, j);
            j++;
        }
        i++;
        j = 0;
    }
    if (e->identifier.perso == 0)
    {
        ft_putstr_fd("Error\nMiss perso", 1);
        ft_exit_before(e);
    }
    if (e->map.pos_n_x > e->raycasting.y && e->map.pos_n_x > e->raycasting.x)
    {
        ft_putstr_fd("Error\nError perso", 1);
        exit(0);
    }
}