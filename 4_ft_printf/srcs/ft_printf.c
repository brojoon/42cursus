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

int		print_control(const char **format, va_list ap)
{
	int		cnt;
	int		statep;
	t_flag	*flag;

	flag = new_flag();
	(*format)++;
	while (**format)
	{
		
	}
	free (flag);
	return (cnt);
}	

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
			write(1, *(format++), 1);
			cnt++;
		}
	}
	va_end(ap);
	return (cnt);
}