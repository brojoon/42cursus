/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:28:10 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:51:19 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_cub_read_path(char *lin, t_num *num, int idx,
	t_cub3d *cub)
{
	char			*pth;
	int				jdx;

	if (!ft_cub_read_path_check(lin))
		ft_tool_exit(1, cub, 1, ft_util_strjoin(
				"something wrong with your path... 1\nthe line is : ", lin));
	jdx = (lin[idx + 1] == ' ') ? idx + 2 : idx + 3;
	while (ft_util_is_empty(lin[jdx]))
		++jdx;
	if (!(pth = ft_util_substr(lin, jdx, ft_util_str_size(lin, jdx))) ||
		!ft_cub_read_path_file_exist(pth))
		ft_tool_exit(1, cub, 1, ft_util_strjoin(
			"something wrong with your path... 2\nthe path is : ", pth));
	if (num->n1 == 'N' && num->n2 == 'O')
		return (ft_texture_set(cub, pth, 0));
	if (num->n1 == 'W' && num->n2 == 'E')
		return (ft_texture_set(cub, pth, 2));
	if (num->n1 == 'S' && num->n2 == 'O')
		return (ft_texture_set(cub, pth, 1));
	if (num->n1 == 'E' && num->n2 == 'A')
		return (ft_texture_set(cub, pth, 3));
	else
		return (ft_cub_read_path_other(cub, num, pth));
}

int					ft_cub_read_path_check(char *l)
{
	int				i;

	i = 0;
	while (ft_util_is_empty(l[i]))
		++i;
	if ((l[i] != 'N' && l[i] != 'S' && l[i] != 'W' && l[i] != 'E' &&
		l[i] != 'P' && l[i] != 'L' && l[i] != 'O') || (l[i + 1] != 'O' &&
		l[i + 1] != 'E' && l[i + 1] != 'A' && l[i + 1] != 'B' &&
		l[i + 1] != 'C' && l[i + 1] != 'D' && l[i + 1] != 'Z' &&
		l[i + 1] != 'G' && !ft_util_is_empty(l[i])))
		return (0);
	i += 2;
	while (ft_util_is_empty(l[i]))
		++i;
	if (l[i] != '.' && l[i + 1] != '/')
		return (0);
	while (ft_util_is_printable(l[i]) && !ft_util_is_empty(l[i]) && l[i] != 0)
		++i;
	if (!ft_util_is_empty(l[i]) && l[i] != '\0')
		return (0);
	while (ft_util_is_empty(l[i]))
		++i;
	return (l[i] != '\0' ? 0 : 1);
}

int					ft_cub_read_path_file_exist(char *pth)
{
	int				fil;
	int				len;

	len = ft_util_strlen(pth);
	if ((fil = open(pth, O_RDONLY)) == -1)
	{
		close(fil);
		return (0);
	}
	if (pth[len - 1] != 'm' || pth[len - 2] != 'p' ||
		pth[len - 3] != 'x' || pth[len - 4] != '.')
		return (0);
	return (1);
}

int					ft_cub_read_path_other(t_cub3d *cub, t_num *num, char *pth)
{
	if (num->n1 == 'S' && num->n2 == 'A')
		return (ft_texture_set(cub, pth, 4));
	if (num->n1 == 'S' && num->n2 == 'B')
		return (ft_texture_set(cub, pth, 5));
	if (num->n1 == 'S' && num->n2 == 'C')
		return (ft_texture_set(cub, pth, 6));
	if (num->n1 == 'S' && num->n2 == 'D')
		return (ft_texture_set(cub, pth, 7));
	if (num->n1 == 'L' && num->n2 == 'G')
		return (ft_texture_set(cub, pth, 8));
	if (num->n1 == 'E' && num->n2 == 'D')
		return (ft_texture_set(cub, pth, 9));
	if (num->n1 == 'E' && num->n2 == 'C')
		return (ft_texture_set(cub, pth, 10));
	if (num->n1 == 'P' && num->n2 == 'Z')
		return (ft_sprites_set(cub, pth));
	return (1);
}
