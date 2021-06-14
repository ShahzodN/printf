/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 22:57:09 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/22 22:57:10 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s) - 1;
	if (c == 0)
		return ((char *)&s[i + 1]);
	while (i >= 0)
		if (s[i--] == c)
			return ((char *)&s[i + 1]);
	return (NULL);
}
