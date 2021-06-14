/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:54:25 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 22:54:27 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*con_s1;
	unsigned char	*con_s2;

	con_s1 = (unsigned char *)s1;
	con_s2 = (unsigned char *)s2;
	while (n--)
	{
		if (*con_s1++ == *con_s2++)
			continue ;
		return (*(con_s1 - 1) - *(con_s2 - 1));
	}
	return (0);
}
