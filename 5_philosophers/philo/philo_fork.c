/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:55:37 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 07:56:28 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */


#include "main.h"

void	init_mutexs(int fork_count)
{
	int	i;

	i = 0;
	g_info->mutexes = malloc(sizeof(pthread_mutex_t) * fork_count);
	while (i < fork_count)
	{
		pthread_mutex_init(&g_info->mutexes[i], NULL);
		i++;
	}
	return ;
}

void	pickup_fork(int n, int philo)
{
	pthread_mutex_lock(&g_info->mutexes[n]);
	print_log(philo, LOG_FORK);
}

void	return_fork(int n)
{
	pthread_mutex_unlock(&g_info->mutexes[n]);
}

void	destroy_mutexs(int fork_count)
{
	int	i;

	i = 0;
	while (i < fork_count)
	{
		pthread_mutex_destroy(&g_info->mutexes[i]);
		i++;
	}
	free(g_info->mutexes);
}
