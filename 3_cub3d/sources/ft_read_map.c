/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/13 19:15:22 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/26 10:24:18 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char    **ft_map_size(t_env *e)
{
    int     i;
    int     max;
    int     cnt;
    char    **tmp;

    i = -1;
    max = 0;
    cnt = 0;
    while (e->map.buff[++i])
    {
        if (e->map.buff[i] == '\n')
        {
            if (max < cnt)
                max = cnt;
            cnt = 0;
        }
        else
            cnt++;
    }
    e->raycasting.x = max;
    if(!(tmp = (char **)malloc(sizeof(char *) * e->raycasting.y)))
        ft_exit("Error delete space func malloc fail", -1);
    i = 0;
    while (i < e->raycasting.y)
    {
          if(!(*(tmp + i) = (char *)malloc(e->raycasting.x)))
            ft_exit("Error delete space func malloc fail", -1);
          i++;
    }
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
    char **tmp;

    i = -1;
    tmp = ft_map_size(e);
    e->map.tab_map = ft_split(e->map.buff, '\n');
    while (++i < e->raycasting.y)
    {
        j = 0;
        while (e->map.tab_map[i][j] && j < e->raycasting.x)
        {
            if (e->map.tab_map[i][j] != ' ')
                tmp[i][j] = e->map.tab_map[i][j];
            else
                tmp[i][j] = 'X';
            j++;
        }
        while (j < e->raycasting.x)
            tmp[i][j++] = 'X';

    }
    i = 0;
    while (e->map.tab_map[i])
    {
        free(e->map.tab_map[i]);
        i++;
    }
    free(e->map.tab_map);
    e->map.tab_map = tmp;
    tmp = NULL;
    i = 0;
    j = 0;
    while (i < e->raycasting.y)
    {
        j = 0;
        while (j < e->raycasting.x)
        {
            printf("%c", e->map.tab_map[i][j]);
            j++;
        }
        printf("\n");
        i++;
    }
      printf("y :%d\n ", e->raycasting.y);
}

void    ft_pos_perso_next(t_env *e, int i, int j)
{
    if (e->map.tab_map[i][j] != '1' && e->map.tab_map[i][j] != '0' &&
                e->map.tab_map[i][j] != '2' && e->map.tab_map[i][j] != 'X' &&
                (ft_is_orientation(e, i, j) == 0))
    {
        ft_exit("Error wrong map pos_perso_next", -1);
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
    while (i < e->raycasting.y)
    {
        while (j < e->raycasting.x)
        {
            ft_pos_perso_next(e, i, j);
            j++;
        }
        i++;
        j = 0;
    }
    if (e->identifier.perso == 0)
    {
        ft_exit( "Error miss perso", -1);
    }
    if (e->map.pos_n_x > e->raycasting.y && e->map.pos_n_x > e->raycasting.x)
    {
        ft_exit("Error perso out of range", -1);
    }
}