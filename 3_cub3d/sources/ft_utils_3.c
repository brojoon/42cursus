/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 18:57:41 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/17 22:45:38 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int     ft_check_identifiants(t_env *e)
{
    if (e->identifiants.r != 1 || e->identifiants.no != 1 ||
            e->identifiants.so != 1 || e->identifiants.we != 1
            || e->identifiants.ea != 1 || e->identifiants.s != 1
            || e->identifiants.f != 1 || e->identifiants.c != 1
            || e->identifiants.m != 1)
        return (0);
    else
        return (1);
}

char    *ft_delete_space_next(char *str)
{
    int     i;
    int     j;
    int     k;
    char    *tmp;

    i = 0;
    j = 0;
    k = 0;
    while (str[i++])
    {
        if (str[i] != ' ')
            j++;
    }
    tmp = (char *)malloc(sizeof(char) * (j + 1));
    if (tmp == NULL)
        return (NULL);
    i = 0;
    while (str[i++])
    {
        if (str[i] != ' ')
            tmp[k++] = str[i];
    }
    tmp[k] = '\0';
    free(str);
    return (tmp);
}

void    ft_check_malloc(t_env *e)
{
    if (!(e->sprite = (t_sprite *)ft_calloc(e->map.nbr_sprite,
        sizeof(t_sprite))))
    {
        ft_putstr_fd("Error\nMalloc sprite", 1);
        ft_exit(e);
    }
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
        ft_exit(e);
    return (0);
}

void    ft_parsing_line_check(t_env *e, char *line)
{
    int     i;

    i = 0;
    if ((line[i] != 'R' && line[i] != ' ' && line[i] != '\n'
    && line[i] != '\0' && line[i] != 'C' && line[i] != 'F' &&
    line[i] != 'S' && line[i] != '1' && (line[i] != 'N' &&
    line[i + 1] != 'O') && (line[i] != 'S' && line[i + 1] != 'O')
    && (line[i] != 'W' && line[i + 1] != 'E')
    && (line[i] != 'E' && line[i + 1] != 'A')))
    {
        ft_putstr_fd("Error\nWrong information in maps.cub\n", 1);
        ft_exit(e);
    }
}