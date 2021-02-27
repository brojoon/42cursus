/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_identifier_util.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 17:24:07 by hyungjki          #+#    #+#             */
/*   Updated: 2021/02/27 19:55:44 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char		*ft_recup_root(char *line, int i)
{
	char		**tmp;
	char		*ret;

	i = 0;
	if (!(tmp = ft_split(line, ' ')))
		ft_exit("Error recup_root func split", -1);
	if (!(ret = ft_strdup(tmp[1])) && ret[i] != '.' && ret[i + 1] != '/')
		ft_exit("Error recup_root func strdup", -1);
	if (tmp[2])
		ft_exit("Error wRong .cub", -1);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp[i]);
	free(tmp);
	return (ret);
}

int			ft_recup_color(char *line, int i)
{
	int			color;

	i = 1;
	ft_space(line, &i);
	color = ft_rgb_color(line, &i) * 65536;
	color += ft_rgb_color(line, &i) * 256;
	if (ft_atoi(&line[i]) < 0 || ft_atoi(&line[i]) > 255)
		ft_exit("Error recup_color atoi", -1);
	color += ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	ft_space(line, &i);
	if (line[i])
		ft_exit("Error wrong .cub", -1);
	return (color);
}

void		ft_recup_axes(t_env *e, char *line)
{
	int			i;

	i = 0;
	ft_space(line, &i);
	i++;
	e->window.x = ft_atoi(&line[i]);
	ft_space(line, &i);
	while (ft_isdigit(line[i]))
		i++;
	e->window.y = ft_atoi(&line[i]);
	ft_space(line, &i);
	while (ft_isdigit(line[i]))
		i++;
	ft_space(line, &i);
	if (line[i])
		ft_exit("Error wrong .cub", -1);
}

void		ft_recup_map(char *line, t_env *e)
{
	e->raycasting.y++;
	if (!e->map.buff)
		e->map.buff = ft_strdup("");
	else
		e->map.buff = ft_strjoin(e->map.buff, "\n", 1);
	e->map.buff = ft_strjoin(e->map.buff, line, 1);
}

void		ft_map_fill(t_env *e, char **tmp)
{
	int		i;
	int		j;

	i = -1;
	while (++i < e->raycasting.y)
	{
		j = 0;
		while (e->map.tab_map[i][j] && j < e->raycasting.x)
		{
			if (e->map.tab_map[i][j] != ' ')
				tmp[i][j] = e->map.tab_map[i][j];
			else
				tmp[i][j] = 'X';
			j++;
		}
		while (j < e->raycasting.x)
			tmp[i][j++] = 'X';
	}
}
