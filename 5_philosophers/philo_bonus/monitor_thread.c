/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:54:09 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 07:54:13 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		is_philo_death(t_philo *philo)
{
	int i;

	if((int)(get_timestamp() - philo->last_eat) >= g_info->time_to_die)
	{
		print_log(philo->num, LOG_DIE);
		sem_post(g_info->sem_end);
		i = 0;
		while (i++ < g_info->philo_count)
			sem_post(g_info->sem_stop);
		return (1);
	}
	return (0);
}

void	is_must_eat(t_philo *philo)
{
	if (g_info->must_eat != -1 && philo->time_eat >= \
		g_info->must_eat)
	{
		sem_post(g_info->sem_stop);	
	}
}

void	*monitor_count_thread(void *arg)
{
	int i;

	i = (int)arg;
	i = 0;
	while (i++ < g_info->philo_count)
		sem_wait(g_info->sem_stop);
	sem_post(g_info->sem_end);
}

void	init_monitor(void)
{
	sem_unlink("check_die");
	g_info->sem_end = sem_open("check_die", O_CREAT, S_IRWXU, 0);
	sem_unlink("check_count");
	g_info->sem_stop = sem_open("check_count", O_CREAT, S_IRWXU, 0);
}

void	monitor_thread(pid_t *pids)
{
	pthread_t	tid;
	int			i;

	pthread_create(&tid, NULL, monitor_count_thread, NULL);
	pthread_detach(tid);
	sem_wait(g_info->sem_end);
	i = -1;
	while (++i < g_info->philo_count)
		kill(pids[i], SIGKILL);
	sem_close(g_info->sem_end);
	sem_close(g_info->sem_stop);
}