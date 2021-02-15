/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:52:46 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:39:11 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_init_player(t_cub3d *cub)
{
	if (!(cub->pos = (t_pos *)malloc(sizeof(t_pos))))
		return (0);
	ft_util_bzero(cub->pos, sizeof(t_pos));
	cub->pos->pox = -20.0;
	cub->pos->poy = -20.0;
	cub->pos->spd = 0.10;
	cub->pos->dix = 1.0;
	cub->pos->diy = 0.0;
	cub->pos->plx = -20.0;
	cub->pos->ply = -20.0;
	cub->pos->rot = 0.10;
	cub->pos->cam = 1.0;
	cub->pos->hel = 10;
	cub->pos->hun = 10;
	cub->pos->left_food = 15;
	return (1);
}

int					ft_init_win_img(t_cub3d *cub)
{
	char			*map;

	cub->sav = 0;
	if (!(map = ft_cub_reader(cub->map->nam, cub)))
		return (0);
	cub->map->map = ft_translate_map(map, cub);
	if (!(cub->win = mlx_new_window(cub->mlx, cub->wid, cub->hei, "cub3D")))
		return (0);
	if (!(cub->img = ft_image_new(cub, cub->wid, cub->hei)))
		return (0);
	cub->intro_wid = (int)(cub->wid / 300) * 100;
	return (1);
}

int					ft_init_sound(t_cub3d *cub)
{
	if (!(cub->snd = (t_snd *)malloc(sizeof(t_snd))))
		return (0);
	ft_util_bzero(cub->snd, sizeof(t_snd));
	cub->snd->clo = clock();
	system("afplay -v 0.30 sound/main.mp3 &>/dev/null &");
	return (1);
}
