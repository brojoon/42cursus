/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:55:26 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 07:56:25 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		is_philo_death(void)
{
	int i;

	i = 0;
	while (i < g_info->philo_count)
	{
		if ((int)(get_timestamp() - g_info->philos[i].last_eat) >= g_info->time_to_die)
			return (i);
		i++;
	}
	return (-1);
}

int		is_must_eat()
{
	int i;

	if (g_info->must_eat == -1)
		return (0);
	i = 0;
	while (i < g_info->philo_count)
	{
		if (g_info->philos[i].time_eat < g_info->must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_thread(void *arg)
{
	int n;

	n = (int)arg;
	while (1)
	{
		if ((n = is_philo_death()) != -1)
		{
			print_log(n, LOG_DIE);
			break;
		}
		if (is_must_eat())
			break;
		usleep(5000);
	}
	g_info->end = 1;
	usleep(1000);
}

void	ft_sleep(int milis)
{
	unsigned long	start_time;

	start_time = get_timestamp();
	while (get_timestamp() - start_time < (unsigned long)milis)
		usleep(100);
}
