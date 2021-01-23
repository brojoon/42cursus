/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 02:16:09 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/24 05:18:41 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_num_len(int n)
{
	return ((-10 < n && n < 10) ? 1 : 1 + get_num_len(n / 10));
}

void	print_uint_num(t_option *ot, unsigned int n)
{
	if (n == 0 && ot->precision == FALSE)
	{
		if (ot->width)
			ft_putchar_fd(' ', 1);
		return ;
	}
	ft_putnbr_fd(n, 1);
}

int		right_sort(t_option *ot, int num, int len)
{
	if (ot->sort && num < 0)
		ft_putchar_fd('-', 1);
	if (ot->precision != DISABLE)
		ot->sort = FALSE;
	return (print_width(ot, len + ((num < 0 ) ? 1 : 0)));
}

int		print_int(va_list ap, t_option *ot)
{
	int		cnt;
	int		num;
	int		len;
	
	num = va_arg(ap, int);
	ot->sort = (num < 0 && ot->sort == RIGHT && ot->precision != DISABLE) ? FALSE : ot->sort;
	cnt = (num < 0) ? 1 : 0;
	len = get_num_len(num);
	len = ((ot->precision > len ) ? ot->precision : len);
	cnt += len;
	if (ot->sort != LEFT)
		cnt += right_sort(ot, num, len);
	if (ot->sort != RIGHT && (num < 0))
		ft_putchar_fd('-', 1);
	while (len > get_num_len(num) && (len--))
		ft_putchar_fd('0', 1);
	print_uint_num(ot, (num < 0) ? -1 * num : num);
	len = ((ot->precision > len) ? ot->precision : len);
	if (ot->sort == LEFT)
		cnt += print_width(ot, len + ((num < 0) ? 1 : 0));
	return (cnt - ((num || ot->precision || ot->width ) ? 0 : 1));
}

int		print_uint(va_list ap, t_option *ot)
{
	int				cnt;
	unsigned int	num;
	int				len;
	int				ulen;
	
	num = va_arg(ap, unsigned int);
	ulen = (num >= 1000000000) ? 10 : get_num_len(num); 
	len = ((ot->precision > ulen) ? ot->precision : ulen);
	cnt = len;
	if (ot->sort != LEFT)
	{
		if (ot->precision != DISABLE)
			ot->sort = FALSE;
		cnt += print_width(ot, len);
	}
	while (len > ulen && (len--))
		ft_putchar_fd('0', 1);
	print_uint_num(ot, num);
	len = ((ot->precision > len) ? ot->precision : len);
	if (ot->sort == LEFT)
		cnt += print_width(ot, len);
	return (cnt - ((num || ot->precision || ot->width ) ? 0 : 1));
	
}

