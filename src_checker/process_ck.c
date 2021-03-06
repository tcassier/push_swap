/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:19:59 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/01 04:20:37 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	exec_apply(t_stack *data, char *line)
{
	if (!ft_strcmp(line, "pa"))
		exec_pa(data);
	else if (!ft_strcmp(line, "pb"))
		exec_pb(data);
	else if (!ft_strcmp(line, "ra"))
		exec_ra(data);
	else if (!ft_strcmp(line, "rb"))
		exec_rb(data);
	else if (!ft_strcmp(line, "rr"))
		exec_rr(data);
	else if (!ft_strcmp(line, "rra"))
		exec_rra(data);
	else if (!ft_strcmp(line, "rrb"))
		exec_rrb(data);
	else if (!ft_strcmp(line, "rrr"))
		exec_rrr(data);
	else if (!ft_strcmp(line, "sa"))
		exec_sa(data);
	else if (!ft_strcmp(line, "sb"))
		exec_sb(data);
	else if (!ft_strcmp(line, "ss"))
		exec_ss(data);
	else
		failure();
}

int			process_ck(int *stack_a, int *stack_b, int size, int print)
{
	t_stack	*data;
	char	*line;
	int		ret;

	if (!(data = (t_stack*)ft_memalloc(sizeof(t_stack))))
		failure();
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	data->size_a = size;
	while (get_next_line(0, &line))
	{
		exec_apply(data, line);
		if (print == 1)
			print_stack(data);
		ft_strdel(&line);
	}
	ret = check_stack(data);
	free(data);
	return (ret);
}
