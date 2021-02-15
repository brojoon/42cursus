/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:21:03 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:38:40 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char				*ft_cub_reader(char *fil, t_cub3d *cub)
{
	int				fd;
	int				rst_gnl;
	char			*lin;
	char			*map;

	if ((fd = open(fil, O_RDONLY)) == -1)
		ft_tool_exit(1, cub, 1, "Error! :(\ncannot read the file!");
	map = (char *)malloc(sizeof(char) * 2);
	ft_util_bzero(map, sizeof(char));
	lin = (char *)malloc(sizeof(char) * 1);
	ft_util_bzero(lin, sizeof(char));
	while ((rst_gnl = get_next_line(fd, &lin)) != -1)
	{
		if (lin && !ft_cub_read(lin, &map, rst_gnl, cub))
			return (0);
		lin = NULL;
		if (rst_gnl == 0)
			break ;
	}
	return (map);
}

int					ft_cub_read(char *lin, char **map, int rst_gnl,
	t_cub3d *cub)
{
	int				idx;
	int				rst_sub;

	idx = 0;
	while (ft_util_is_empty(lin[idx]) == 1)
		++idx;
	if (cub->sig == 1 && lin[idx] != '\0')
		ft_tool_exit(1, cub, 1, "something problem with map description!");
	if (!(rst_sub = ft_cub_read_sub(lin, idx, cub)))
		return (0);
	if (rst_sub == 2)
	{
		if (ft_cub_read_map(lin, map, idx, rst_gnl))
		{
			cub->opt = 1;
			return (1);
		}
		else
			ft_cub_read_other(lin, idx, cub);
	}
	return (1);
}

int					ft_cub_read_sub(char *lin, char idx, t_cub3d *cub)
{
	t_num			*num;

	if (!(num = (t_num *)malloc(sizeof(t_num))))
		return (0);
	ft_util_bzero(num, sizeof(t_num));
	if (lin[idx] && lin[idx + 1])
	{
		num->n1 = lin[idx];
		num->n2 = lin[idx + 1];
	}
	else
		return (2);
	if (num->n1 == 'R')
		return (ft_cub_read_window_size(lin, cub));
	else if (num->n1 == 'N' || num->n1 == 'W' || num->n1 == 'E' ||
		num->n1 == 'S' || num->n1 == 'P' || num->n1 == 'L')
		return (ft_cub_read_path(lin, num, idx, cub));
	else if (num->n1 == 'F' || num->n1 == 'C')
		return (ft_cub_read_color(lin, lin[idx], idx, cub));
	return (2);
}

int					ft_cub_read_map(char *l, char **map, int i, int rst_gnl)
{
	if (l[i] == '1' || l[i] == '2' || l[i] == '3' || l[i] == '0' ||
		l[i] == 'N' || l[i] == 'S' || l[i] == 'W' || l[i] == 'E')
	{
		*map = ft_util_strjoin(*map, l);
		if (rst_gnl != 0 && l[i])
			*map = ft_util_strjoin(*map, "\n");
		free(l);
		return (1);
	}
	return (0);
}

int					ft_cub_read_other(char *lin, int idx, t_cub3d *cub)
{
	if (lin[idx])
	{
		if (lin[idx] != '\0' && lin[idx] != '\n')
			ft_tool_exit(1, cub, 1,
				ft_util_strjoin("unknown identifier : ", lin));
		free(lin);
	}
	else if (lin[idx] == '\0' && cub->opt == 1)
		cub->sig = 1;
	return (1);
}
