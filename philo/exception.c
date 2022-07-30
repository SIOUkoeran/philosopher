/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 17:21:45 by mkim3             #+#    #+#             */
/*   Updated: 2022/07/30 18:55:00 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void io_exception()
{
	printf("input exception");
}

void memory_exception()
{
	printf("memory exception");
}

int	thread_exception()
{
	printf("exception while creating thread");
	return (1);
}