/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 04:14:52 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/25 04:14:54 by dtarkin          ###   ########.fr       */
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

static void	mod_itoa(int nbr, char *dest)
{
	char		final_res[12];
	long long	n;
	int			digits_count;

	set(&n, nbr, &digits_count);
	ft_bzero(final_res, 12);
	if (n == 0)
		final_res[0] = '0';
	while (n > 0)
	{
		final_res[--digits_count] = n % 10 + '0';
		n = n / 10;
	}
	if (nbr < 0)
		final_res[--digits_count] = '-';
	ft_memccpy(dest, final_res, 0, 12);
}

void	ft_putnbr_fd(int n, int fd)
{
	char	res[12];

	ft_bzero(res, 12);
	mod_itoa(n, res);
	write(fd, res, ft_strlen(res));
}
