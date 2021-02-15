/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:14:35 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:14:43 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_raycasting_main_hit_(t_cub3d *cub, t_ray *ray)
{
	while (ray->hit == 0)
	{
		ft_raycasting_main_hit_wall(ray);
		if (cub->map->map[ray->map_poy][ray->map_pox] == '1')
			ray->hit = 1;
		else if (cub->map->map[ray->map_poy][ray->map_pox] == '2')
			ft_sprite(cub, ray);
	}
}

void				ft_raycasting_main_hit_wall(t_ray *ray)
{
	if (ray->sid_pox < ray->sid_poy)
	{
		ray->sid_pox += ray->dlt_pox;
		ray->map_pox += ray->stp_pox;
		if (ray->stp_pox == 1)
			ray->sid = 0;
		if (ray->stp_pox == -1)
			ray->sid = 1;
	}
	else
	{
		ray->sid_poy += ray->dlt_poy;
		ray->map_poy += ray->stp_poy;
		if (ray->stp_poy == 1)
			ray->sid = 2;
		if (ray->stp_poy == -1)
			ray->sid = 3;
	}
}

void				ft_raycasting_main_perp(t_cub3d *cub, t_ray *ray)
{
	if (ray->sid == 0 || ray->sid == 1)
		ray->perp_wd = (ray->map_pox - cub->pos->pox +
			(1 - ray->stp_pox) / 2) / ray->ray_dix;
	else
		ray->perp_wd = (ray->map_poy - cub->pos->poy +
			(1 - ray->stp_poy) / 2) / ray->ray_diy;
	ray->hei = (int)(cub->hei / ray->perp_wd);
	ray->stt = (-ray->hei / 2 + ((cub->hei / 2) * cub->pos->cam));
	if (ray->stt < 0)
		ray->stt = 0;
	ray->end = (ray->hei / 2 + ((cub->hei / 2) * cub->pos->cam));
	if (ray->end >= cub->hei)
		ray->end = cub->hei - 1;
}
