/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_metrics.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 22:00:25 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/19 22:00:46 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	total_pairs;
	int		i;
	int		j;

	if (a->len < 2)
		return (0.0);
	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < a->len - 1)
	{
		j = i + 1;
		while (j < a->len)
		{
			total_pairs++;
			if (a->arr[i] > a->arr[j])
				mistakes++;
			j++;
		}
		i++;
	}
	return ((double)mistakes / (double)total_pairs);
}

void	index_stack(t_ps *ps)
{
	int	*indexed;
	int	i;
	int	j;
	int	rank;

	indexed = malloc(sizeof(int) * ps->a.len);
	if (!indexed)
		free_and_exit(ps, NULL, 1);
	i = 0;
	while (i < ps->a.len)
	{
		rank = 0;
		j = 0;
		while (j < ps->a.len)
		{
			if (ps->a.arr[j] < ps->a.arr[i])
				rank++;
			j++;
		}
		indexed[i] = rank;
		i++;
	}
	free(ps->a.arr);
	ps->a.arr = indexed;
}
