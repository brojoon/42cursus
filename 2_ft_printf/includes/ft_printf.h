  
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 08:46:49 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/15 20:02:45 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define DISABLE -1
# define TRUE 1
# define FALSE 0
# define RIGHT 10
# define LEFT 20
# define UPPER 30
# define LOWER 40
# define FLAGE 50
# define WIDTH 60
# define PRECISION 70
# define PRINT 80

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct s_option
{
	int		sign;
	int		sort;
	int		width;
	int		precision;
}				t_option;

int					ft_printf(const char *format, ...);
int					print_control(const char **format, va_list ap);
int					print_case(const char **format, va_list ap, t_option *ot);
void				add_option(const char **format, va_list ap, t_option *ot);
int					find_case(const char **format, int *cnt);
int					set_width(const char **format, va_list ap);
int					get_hex_len(unsigned int n);
unsigned int		get_hex_pow(int n);
void				prinit_hex_num(t_option *ot, unsigned int hex_num, int is_alpha);
int					print_hex(va_list ap, t_option *ot, int is_alpha);
int					get_num_len(int n);
void				print_uint_num(t_option *ot, unsigned int n);
int					right_sort(t_option *ot, int num, int len);
int					print_int(va_list ap, t_option *ot);
int					print_uint(va_list ap, t_option *ot);
int					get_long_hex_len(unsigned long long print);
unsigned long long	get_long_hex_pow(int n);
int					add_width_two(t_option *ot, int len);
void				print_long_hex_num(t_option *ot, unsigned long long hex_num);
int					print_pointer(va_list ap, t_option *ot);
int					print_percent(t_option *ot);
int					print_string(va_list ap, t_option *ot);
int					print_char(va_list ap, t_option *ot);
int					print_width(t_option *ot, int len);
void				clear_ot(t_option *ot);
void				skip_blank(const char **format, int *cnt);



#endif