/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:38:07 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/03 22:49:16 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_printf_died_philosopher(t_philosopher *philosopher)
{
	printf("%dms %d %s\n", ft_get_time(philosopher->info.start_time), philosopher->num, died);
}

void ft_thread_state(void* arg)
{ 
	t_philosopher 	*philosopher;
	int 			idx;
	int				flag;
	int				idx2;
	int				eat_cnt;

	eat_cnt = 0;
	flag = 0;
	philosopher = (t_philosopher *) arg;
	while (flag == 0)
	{
		idx = -1;

		while (++idx < philosopher->info.philosophers)
		{
			pthread_mutex_lock(&philosopher[idx].limit_mutex); 
			if (ft_get_time(philosopher[idx].limit) >= philosopher->info.time_to_die)
			{
				ft_printf_died_philosopher(&philosopher[idx]);
				flag = 1;
				break ;
			}
			pthread_mutex_unlock(&philosopher[idx].limit_mutex);
			if (philosopher->info.is_optional == 1)
			{
				idx2 = -1;
				while (++idx2 < philosopher->info.philosophers)
				{
					pthread_mutex_lock(&philosopher[idx].eat_mutex);
					if (philosopher[idx2].eat_cnt >= philosopher->info.number_of_times_each_philosopher_must_eat)
						++eat_cnt;
					pthread_mutex_unlock(&philosopher[idx].eat_mutex);
				}
				if (eat_cnt == philosopher->info.philosophers)
					flag = 1;
				eat_cnt = 0;
			}
		}
	}
	return ;
}