/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:32:36 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/23 07:14:24 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_percent(t_option *ot)
{
	int cnt;

	cnt = 1;
	if (ot->sort != LEFT)
		cnt += print_width(ot, 1);
	ft_putchar_fd('%', 1);
	if (ot->sort == LEFT)
		cnt += print_width(ot, 1);
	return (cnt);
}

int		print_string(va_list ap, t_option *ot)
{
	int		cnt;
	int		len;
	int		idx;
	char	*str1;
	
	str1 = (char *)va_arg(ap, char *);
	if (str1 == NULL)
		str1 = "(null)";
	len = ft_strlen(str1);
	cnt = 0;
	if (ot->precision != DISABLE)
		len = (len > ot->precision) ? ot->precision : len;
	if (ot->sort != LEFT)
		cnt += print_width(ot, len);
	idx = - 1;
	while (++idx < len)
		ft_putchar_fd(str1[idx], 1);
	cnt += len;
	if (ot->sort == LEFT)
		cnt += print_width(ot, len); 
	return (cnt);	
}

int		print_char(va_list ap, t_option *ot)
{
	int cnt;
	
	cnt = 1;
	if (ot->sort != LEFT)
		cnt += print_width(ot, 1);
	ft_putchar_fd((char)va_arg(ap, int), 1);
	if (ot->sort== LEFT)
		cnt += print_width(ot, 1);
	return (cnt);
}