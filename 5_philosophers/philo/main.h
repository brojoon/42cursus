/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjki <hyungjki@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 07:54:53 by hyungjki          #+#    #+#             */
/*   Updated: 2021/06/10 07:56:22 by hyungjki         ###   ########lyon.fr   */
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
	pthread_mutex_t *mutexes;
	int				end;
}					t_info;

extern				t_info *g_info;

unsigned long		get_timestamp(void);
unsigned long		init_timestamp(void);
int					ft_atoi(const char *str);
void				ft_sleep(int milis);
void				init_mutexs(int fork_count);
void				pickup_fork(int n, int philo);
void				return_fork(int n);
void				destroy_mutexs(int fork_count);
void				print_log(int n, int type);
void				*monitor_thread();
int					is_philo_death(void);

#endif
