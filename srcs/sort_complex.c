/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 23:11:40 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/19 23:18:30 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(int len)
{
	int	max_num;
	int	bits;

	max_num = len - 1;
	bits = 0;
	while ((max_num >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass_bit(t_ps *ps, int bit, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (((ps->a.arr[0] >> bit) & 1) == 0)
			exec_op(ps, OP_PB, 1);
		else
			exec_op(ps, OP_RA, 1);
		i++;
	}
	while (ps->b.len > 0)
		exec_op(ps, OP_PA, 1);
}

void	sort_complex(t_ps *ps)
{
	int	max_bits;
	int	bit;
	int	size;

	if (is_sorted(&ps->a))
		return ;
	if (ps->a.len <= 5)
		return (sort_simple(ps));
	size = ps->a.len;
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass_bit(ps, bit, size);
		bit++;
	}
}
