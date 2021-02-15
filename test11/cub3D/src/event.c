/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:41:08 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 18:28:27 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_event_key_press(int key, t_cub3d *cub)
{
	if (key == _ESC)
		ft_tool_exit(0, cub, 0, "");
	else if (key == _W && cub->key->_w == 0)
		cub->key->_w = 1;
	else if (key == _S && cub->key->_s == 0)
		cub->key->_s = 1;
	else if (key == _A && cub->key->_a == 0)
		cub->key->_a = 1;
	else if (key == _D && cub->key->_d == 0)
		cub->key->_d = 1;
	else if (key == _LEFT && cub->key->_left == 0)
		cub->key->_left = 1;
	else if (key == _RIGHT && cub->key->_right == 0)
		cub->key->_right = 1;
	else if (key == _UP && cub->key->_up == 0)
		cub->key->_up = 1;
	else if (key == _DOWN && cub->key->_down == 0)
		cub->key->_down = 1;
	else if (key == _PLS)
		ft_health_change(cub, key, 1);
	else if (key == _QUES)
		cub->key->_help = (cub->key->_help == 0) ? 1 : 0;
	else if (key == _SPACE || key == _SHIFT)
		ft_event_key_press_opt(cub, key);
	return (1);
}

int					ft_event_key_press_opt(t_cub3d *cub, int opt)
{
	if (opt == _SPACE &&
		cub->map->map[(int)cub->pos->poy][(int)cub->pos->pox] == '3' &&
		cub->is_game_playing == 1)
	{
		cub->is_game_playing = 2;
		cub->idx = 0;
	}
	if (opt == _SHIFT && cub->is_game_playing == 0)
		cub->is_game_playing = 1;
	else if (opt == _SHIFT && cub->is_game_playing == 3)
		cub->is_game_playing = 4;
	else if (opt == _SHIFT && cub->is_game_playing == 4)
		cub->is_game_playing = 5;
	return (1);
}

int					ft_event_key_release(int key, t_cub3d *cub)
{
	if (key == _W && cub->key->_w == 1)
		cub->key->_w = 0;
	else if (key == _S && cub->key->_s == 1)
		cub->key->_s = 0;
	else if (key == _A && cub->key->_a == 1)
		cub->key->_a = 0;
	else if (key == _D && cub->key->_d == 1)
		cub->key->_d = 0;
	else if (key == _LEFT && cub->key->_left == 1)
		cub->key->_left = 0;
	else if (key == _RIGHT && cub->key->_right == 1)
		cub->key->_right = 0;
	else if (key == _UP && cub->key->_up == 1)
		cub->key->_up = 0;
	else if (key == _DOWN && cub->key->_down == 1)
		cub->key->_down = 0;
	return (1);
}

int					ft_event_destroy(t_cub3d *cub)
{
	ft_tool_exit(0, cub, 0, "");
	return (1);
}
