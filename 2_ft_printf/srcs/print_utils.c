/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:16:13 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/24 10:07:38 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_width(t_option *ot, int len)
{
	int		print_len;

	if (ot->width <= len)
		return (0);
	print_len = ot->width - len;
	while (print_len--)
		ft_putchar_fd((ot->sort == RIGHT ? '0' : ' '), 1);
	return (ot->width - len);
}

void	clear_ot(t_option *ot)
{
	ot->precision = DISABLE;
	ot->sort = FALSE;
	ot->width = FALSE;
	ot->sign = FALSE;
}

void	skip_blank(const char **format, int *cnt)
{
	while (**format == '\t' || **format == '\v' || **format == '\f' \
			|| **format == '\r' || **format == '\n' || **format == ' ')
			{
				ft_putchar_fd(**format, 1);
				(*format)++;
				(*cnt)++;
			}
}
