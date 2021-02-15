/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:04:50 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:05:31 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_tool_exit(int mod, t_cub3d *cub, int err, char *msg)
{
	if (mod == 0)
		mlx_destroy_window(cub->mlx, cub->win);
	system("killall afplay");
	if (err == 1)
	{
		printf(
			"Error\n--------------------------------------------------\n");
		printf("%s\n--------------------------------------------------\n",
			msg);
	}
	if (err == 2)
		printf("%s\n", msg);
	if (err == 3)
	{
		printf("Problem with your color string format!\n");
		printf("Color consists only of '0123456789,'!\n your color line : %s",
			msg);
	}
	exit(0);
}
