/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:29:06 by mkim3             #+#    #+#             */
/*   Updated: 2022/07/30 18:28:27 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing_input(char **argv, t_input *info)
{
	
	(void) *argv++;
	info->philosophers = atoi(*argv++);
	info->forks = info->philosophers;
	info->time_to_die = atoi(*argv++);
	info->time_to_sleep = atoi(*argv++);
	info->numbers_of_time_eat = atoi(*argv);

	if (!info->philosophers || !info->time_to_die)
		return (1);
	if (!info->numbers_of_time_eat || !info->time_to_sleep)
		return (1);
	return (0);
}