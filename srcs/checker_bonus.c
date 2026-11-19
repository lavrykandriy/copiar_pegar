/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alavryk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 00:17:24 by alavryk           #+#    #+#             */
/*   Updated: 2026/11/20 00:30:24 by alavryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	parse_rot_op(char *line, t_op *op)
{
	if (ft_strncmp(line, "ra\n", 4) == 0)
		*op = OP_RA;
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		*op = OP_RB;
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		*op = OP_RR;
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		*op = OP_RRA;
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		*op = OP_RRB;
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		*op = OP_RRR;
	else
		return (0);
	return (1);
}

static int	parse_op(char *line, t_op *op)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		*op = OP_SA;
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		*op = OP_SB;
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		*op = OP_SS;
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		*op = OP_PA;
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		*op = OP_PB;
	else
		return (parse_rot_op(line, op));
	return (1);
}

static void	drain_and_error(t_ps *ps, char *line)
{
	while (line != NULL)
	{
		free(line);
		line = get_next_line(0);
	}
	free_and_exit(ps, NULL, 1);
}

static void	read_and_run_ops(t_ps *ps)
{
	char	*line;
	t_op	op;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!parse_op(line, &op))
			drain_and_error(ps, line);
		exec_op(ps, op, 0);
		free(line);
		line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	ft_bzero(&ps, sizeof(t_ps));
	if (argc < 2)
		return (0);
	if (ft_strncmp(argv[1], "--", 2) == 0)
		return (write(2, "Error\n", 6), 1);
	parse_args(argc, argv, &ps);
	read_and_run_ops(&ps);
	if (is_sorted(&ps.a) && ps.b.len == 0)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	free_and_exit(&ps, NULL, 0);
	return (0);
}
