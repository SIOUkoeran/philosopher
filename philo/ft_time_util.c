/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkim3 <mkim3@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 18:43:31 by mkim3             #+#    #+#             */
/*   Updated: 2022/08/02 20:23:02 by mkim3            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_get_time(struct timeval input)
{
	struct timeval 	now;
	int				sec;
	int				usec;
	
	gettimeofday(&now, NULL);
	sec = now.tv_sec - input.tv_sec;
	usec = now.tv_usec - input.tv_usec;
	return ((sec * 1000 + usec / 1000));
}