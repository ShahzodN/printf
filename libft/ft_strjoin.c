/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 04:15:27 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/25 04:15:28 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*alloc_mem;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	alloc_mem = ft_calloc(len, sizeof(char));
	if (alloc_mem == NULL)
		return (NULL);
	alloc_mem = ft_memcpy(alloc_mem, s1, ft_strlen(s1));
	ft_strlcat(alloc_mem, s2, len);
	return (alloc_mem);
}
