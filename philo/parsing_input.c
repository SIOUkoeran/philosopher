/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:29:06 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/02 20:55:00 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	parsing_input(char **argv, t_input *info)
{
	info->philosophers = atoi(*argv++);
	info->forks = info->philosophers;
	info->time_to_die = atoi(*argv++);
	info->time_to_sleep = atoi(*argv++);
	info->numbers_of_time_eat = atoi(*argv);
	info->is_optional = 0;
	if (!info->philosophers || !info->time_to_die)
		return (1);
	if (!info->numbers_of_time_eat || !info->time_to_sleep)
		return (1);
	return (0);
}

int parsing_input_when_6(char **argv, t_input *info)
{
	info->philosophers = atoi(*argv++);
	info->forks = info->philosophers;
	info->time_to_die = atoi(*argv++);
	info->time_to_sleep = atoi(*argv++);
	info->numbers_of_time_eat = atoi(*argv++);
	info->number_of_times_each_philosopher_must_eat = atoi(*argv);
	info->is_optional = 1;
	if (!info->philosophers || !info->time_to_die)
		return (1);
	if (!info->numbers_of_time_eat || !info->time_to_sleep)
		return (1);
	if (!info->number_of_times_each_philosopher_must_eat)
		return (1);
	return (0);
}