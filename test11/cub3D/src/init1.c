/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:52:40 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 18:47:43 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub3d				*ft_init_cub_win(void)
{
	t_cub3d			*cub;

	if (!(cub = (t_cub3d *)malloc(sizeof(t_cub3d))))
		exit(1);
	ft_util_bzero(cub, sizeof(t_cub3d));
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (0);
	cub->opt = 0;
	cub->sig = 0;
	cub->wid = 400;
	cub->hei = 400;
	cub->is_game_playing = 0;
	cub->idx = 0;
	cub->intro_time = 0;
	cub->outro_time = 0;
	return (cub);
}

int					ft_init_textures(t_cub3d *cub, int num)
{
	int				idx;

	idx = 0;
	if (!(cub->txt = (t_img **)malloc(sizeof(t_img *) * num - 1)))
		return (0);
	while (idx < num)
	{
		if (!(cub->txt[idx] = (t_img *)malloc(sizeof(t_img) * 1)))
			return (0);
		ft_util_bzero(cub->txt[idx], sizeof(t_img));
		++idx;
	}
	return (1);
}

int					ft_init_sprites(t_cub3d *cub)
{
	int				idx;

	idx = 0;
	if (!(cub->spr = (t_img *)malloc(sizeof(t_img) * 1)))
		return (0);
	ft_util_bzero(cub->spr, sizeof(t_img));
	if (!(cub->spr_scr = malloc(sizeof(t_lst))))
		return (0);
	ft_util_bzero(cub->spr_scr, sizeof(t_lst));
	cub->spr_scr->pox = -1;
	cub->spr_scr->poy = -1;
	return (1);
}

int					ft_init_map(t_cub3d *cub, char *map_name)
{
	if (!(cub->map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	ft_util_bzero(cub->map, sizeof(t_map));
	cub->map->nam = map_name;
	cub->map->hei = 0;
	cub->map->wid = 0;
	return (1);
}

int					ft_init_keybuff(t_cub3d *cub)
{
	if (!(cub->key = (t_key *)malloc(sizeof(t_key))))
		return (0);
	ft_util_bzero(cub->key, sizeof(t_key));
	cub->key->_w = 0;
	cub->key->_a = 0;
	cub->key->_s = 0;
	cub->key->_d = 0;
	cub->key->_left = 0;
	cub->key->_right = 0;
	cub->key->_up = 0;
	cub->key->_down = 0;
	cub->key->_help = 1;
	cub->key->_map = 0;
	return (1);
}
