/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:54:00 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 22:54:04 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*con_src;
	unsigned char	*con_dest;

	con_src = (unsigned char *)src;
	con_dest = (unsigned char *)dest;
	while (n--)
	{
		*con_dest++ = *con_src++;
		if (*(con_src - 1) == (unsigned char)c)
			return (con_dest);
	}
	return (NULL);
}
