/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:24:23 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:39:29 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_save(t_cub3d *cub, char *arv[])
{
	if (ft_util_strlen(arv[2]) > 0)
	{
		if (ft_util_strlen(arv[2]) == ft_util_strlen("--save") &&
			ft_util_strncmp(arv[2], "--save", ft_util_strlen(arv[2])) == 0)
		{
			cub->sav = 1;
			ft_raycasting(cub);
		}
		else
			ft_error_input();
	}
	else
		cub->sav = 0;
}

int					main(int arc, char *arv[])
{
	t_cub3d		*cub;

	if (arc < 2)
		ft_error_input();
	if (!(cub = ft_init_cub_win()) ||
		!ft_init_textures(cub, 11) ||
		!ft_init_sprites(cub) ||
		!ft_init_map(cub, arv[1]) ||
		!ft_init_keybuff(cub) ||
		!ft_init_player(cub) ||
		!ft_init_win_img(cub) ||
		!ft_init_sound(cub))
		ft_tool_exit(1, cub, 1, "something problem at init.. sorry!");
	ft_save(cub, arv);
	mlx_hook(cub->win, 2, 0, ft_event_key_press, cub);
	mlx_hook(cub->win, 3, 1, ft_event_key_release, cub);
	mlx_hook(cub->win, 17, 17, ft_event_destroy, cub);
	mlx_loop_hook(cub->mlx, ft_loop, cub);
	if (cub->sav != 1)
		mlx_loop(cub->mlx);
	ft_tool_exit(0, cub, 0, "");
	return (0);
}
