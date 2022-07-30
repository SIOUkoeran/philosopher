/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_philosopher.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:30:18 by mkim3             #+#    #+#             */
/*   Updated: 2022/07/30 19:10:28 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	ft_philosopher(t_philosopher *philosophers)
{
	
	while (philosophers++)
	{
		philosophers->left = gettimeofday();
		philosophers->right = gettimeofday();
	}
}

int ft_create_philosopher(t_thread *thread_array, t_input info)
{
	int	idx;
	t_philosopher *philosophers;

	philosophers = malloc(sizeof(t_philosopher) * (info.philosophers + 1));
	if (!philosophers)
		return thread_exception();
	ft_philosopher(philosophers);
	memset(philosophers, 0, info.philosophers);
	idx = -1;
	while (++idx < info.philosophers)
	{
	  if (pthread_create(&thread_array[idx].thread_id, NULL, (void *)&start_philosopher, &thread_array[idx]) == 1)
	  	return (1);
	}
	return (0);
}