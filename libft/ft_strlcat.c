/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:29:09 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 22:40:55 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	get_length(char *str, size_t size)
{
	size_t	length;

	length = 0;
	while (*str++ && size--)
		length++;
	return (length);
}

size_t	ft_strlcat(char	*dest, const char *src, size_t size)
{
	size_t	i;
	size_t	length;
	char	*con_src;

	con_src = (char *)src;
	i = 0;
	length = get_length(dest, size) + ft_strlen(src);
	if (size > 0)
	{
		while (dest[i])
		{
			i++;
			continue ;
		}
		while (i < (size - 1) && *con_src)
		{
			dest[i] = *con_src++;
			i++;
		}
		dest[i] = 0;
	}
	return (length);
}
