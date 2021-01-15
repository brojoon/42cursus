/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 08:46:49 by hyungjki          #+#    #+#             */
/*   Updated: 2021/01/09 00:54:48 by hyungjki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define TRUE 1
# define FALSE 0

typedef struct s_flag
{
	int		sign;
	int		sort;
	int		width;
	int		precision;
}				t_flag;

int				ft_printf(const char *format, ...);
int				print_control(const char **format, va_list ap);

#endif