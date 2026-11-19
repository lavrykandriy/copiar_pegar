/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 23:10:47 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/19 23:10:51 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_simple(t_ps *ps)
{
	int	min_pos;

	if (is_sorted(&ps->a))
		return ;
	while (ps->a.len > 3)
	{
		min_pos = find_min_pos(&ps->a);
		move_pos_to_top_a(ps, min_pos);
		exec_op(ps, OP_PB, 1);
	}
	if (ps->a.len == 2 && ps->a.arr[0] > ps->a.arr[1])
		exec_op(ps, OP_SA, 1);
	else if (ps->a.len == 3)
		sort_three(ps);
	while (ps->b.len > 0)
		exec_op(ps, OP_PA, 1);
}
