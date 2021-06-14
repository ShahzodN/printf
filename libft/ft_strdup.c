/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:55:36 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 22:55:38 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*block;
	size_t	length;

	length = ft_strlen(s);
	block = malloc(sizeof(char) * length + 1);
	if (block == 0)
		return (0);
	ft_bzero(block, length + 1);
	ft_memcpy(block, s, length);
	return (block);
}
