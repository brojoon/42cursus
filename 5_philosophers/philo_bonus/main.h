/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:54:34 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 07:54:35 by hyungjki         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>
# include <signal.h>
# include <semaphore.h>
# include <fcntl.h>

# define STATE_EAT 0
# define STATE_THINK 1
# define STATE_SLEEP 2

# define LOG_FORK 0
# define LOG_EAT 1
# define LOG_SLEEP 2
# define LOG_THINK 3
# define LOG_DIE 4

typedef struct		s_philo
{
	int				time_eat;
	unsigned long	last_eat;
	int				state;
	int				num;
}					t_philo;

typedef struct		s_info
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	unsigned long	start_time;
	t_philo			*philos;
	sem_t			*sem_forks;
	sem_t			*sem_lock;
	sem_t			*sem_end;
	sem_t			*sem_stop;
}					t_info;

extern				t_info *g_info;

unsigned long		get_timestamp(void);
unsigned long		init_timestamp(void);
int					ft_atoi(const char *str);
void				ft_sleep(int milis);
void				init_sem(int fork_count);
void				pickup_fork(int philo);
void				return_fork(void);
void				destroy_sem(void);
void				print_log(int n, int type);
void				monitor_thread(pid_t *pids);
void				*philo_thread_monitor(void *arg);
int					is_philo_death(t_philo *philo);
void				is_must_eat(t_philo *philo);

#endif