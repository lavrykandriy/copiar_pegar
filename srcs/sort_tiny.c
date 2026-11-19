/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 23:10:11 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/19 23:10:28 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->len - 1)
	{
		if (a->arr[i] > a->arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	find_min_pos(t_stack *s)
{
	int	min_pos;
	int	i;

	min_pos = 0;
	i = 1;
	while (i < s->len)
	{
		if (s->arr[i] < s->arr[min_pos])
			min_pos = i;
		i++;
	}
	return (min_pos);
}

void	move_pos_to_top_a(t_ps *ps, int pos)
{
	int	steps;

	if (pos <= ps->a.len / 2)
	{
		while (pos-- > 0)
			exec_op(ps, OP_RA, 1);
	}
	else
	{
		steps = ps->a.len - pos;
		while (steps-- > 0)
			exec_op(ps, OP_RRA, 1);
	}
}

void	sort_three(t_ps *ps)
{
	int	*a;

	if (ps->a.len != 3 || is_sorted(&ps->a))
		return ;
	a = ps->a.arr;
	if (a[0] > a[1] && a[1] < a[2] && a[0] < a[2])
		exec_op(ps, OP_SA, 1);
	else if (a[0] > a[1] && a[1] > a[2])
	{
		exec_op(ps, OP_SA, 1);
		exec_op(ps, OP_RRA, 1);
	}
	else if (a[0] > a[1] && a[1] < a[2] && a[0] > a[2])
		exec_op(ps, OP_RA, 1);
	else if (a[0] < a[1] && a[1] > a[2] && a[0] < a[2])
	{
		exec_op(ps, OP_SA, 1);
		exec_op(ps, OP_RA, 1);
	}
	else
		exec_op(ps, OP_RRA, 1);
}
