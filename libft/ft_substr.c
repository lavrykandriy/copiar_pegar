/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/30 23:16:44 by alavryk           #+#    #+#             */
/*   Updated: 2026/09/30 23:50:24 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*res;

	if (!s)
		return (NULL);
	if (len == 0 || start >= ft_strlen(s) || ft_strlen(s) == 0)
		return (ft_strdup(""));
	size = 0;
	while (s[start + size] && size < len)
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	ft_strlcpy(res, &s[start], size + 1);
	return (res);
}
