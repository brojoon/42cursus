/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:54:34 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:38:46 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_cub_read_color(char *lin, int chr, int idx, t_cub3d *cub)
{
	int				rgb;
	int				r;
	int				g;
	int				b;
	int				i;

	rgb = 0;
	if (!ft_cub_read_color_check(lin, chr, idx, cub))
		return (0);
	i = idx + 1;
	while (ft_util_is_empty(lin[i]))
		++i;
	if ((r = ft_cub_read_color_get_rgb_sep(r, lin, &i, cub)) == -1 ||
		(g = ft_cub_read_color_get_rgb_sep(g, lin, &i, cub)) == -1 ||
		(b = ft_cub_read_color_get_rgb_sep(b, lin, &i, cub)) == -1)
		ft_tool_exit(1, cub, 1, ft_util_strjoin(
			"your color is wrong!\nPlease check your color line : ", lin));
	rgb = ft_cub_read_color_get_rgb(r, g, b);
	if (chr == 'F')
		cub->clr_floor = rgb;
	else if (chr == 'C')
		cub->clr_ceiling = rgb;
	free(lin);
	return (1);
}

int					ft_cub_read_color_check(char *str, int chr, int idx,
	t_cub3d *cub)
{
	int				i;

	if (!str || str[idx] != chr || !ft_util_is_empty(str[idx + 1]))
		return (0);
	i = idx + 1;
	while (ft_util_is_empty(str[i]))
		++i;
	while (ft_util_is_number(str[i]) || str[i] == ',')
		++i;
	while (ft_util_is_empty(str[i]))
		++i;
	if (str[i] != '\0')
		ft_tool_exit(1, cub, 3, str);
	return (1);
}

int					ft_cub_read_color_get_rgb_sep(int spc, char *lin, int *i,
	t_cub3d *cub)
{
	int				clr;

	clr = ft_util_atoi(&lin[*i]);
	if (clr < 0 || clr > 255)
		return (-1);
	while (ft_util_is_number(lin[*i]))
		*i += 1;
	*i += 1;
	return (clr);
}

int					ft_cub_read_color_get_rgb(int r, int g, int b)
{
	int				rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}
