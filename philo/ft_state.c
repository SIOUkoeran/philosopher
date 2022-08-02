/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:38:07 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/02 20:41:01 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void ft_thread_state(void* arg)
{ 
	t_philosopher 	*philosopher;
	int 			idx;
	
	philosopher = (t_philosopher *) arg;
	idx = -1;
	while (1)
	{
		while (++idx < philosopher->info.forks)
		{
			if (philosopher[idx].limit > philosopher->info.time_to_die)
			{
				
			}
		}
	}
}