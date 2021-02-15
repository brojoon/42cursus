/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:23:52 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 12:16:05 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void				ft_error_input(void)
{
	printf("Error\n--------------------------------------------------\n");
	printf("somethig problem with your input.\n");
	printf("tips:\n   ./cub3D map_name.cub [--save]\n");
	printf("--------------------------------------------------\n");
	exit(-1);
}
