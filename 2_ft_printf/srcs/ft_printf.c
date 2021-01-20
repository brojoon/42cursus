
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/09 00:52:02 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/15 21:31:15 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		cnt;

	va_start(ap, format);
	cnt = 0;
	while(*format)
	{
		if (*format == '%')
			cnt += print_control(&format, ap);
		else
		{
			ft_putchar_fd(*(format++), 1);
			cnt++;
		}
	}
	va_end(ap);
	return (cnt);
}