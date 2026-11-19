/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 23:12:34 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/19 23:12:46 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	sort_low_disorder(t_ps *ps)
{
	int	i;
	int	n;

	n = ps->a.len;
	i = 0;
	while (i < n - 1)
	{
		if (ps->a.arr[0] > ps->a.arr[1])
			exec_op(ps, OP_SA, 1);
		exec_op(ps, OP_RA, 1);
		i++;
	}
	exec_op(ps, OP_RA, 1);
	if (!is_sorted(&ps->a))
		move_pos_to_top_a(ps, find_min_pos(&ps->a));
	if (!is_sorted(&ps->a))
		sort_medium(ps);
}

static void	select_strategy(t_ps *ps)
{
	if (ps->flag_strat != STRAT_ADAPTIVE)
		ps->bench.used_strat = ps->flag_strat;
	else if (ps->bench.disorder < 0.2)
		ps->bench.used_strat = STRAT_SIMPLE;
	else if (ps->bench.disorder < 0.5)
		ps->bench.used_strat = STRAT_MEDIUM;
	else
		ps->bench.used_strat = STRAT_COMPLEX;
}

void	run_push_swap(t_ps *ps)
{
	ps->bench.disorder = compute_disorder(&ps->a);
	index_stack(ps);
	select_strategy(ps);
	if (is_sorted(&ps->a))
		return ;
	if (ps->flag_strat == STRAT_ADAPTIVE && ps->bench.disorder < 0.2)
		sort_low_disorder(ps);
	else if (ps->bench.used_strat == STRAT_SIMPLE)
		sort_simple(ps);
	else if (ps->bench.used_strat == STRAT_MEDIUM)
		sort_medium(ps);
	else
		sort_complex(ps);
}
