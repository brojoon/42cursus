/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:55:11 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:57:51 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char				**ft_translate_map(char *str, t_cub3d *cub)
{
	char			**map;

	ft_translate_map_get_size(str, cub);
	map = ft_translate_map_malloc(cub);
	map = ft_translate_map_init(str, map, cub);
	if (!ft_translate_map_check(cub, map))
		ft_tool_exit(1, cub, 1, "Sorry! There's problem in map format");
	if (cub->pos->pox == -20.0 || cub->pos->poy == -20.0 ||
		cub->pos->dix == -20.0 || cub->pos->diy == -20.0)
		ft_tool_exit(1, cub, 1,
			"Sorry! Logic problem!\nPlayer(cub->pos) didn't init!");
	free(str);
	return (map);
}

void				ft_translate_map_get_size(char *map, t_cub3d *cub)
{
	int				idx;
	int				wid;
	int				hei;

	idx = 0;
	wid = 0;
	hei = 0;
	while (map[idx] != '\n')
	{
		if (!ft_util_is_empty(map[idx]))
			++wid;
		++idx;
	}
	cub->map->wid = wid;
	while (map[idx] != '\0')
	{
		if (map[idx] == '\n')
			++hei;
		++idx;
		if (map[idx] == '\0' && (idx > 0 && map[idx - 1] != '\n'))
			++hei;
	}
	cub->map->hei = hei;
}

char				**ft_translate_map_malloc(t_cub3d *cub)
{
	int				idx;
	char			**map;

	if (!(map = (char **)malloc(sizeof(char *) * cub->map->hei)))
		ft_tool_exit(1, cub, 1, "Sorry! Problem occurred during map malloc...");
	ft_util_bzero(map, sizeof(char *) * cub->map->hei);
	idx = 0;
	while (idx < cub->map->hei)
	{
		if (!(map[idx] = (char *)malloc(sizeof(char) * cub->map->wid)))
			ft_tool_exit(1, cub, 1,
				"Sorry! Problem occurred during map line malloc...");
		ft_util_bzero(map[idx], sizeof(char) * cub->map->wid);
		++idx;
	}
	return (map);
}

char				**ft_translate_map_init(char *str, char **map, t_cub3d *cub)
{
	int				cur;
	int				idx;
	int				jdx;

	idx = 0;
	jdx = 0;
	while (idx < cub->map->hei)
	{
		cur = 0;
		while (str[jdx] && str[jdx] != '\n')
		{
			if (!ft_util_is_empty(str[jdx]))
				map[idx][cur++] = str[jdx];
			if (str[jdx] == 'N' || str[jdx] == 'S' ||
				str[jdx] == 'W' || str[jdx] == 'E')
			{
				ft_player_set_start(cub, str[jdx], cur, idx);
				map[idx][cur - 1] = '0';
			}
			++jdx;
		}
		map[idx++][cur] = '\0';
		jdx += 1;
	}
	return (map);
}

int					ft_translate_map_check(t_cub3d *cub, char **map)
{
	int				xdx;
	int				ydx;

	if (!*map || !**map)
		return (0);
	ydx = 0;
	while (ydx < cub->map->hei)
	{
		xdx = 0;
		if (ft_util_strlen(map[ydx]) != (size_t)cub->map->wid)
			return (0);
		while (xdx < cub->map->wid)
		{
			if ((ydx == 0 && map[ydx][xdx] != '1') ||
				(ydx == cub->map->hei - 1 && map[ydx][xdx] != '1') ||
				(xdx == 0 && map[ydx][xdx] != '1') ||
				(xdx == cub->map->wid - 1 && map[ydx][xdx] != '1') ||
				(map[ydx][xdx] != '0' && map[ydx][xdx] != '1' &&
					map[ydx][xdx] != '2' && map[ydx][xdx] != '3'))
				return (0);
			++xdx;
		}
		++ydx;
	}
	return (1);
}
