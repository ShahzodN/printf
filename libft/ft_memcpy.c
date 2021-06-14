/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:54:39 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 22:54:41 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*con_dest;
	unsigned char	*con_src;

	if (!dest && !src)
		return (NULL);
	con_dest = (unsigned char *)dest;
	con_src = (unsigned char *)src;
	while (n--)
		*con_dest++ = *con_src ++;
	return (dest);
}
