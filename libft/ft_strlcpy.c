/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 20:25:24 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 20:25:33 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*con_src;

	if (!dest || !src)
		return (0);
	con_src = (char *)src;
	if (size > 0)
	{
		while (size-- > 1 && *con_src != 0)
			*dest++ = *con_src++;
		*dest = 0;
	}
	return (ft_strlen(src));
}
