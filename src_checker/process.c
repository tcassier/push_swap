/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:19:59 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/17 17:08:39 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_stack(t_stack *data)
{
	int		index;

	if (data->size_b || !data->size_a)
		return (0);
	index = data->size_a;
	while (--index)
	{
		if (data->stack_a[index] > data->stack_a[index - 1])
			return (0);
	}
	return (1);
}

static void	exec(t_stack *data, char *line)
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

int			process(int *stack_a, int *stack_b, int ac, int print)
{
	t_stack	*data;
	char	*line;
	int		ret;

	if (!(data = (t_stack*)ft_memalloc(sizeof(t_stack))))
		failure();
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	data->size_a = ac;
	data->size_b = 0;
	while (get_next_line(0, &line))
	{
		exec(data, line);
		if (print == 1)
			print_stack(data);
	}
	ret = check_stack(data);
	return (ret);
}
