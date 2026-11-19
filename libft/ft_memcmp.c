/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/29 00:15:52 by alavryk           #+#    #+#             */
/*   Updated: 2026/09/29 00:24:33 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1u;
	const unsigned char	*s2u;

	s1u = (const unsigned char *)s1;
	s2u = (const unsigned char *)s2;
	while (n-- > 0)
	{
		if (*s1u != *s2u)
			return (*s1u - *s2u);
		s1u++;
		s2u++;
	}
	return (0);
}
