/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:33:30 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/03 22:49:28 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void ft_printf_thinking_philosopher(t_philosopher *philosopher)
{
	printf("%dms %d %s\n", ft_get_time(philosopher->info.start_time), philosopher->num, THINK);
	usleep(200);
}

static int ft_printf_sleep_philosopher(t_philosopher *philosopher)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	printf("%dms %d %s\n", ft_get_time(philosopher->info.start_time), philosopher->num, SLEEP);
	while (ft_get_time(time) < philosopher->info.numbers_of_time_eat)
				usleep(200);
	return (1);
}

static int ft_printf_eat_philosopher(t_philosopher *philosopher)
{
	struct timeval time;
	
	int	left_result = 1;
	int	right_result = 1;
	left_result = pthread_mutex_lock(&(philosopher->left->mutex));
	if (left_result == 0){
		printf("%dms %d %s\n", ft_get_time(philosopher->info.start_time), philosopher->num, FORK);
		right_result = pthread_mutex_lock(&(philosopher->right->mutex));
		if (right_result == 0){
			pthread_mutex_lock(&(philosopher->limit_mutex));
			gettimeofday(&(philosopher->limit), NULL);
			pthread_mutex_unlock(&(philosopher->limit_mutex));
			printf("%dms %d %s\n", ft_get_time(philosopher->info.start_time), philosopher->num, FORK);
			printf("%dms %d %s\n", ft_get_time(philosopher->info.start_time), philosopher->num, EAT);
			pthread_mutex_lock(&(philosopher->eat_mutex));
			philosopher->eat_cnt = philosopher->eat_cnt + 1;
			pthread_mutex_unlock(&(philosopher->eat_mutex));
			gettimeofday(&time, NULL);
			while (ft_get_time(time) < philosopher->info.numbers_of_time_eat)
				usleep(200);
			pthread_mutex_unlock(&(philosopher->right->mutex));
			pthread_mutex_unlock(&(philosopher->left->mutex));
		}
	}
	return (left_result == 0 && right_result == 0);
}

void start_philosopher(void *arg)
{
	t_philosopher *philosopher;

	philosopher = (t_philosopher *) arg;
	gettimeofday(&(philosopher->limit), NULL);
	while (1)
	{
		if (ft_printf_eat_philosopher(philosopher))
			ft_printf_sleep_philosopher(philosopher);
		ft_printf_thinking_philosopher(philosopher);
		if (ft_get_time(philosopher->limit) >= philosopher->info.time_to_die)
		{
			while (1)
			{
			}
		}
			
	}
}