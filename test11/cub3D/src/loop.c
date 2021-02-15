/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:02:43 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:13:16 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_loop(t_cub3d *cub)
{
	if (cub->is_game_playing == 0)
		ft_special_intro(cub);
	if (cub->is_game_playing == 1 ||
		cub->is_game_playing == 4)
	{
		ft_loop_health(cub);
		ft_loop_draw(cub);
		ft_health_draw(cub);
		ft_hungry_draw(cub);
		ft_key_manager(cub);
		ft_music_play(cub);
	}
	if (cub->is_game_playing == 2)
		ft_special_outro(cub);
	if (cub->is_game_playing == 3)
		ft_special_outro2(cub);
	if (cub->is_game_playing == 5)
		ft_tool_exit(1, cub, 2, "game finished");
	return (0);
}

void				ft_loop_health(t_cub3d *cub)
{
	if (cub->pos->hun == 10 && cub->pos->hel < 10 &&
		(int)(clock() / CLOCKS_PER_SEC) >= cub->pos->last_heal + 5)
	{
		++cub->pos->hel;
		cub->pos->last_heal = (int)(clock() / CLOCKS_PER_SEC);
	}
	if (cub->pos->hun == 0 &&
		(int)(clock() / CLOCKS_PER_SEC) >= cub->pos->last_hungry_hurt + 5)
	{
		--cub->pos->hel;
		system("afplay -v 0.30 sound/oof.mp3 &>/dev/null &");
		cub->pos->last_hungry_hurt = (int)(clock() / CLOCKS_PER_SEC);
	}
	if ((int)(clock() / CLOCKS_PER_SEC) >= cub->pos->last_hungry + 10)
	{
		--cub->pos->hun;
		cub->pos->last_hungry = (int)(clock() / CLOCKS_PER_SEC);
	}
}

void				ft_loop_draw(t_cub3d *cub)
{
	if (!ft_raycasting(cub))
		ft_tool_exit(0, cub, 0, "");
	if (cub->key->_help == 1)
		ft_loop_draw_string_put(cub);
	mlx_string_put(cub->mlx, cub->win, cub->wid - 200, 25, 0xffffff,
		ft_util_strjoin("food left : ",
			ft_util_strjoin(ft_util_itoa(cub->pos->left_food), "/15")));
}

void				ft_loop_draw_string_put(t_cub3d *cub)
{
	char			*str;
	char			*num;

	mlx_string_put(cub->mlx, cub->win, 25, 75, 0xffffff,
		"Look Up : /\\, Look Down : \\/, Look left : <, Look right : >");
	mlx_string_put(cub->mlx, cub->win, 25, 100, 0xffffff,
		"Forward : W, Backward : S, Left : A, Right : D");
	mlx_string_put(cub->mlx, cub->win, 25, 120, 0xffffff,
		"Eat food : +");
	mlx_string_put(cub->mlx, cub->win, 25, 140, 0xffffff,
		"Toggle Help : ?, Leave Game : ESC");
	str = ft_util_strjoin("Map Name Test : ", cub->map->nam);
	mlx_string_put(cub->mlx, cub->win, 25, 170, 0xffffff, str);
	num = ft_util_itoa(cub->wid);
	str = ft_util_strjoin("Width : ", num);
	num = ft_util_itoa(cub->hei);
	str = ft_util_strjoin(str, ", Height : ");
	str = ft_util_strjoin(str, num);
	mlx_string_put(cub->mlx, cub->win, 25, 190, 0xffffff, str);
}

void				ft_music_play(t_cub3d *cub)
{
	long			clo_tck;
	clock_t			act_tim;

	act_tim = clock();
	act_tim = CLOCKS_PER_SEC;
	if ((double)(act_tim - cub->snd->clo) / (double)clo_tck >= 129.5)
	{
		system("killall afplay");
		system("afplay -v 0.30 sound/main.mp3 &>/dev/null &");
		cub->snd->clo = act_tim;
	}
}
