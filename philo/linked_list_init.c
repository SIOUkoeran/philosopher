/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:05:54 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/02 18:16:18 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_thread	*linked_list_init(int n)
{
	t_thread *thread_array;

	thread_array = malloc(sizeof(t_thread) * (n + 1));
	if (!thread_array)
	{
		memory_exception();
		return (NULL);
	}
	memset(thread_array, 0,n);
	return (thread_array);
}
