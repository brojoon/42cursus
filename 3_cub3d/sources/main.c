/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 19:26:41 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:54:18 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int			main(int argc, char **argv)
{
	t_env		e;
	int			len;

	memset(&e, 0, sizeof(t_env));
	if (argv[2] && !ft_strcmp(argv[2], "--save") && argc < 4)
	{
		ft_read_map(argv[1], &e);
		ft_push_bmp(&e);
	}
	if (argc < 2 || argc > 2)
	{
		ft_exit("Error numbers of argc incorrect", -1);
	}
	len = (ft_strlen(argv[1]) - 4);
	if (!argv[1] || (ft_strncmp(argv[1] + len, ".cub", 4)))
	{
		ft_exit("ERROR no map or no file .cub", -1);
	}
	ft_read_map(argv[1], &e);
	ft_init_window(&e);
	return (0);
}
