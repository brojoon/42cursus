/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:46:16 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 11:46:18 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_key_manager(t_cub3d *cub)
{
	if (cub->key->_w == 1)
		ft_player_move_front_back(cub, 0);
	if (cub->key->_s == 1)
		ft_player_move_front_back(cub, 1);
	if (cub->key->_a == 1)
		ft_player_move_left_right(cub, 0);
	if (cub->key->_d == 1)
		ft_player_move_left_right(cub, 1);
	if (cub->key->_left == 1)
		ft_camera_turn_left_right(cub, 0);
	if (cub->key->_right == 1)
		ft_camera_turn_left_right(cub, 1);
	if (cub->key->_up == 1)
		ft_camera_turn_up_down(cub, 0);
	if (cub->key->_down == 1)
		ft_camera_turn_up_down(cub, 1);
	return (1);
}
