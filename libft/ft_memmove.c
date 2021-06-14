/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:54:53 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 22:54:55 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*con_dest;
	unsigned char	*con_src;

	con_dest = (unsigned char *)dest;
	con_src = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	if (con_dest < con_src)
		while (n--)
			*con_dest++ = *con_src++;
	else
	{
		con_dest += n;
		con_src += n;
		while (n--)
			*--con_dest = *--con_src;
	}
	return (dest);
}
