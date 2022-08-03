/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:20:59 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/03 18:21:33 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_input_parsing(int argc, char **argv, t_input *info)
{
	if (argc != 5 && argc != 6)
	{
		io_exception();
		return (1);
	}
	if (argc == 5)
	{
		if (parsing_input(argv, info) == 1)
		{
			memory_exception();
			return (1);
		}
	}
	else if (argc == 6)
	{
		if (parsing_input_when_6(argv, info) == 1)
		{
			printf("here");
			memory_exception();
			return (1);
		}
	}
	return (0);
}

static int ft_join_thread(t_thread *thread_array)
{
	int result;

	while (thread_array++)
	{
		pthread_join(thread_array->thread_id, (void *) &result);
		if (result != 0)
			return join_thread_exception();
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_thread *thread_array;
	t_input info;

	if (ft_input_parsing(argc, argv, &info) == 1)
		return (1);
	thread_array = linked_list_init(argc);
	if (!thread_array)
		return (0);
	if (ft_create_philosopher(thread_array, info) == 1)
		return thread_exception();
	if (pthread_join(thread_array[info.forks].thread_id, NULL) == 0)
		return (0);
	return (0);
}