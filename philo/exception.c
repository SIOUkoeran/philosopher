/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:21:45 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/02 18:48:15 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void io_exception()
{
	printf("\ninput exception\n");
}

void memory_exception()
{
	printf("\nmemory exception\n");
}

int	thread_exception()
{
	printf("\nexception while creating thread\n");
	return (1);
}

int join_thread_exception()
{
	printf("\nexception while waiting for joining thread\n");
	return (-1);
}

int	mutex_exception(t_thread *thread_array)
{
	printf("\nexception while initializing mutex\n");
	while (thread_array)
	{
		free(thread_array);
		thread_array++;
	}
	return (-1);
}

int		thread_in_fork_exception()
{
	printf("\nexception while creating forks\n");
	return (-1);
}