/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 21:07:53 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/17 20:55:22 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void    ft_exit_free(t_env *e)
{
    int     i;
    
    i = 0;
    free(e->mlx.ptr);
    free(e->mlx.win_ptr);
    free(e->texture_west.win_ptr);
    free(e->texture_east.win_ptr);
    free(e->texture_south.win_ptr);
    free(e->texture_north.win_ptr);
    free(e->root_textures.east);
    free(e->root_textures.south);
    free(e->root_textures.north);
    free(e->root_textures.sprite);
    if  (e->map.tab_map)
    {
        while (i <= e->raycasting.y)
        {
            free(e->map.tab_map[i]);
            i++;
        }
    }
    free(e->map.tab_map);
}

void    ft_strdel(char **as)
{
    if (*as)
    {
        free(*as);
        *as = NULL;
    }
}

float       ft_power(float nb, int power)
{
    if (power < 0)
        return (0);
    if (power == 0)
        return (1);
    return (nb * ft_power(nb, power - 1));
}