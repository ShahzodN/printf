/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:54:14 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 22:54:16 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*con_s;

	con_s = (unsigned char *)s;
	while (n--)
		if (*con_s++ == (unsigned char)c)
			return (con_s - 1);
	return (NULL);
}
