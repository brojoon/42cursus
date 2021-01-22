/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:15:20 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/23 07:26:39 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_width(const char **format, va_list ap)
{
	int cnt;
	
	if (**format == '*')
	{
		++(*format);
		return(va_arg(ap, int));
	}
	while (**format == '0')
		++(*format);
	cnt = ft_atoi(*format);
	while (ft_isdigit(**format))
		++(*format);
	return (cnt);
}

int		find_case(char c)
{
	if (c == '-' || c == '0')
		return (FLAGE);
	else if (c == '*' || ft_isdigit(c))
		return (WIDTH);
	else if (c == '.')
		return (PRECISION);
	else if (c == 'c' || c == 's' || c == 'd' || c == 'i' || \
	c == 'u' || c == 'x' || c == 'X' || c == 'p' || c == '%' )
		return (PRINT);
	return (0);
}

void	add_option(const char **format, va_list ap, t_option *ot)
{
	if (**format == '-')
	{
		ot->sort = LEFT;
		(*format)++;
	}
	else if (**format == '0' && ot->sort != LEFT)
	{
		ot->sort = RIGHT;
		(*format)++;	
	}
	else if (**format == '*' || ft_isdigit(**format))
	{
		ot->width = set_width(format, ap);
		if (ot->width < 0)
		{
			ot->width *= -1;
			ot->sort = LEFT;
		}	
	}
	else
	{
		++(*format);
		if (**format == '*' || ft_isdigit(**format))
			ot->precision = set_width(format, ap);
		else
			ot->precision = FALSE;
		if (ot->precision < 0)
			ot->precision = DISABLE;
	}
}

int		print_case(const char **format, va_list ap, t_option *ot)
{
	int cnt;

	cnt = 0;
	if (**format == 'c')
		cnt = print_char(ap, ot);
	else if (**format == 's')
		cnt = print_string(ap, ot);
	else if (**format == 'd' || **format == 'i')
		cnt = print_int(ap, ot);
	else if (**format == 'u')
		cnt = print_uint(ap, ot);
	else if (**format == 'x' || **format == 'X')
		cnt = print_hex(ap, ot, (**format == 'x' ? LOWER : UPPER));
	else if (**format == 'p')
		cnt = print_pointer(ap, ot);
	else if (**format == '%')
		cnt = print_percent(ot);
	(*format)++;
	return (cnt);
}

int		print_control(const char **format, va_list ap)
{
	int		cnt;
	int		state;
	t_option ot;

	clear_ot(&ot);
	state = 0;
	cnt = 0;
	(*format)++;
	while (**format)
	{
		if (!(find_case(**format)))
			break ;
		if (state > find_case(**format))
			clear_ot(&ot);
		state = find_case(**format);
		if (state == PRINT)
		{
			cnt += print_case(format, ap, &ot);
			break ;
		}
		else
			add_option(format, ap, &ot);
	}
	return (cnt);
}	