/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtarkin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 23:43:24 by dtarkin           #+#    #+#             */
/*   Updated: 2021/04/24 23:43:27 by dtarkin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_count(char const *s, int c)
{
	int	i;
	int	count;

	if (*s == 0)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (count == 0 && s[i] != c)
			count++;
		if (s[i] == c && s[i + 1] != c && s[i + 1] != 0)
			count++;
		i++;
	}
	return (count);
}

static int	get_bytes_count(char const *s, int c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != c && s[i])
	{
		count++;
		i++;
	}
	return (count);
}

static void	*free_mem(char **alloc_mem, int str_count)
{
	int	i;

	i = 0;
	while (i < str_count)
	{
		free(alloc_mem[i]);
		i++;
	}
	free(alloc_mem);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		string_count;
	char	**strings;
	int		i;
	int		k;

	if (!s)
		return (NULL);
	string_count = get_count(s, c);
	strings = ft_calloc((string_count + 1), sizeof(char *));
	if (!strings)
		return (NULL);
	i = 0;
	while (i < string_count)
	{
		while (*s == c)
			s++;
		k = get_bytes_count(s, c);
		strings[i] = malloc(sizeof(char) * (k + 1));
		if (!strings[i])
			return (free_mem(strings, i));
		ft_strlcpy(strings[i], s, k + 1);
		s = s + k + 1;
		i++;
	}
	return (strings);
}
