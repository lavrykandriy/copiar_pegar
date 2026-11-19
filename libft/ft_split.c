/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 00:12:18 by alavryk           #+#    #+#             */
/*   Updated: 2026/10/01 01:35:58 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_word_counter(const char *s, char c)
{
	unsigned int	words;

	words = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			words++;
			while (*s != c && *s)
				s++;
		}
	}
	return (words);
}

static unsigned int	ft_word_len(const char *s, char c)
{
	unsigned int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_all(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	unsigned int	i;

	if (!s)
		return (NULL);
	arr = (char **)ft_calloc(ft_word_counter(s, c) + 1, sizeof(char *));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s != c)
		{
			arr[i] = malloc((ft_word_len(s, c) + 1) * sizeof(char));
			if (!arr[i])
				return (free_all(arr));
			ft_strlcpy(arr[i++], s, ft_word_len(s, c) + 1);
			s = s + ft_word_len(s, c);
		}
		while (*s == c && *s)
			s++;
	}
	return (arr);
}
