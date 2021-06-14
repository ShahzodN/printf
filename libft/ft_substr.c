/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:57:50 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/26 21:57:53 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*alloc_mem;
	int				i;
	unsigned int	s_len;

	if (!s)
		return (NULL);
	alloc_mem = (char *)ft_calloc(len + 1, sizeof(char));
	if (!alloc_mem)
		return (NULL);
	i = 0;
	s_len = (unsigned int)ft_strlen(s);
	while (len-- && s[start] && start < s_len)
		alloc_mem[i++] = s[start++];
	return (alloc_mem);
}
