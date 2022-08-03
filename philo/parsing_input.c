/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 16:29:06 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/03 18:46:31 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_check_param(t_input *info)
{
	if (info->forks <= 0 || info->time_to_die <= 0)
		return (1);
	if (info->time_to_sleep <= 0 || info->numbers_of_time_eat <= 0)
		return (1);
	return (0);
}

int	parsing_input(char **argv, t_input *info)
{
	(void)*argv++;
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
	if (ft_check_param(info) == 1)
		return (1);
	return (0);
}

int parsing_input_when_6(char **argv, t_input *info)
{
	(void) *argv++;
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
	if (ft_check_param(info) == 1)
		return (1);
	return (0);
}