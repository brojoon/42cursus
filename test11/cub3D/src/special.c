/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 11:02:46 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:04:33 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_special_intro(t_cub3d *cub)
{
	int				now;
	int				wid;

	wid = cub->intro_wid - 30;
	now = (int)(clock() / CLOCKS_PER_SEC);
	mlx_put_image_to_window(cub->mlx, cub->win, cub->txt[8]->img,
		(cub->wid - cub->txt[8]->wid) / 2, 10);
	mlx_string_put(cub->mlx, cub->win, 30, cub->hei - 30, 0x2E2E2E,
		"Press Shift to skip intro");
	ft_special_intro_print_welcome(cub, &wid);
	ft_special_intro_print_cub3d(cub, &wid);
	if (cub->idx == 18)
		mlx_string_put(cub->mlx, cub->win, 100, 400, 0xffffff,
			"You need to find hidden place and push spacebar to clear game!");
	if (cub->idx == 25)
		cub->is_game_playing = 1;
	if (now >= cub->intro_time + 1)
	{
		cub->intro_time = now;
		++cub->idx;
		cub->pos->last_hungry = now;
	}
}

void				ft_special_intro_print_welcome(t_cub3d *cub, int *w)
{
	if (cub->idx >= 0)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "W");
	if (cub->idx >= 1)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "e");
	if (cub->idx >= 2)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "l");
	if (cub->idx >= 3)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "c");
	if (cub->idx >= 4)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "o");
	if (cub->idx >= 5)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "m");
	if (cub->idx >= 6)
		*w += 30 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "e");
	if (cub->idx >= 7)
		*w += 45 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "to");
	if (cub->idx >= 8)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "K");
	if (cub->idx >= 9)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "K");
	if (cub->idx >= 10)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "I");
	if (cub->idx >= 11)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "M");
}

void				ft_special_intro_print_cub3d(t_cub3d *cub, int *w)
{
	if (cub->idx >= 12)
		*w += 35 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "'s");
	if (cub->idx >= 13)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "C");
	if (cub->idx >= 14)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "U");
	if (cub->idx >= 15)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "B");
	if (cub->idx >= 16)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "3");
	if (cub->idx >= 17)
		*w += 15 + mlx_string_put(cub->mlx, cub->win, *w, 375, 0xffffff, "D");
}

void				ft_special_outro(t_cub3d *cub)
{
	int				wid;

	wid = cub->intro_wid - 100;
	mlx_put_image_to_window(cub->mlx, cub->win, cub->txt[9]->img, 0, 0);
	if (cub->idx >= 0 && cub->idx < 15)
		wid += 15 * 14 + mlx_string_put(cub->mlx, cub->win, wid, 260, 0x00ffff,
			"Congraturation!");
	if (cub->idx >= 3 && cub->idx < 15)
		wid += 15 + mlx_string_put(cub->mlx, cub->win, wid, 260, 0x00ffff,
			"You have cleared the game!");
	if (cub->idx >= 5 && cub->idx < 15)
	{
		mlx_string_put(cub->mlx, cub->win, 200, 300, 0x00ffff,
		"visit next websites to see more.");
		mlx_string_put(cub->mlx, cub->win, 200, 340, 0x00ffff,
		"https://github.com/KKWANH    https://kkim-blog.tistory.com");
	}
	else if (cub->idx >= 15)
		cub->is_game_playing = 3;
	if ((int)(clock() / CLOCKS_PER_SEC) >= cub->outro_time + 1)
	{
		cub->outro_time = (int)(clock() / CLOCKS_PER_SEC);
		++cub->idx;
	}
}

void				ft_special_outro2(t_cub3d *cub)
{
	mlx_put_image_to_window(cub->mlx, cub->win, cub->txt[10]->img, 0, 0);
	mlx_string_put(cub->mlx, cub->win, 325, 400, 0xffffff,
		"Press shift to play more!");
}
