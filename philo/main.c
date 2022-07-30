/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:20:59 by mkim3             #+#    #+#             */
/*   Updated: 2022/07/30 18:55:20 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_input_parsing(int argc, char **argv, t_input *info)
{
	if (argc != 5)
	{
		io_exception();
		return (1);
	}
	if (parsing_input(argv, info) == 1)
	{
		memory_exception();
		return (1);
	}
	return (0);
}

int main(int argc, char **argv){
	t_thread *thread_array;
	t_input info;
	
	if (ft_input_parsing(argc, argv, &info) == 1)
		return (1);
	
	thread_array = linked_list_init(argc);
	if (!thread_array)
		return (0);
	if (ft_create_philosopher(thread_array, info) == 1)
		return thread_exception();
	printf("done");
	return (0);
}