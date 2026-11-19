/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 23:21:09 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/19 23:21:19 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_ps	ps;

	ft_bzero(&ps, sizeof(t_ps));
	if (argc < 2)
		return (0);
	parse_args(argc, argv, &ps);
	run_push_swap(&ps);
	print_bench(&ps);
	free_and_exit(&ps, NULL, 0);
	return (0);
}
