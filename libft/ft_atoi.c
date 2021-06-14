/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:44:30 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/26 21:44:34 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	sign;

	number = 0;
	sign = 1;
	while (*str && !ft_isalpha(*str))
	{
		if ((*str < 27 || *str == 32) && str++)
			continue ;
		if (*str == '+')
			str++;
		else if (*str == '-' && str++)
			sign = -1;
		if (!ft_isdigit(*str))
			return (0);
		while (ft_isdigit(*str) && *str)
			number = (number * 10) + (*str++ - '0');
		return (number * sign);
	}
	return (0);
}
