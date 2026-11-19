/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 20:23:53 by alavryk           #+#    #+#             */
/*   Updated: 2026/09/29 21:40:42 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*p_big;
	const char	*p_lit;
	size_t		rem;

	if (!*little)
		return ((char *)big);
	while (*big && len)
	{
		p_big = big;
		p_lit = little;
		rem = len;
		while (*p_big && *p_big == *p_lit && rem && *p_lit)
		{
			p_big++;
			p_lit++;
			rem--;
		}
		if (!*p_lit)
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
