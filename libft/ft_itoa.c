/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 04:13:47 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/25 04:13:49 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	set(long long *n, int nbr, int *digits_count)
{
	unsigned int	b;

	*digits_count = 0;
	*n = nbr;
	if (*n <= 0)
	{
		*n *= -1;
		*digits_count += 1;
	}
	b = *n;
	while (b != 0)
	{
		b /= 10;
		*digits_count += 1;
	}
}

char	*ft_itoa(int nbr)
{
	char		*final_res;
	long long	n;
	int			digits_count;

	set(&n, nbr, &digits_count);
	final_res = (char *)ft_calloc(digits_count + 1, sizeof(char));
	if (!final_res)
		return (NULL);
	if (n == 0)
	{
		final_res[0] = '0';
		return (final_res);
	}
	while (n > 0)
	{
		final_res[--digits_count] = n % 10 + '0';
		n = n / 10;
	}
	if (nbr < 0)
		final_res[--digits_count] = '-';
	return (final_res);
}
