/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:54:43 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 07:54:43 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

static int		ft_isspace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	ft_atoi(const char *str)
{
	int				number;
	unsigned char	*ptr;
	int				sign;

	number = 0;
	sign = 1;
	ptr = (unsigned char *)str;
	while (ft_isspace(*ptr))
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (*ptr >= '0' && *ptr <= '9')
		number = number * 10 + *ptr++ - '0';
	return (number * sign);
}

unsigned long	init_timestamp(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

unsigned long	get_timestamp()
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000 + tv.tv_usec / 1000) - g_info->start_time);
}

void	print_log(int n, int type)
{
	if (type == LOG_FORK)
		printf("[%10lums] %2d has taken a fork\n", get_timestamp(), n + 1);
	else if (type == LOG_EAT)
		printf("[%10lums] %2d is eating\n", get_timestamp(), n + 1);
	else if (type == LOG_SLEEP)
		printf("[%10lums] %2d is sleeping\n", get_timestamp(), n + 1);
	else if (type == LOG_THINK)
		printf("[%10lums] %2d is thinking\n", get_timestamp(), n + 1);
	else if (type == LOG_DIE)
		printf("[%10lums] %2d died\n", get_timestamp(), n + 1);
}
