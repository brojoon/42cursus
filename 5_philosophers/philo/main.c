/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:55:47 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 07:55:48 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */



#include "main.h"

t_info *g_info;

void	*philo_thread(void *arg)
{
	int			lf;
	int			rf;
	t_philo		*philo;

	philo = arg;
	lf = (philo->num % 2 ? philo->num : philo->num + 1) % g_info->philo_count;
	rf = (philo->num % 2 ? philo->num + 1 : philo->num) % g_info->philo_count;
	while (!g_info->end)
	{
		pickup_fork(lf, philo->num);
		pickup_fork(rf, philo->num);
		philo->state = STATE_EAT;
		print_log(philo->num, LOG_EAT);
		ft_sleep(g_info->time_to_eat);
		philo->last_eat = get_timestamp();
		philo->time_eat++;
		return_fork(lf);
		return_fork(rf);
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
	pthread_t	*tids;
	pthread_t	monitor_tid;

	set_philos();
	tids = malloc(sizeof(pthread_t) * (g_info->philo_count + 1));
	init_mutexs(g_info->philo_count);
	i = -1;
	while (++i < g_info->philo_count)
	{
		pthread_create(&tids[i], NULL, philo_thread, &g_info->philos[i]);
		pthread_detach(tids[i]);
	}
	pthread_create(&monitor_tid, NULL, monitor_thread, NULL);
	pthread_join(monitor_tid, NULL);
	destroy_mutexs(g_info->philo_count);
	free(g_info->philos);
	free(tids);
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
