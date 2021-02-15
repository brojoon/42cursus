/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_win.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimkwanho <kimkwanho@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 10:54:38 by kimkwanho         #+#    #+#             */
/*   Updated: 2021/02/15 19:54:18 by kimkwanho        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int					ft_cub_read_window_size(char *lin, t_cub3d *cub)
{
	int				idx;

	if (!ft_cub_read_window_size_check(lin))
		ft_tool_exit(1, cub, 1, ft_util_strjoin(
			"window size format is wrong!\nthe line is : ", lin));
	idx = 0;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	++idx;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	cub->wid = ft_util_str_to_int(lin, idx);
	if (cub->wid > 2560)
		cub->wid = 2560;
	while (ft_util_is_number(lin[idx]))
		++idx;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	cub->hei = ft_util_str_to_int(lin, idx);
	if (cub->hei > 1440)
		cub->hei = 1440;
	return (1);
}

/*
**	[space]R [space]1920 [space]1080[space]\n
**	1. skip empty space
**	2. return 0 when lin is something wrong
**		or first char of the line isn't 'R' or next char isn't ' '
**	-. we have checked: "[space]R "
**	3. skip empty space
**	4. return 0 when current char is not number
**	5. skip numbers (you don't put numbers on t_cub3d on this part)
**	6. return 0 when there isn't empty space after first char
**	7. skip spaces
**	8. skip second numbers
**	9. skip next spaces
**	10. return 0 when space is not empty or is not the end
**	11. return 1
*/

int					ft_cub_read_window_size_check(char *lin)
{
	int				idx;

	idx = 0;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	if (!lin || lin[idx] != 'R' || lin[idx + 1] != ' ')
		return (0);
	++idx;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	if (!ft_util_is_number(lin[idx]))
		return (0);
	while (ft_util_is_number(lin[idx]))
		++idx;
	if (!ft_util_is_empty(lin[idx]))
		return (0);
	while (ft_util_is_empty(lin[idx]))
		++idx;
	while (ft_util_is_number(lin[idx]))
		++idx;
	while (ft_util_is_empty(lin[idx]))
		++idx;
	if (!ft_util_is_empty(lin[idx]) && lin[idx] != '\0')
		return (0);
	return (1);
}
