/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:54:19 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 07:54:32 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_info *g_info;

void	*philo_thread_monitor(void *arg)
{
	t_philo *philo;

	philo = arg;
	while (!is_philo_death(philo))
	{
		is_must_eat(philo);
		usleep(50);
	}
	return (NULL);
}

void	*philo_thread(t_philo *philo)
{
	pthread_t tid;

	pthread_create(&tid, NULL, philo_thread_monitor, philo);
	pthread_detach(tid);
	while (1)
	{
		is_philo_death(philo);
		pickup_fork(philo->num);
		philo->state = STATE_EAT;
		print_log(philo->num, LOG_EAT);
		ft_sleep(g_info->time_to_eat);
		philo->last_eat = get_timestamp();
		philo->time_eat++;
		return_fork();
		philo->state = STATE_SLEEP;
		print_log(philo->num, LOG_SLEEP);
		ft_sleep(g_info->time_to_sleep);
		philo->state = STATE_THINK;
	}
}

void	set_philos(void)
{
	int				i;
	unsigned long	t;

	i = -1;
	g_info->philos = malloc(sizeof(t_philo) * g_info->philo_count);
	t = get_timestamp();
	while (++i < g_info->philo_count)
	{
		g_info->philos[i].last_eat = t;
		g_info->philos[i].time_eat = 0;
		g_info->philos[i].state = STATE_THINK;
		g_info->philos[i].num = i;
	}
}

void	philo(void)
{
	int			i;
	pid_t		*pids;

	set_philos();
	init_monitor();
	pids = malloc(sizeof(pid_t) * (g_info->philo_count + 3));
	init_sem(g_info->philo_count);
	i = -1;
	while (++i < g_info->philo_count)
	{
		if ((pids[i] = fork()) == 0)
		{
			philo_thread(&g_info->philos[i]);
			exit(1);
		}
	}
	monitor_thread(pids);
	destroy_sem();
	free(g_info->philos);
	free(pids);
}

int		main(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: wrong arguments!\n");
		return (1);
	}
	if (!(g_info = malloc(sizeof(t_info))))
		return (1);
	memset(g_info, 0, sizeof(t_info));
	g_info->philo_count = ft_atoi(argv[1]);
	if (g_info->philo_count < 2)
	{
		printf("Error: wrong philo_number!\n");
		free(g_info);
		return (1);
	}
	g_info->time_to_die = ft_atoi(argv[2]);
	g_info->time_to_eat = ft_atoi(argv[3]);
	g_info->time_to_sleep = ft_atoi(argv[4]);
	g_info->must_eat = argc == 6 ? ft_atoi(argv[5]) : -1;
	g_info->start_time = init_timestamp();
	philo();
	free(g_info);
	return (0);
}
