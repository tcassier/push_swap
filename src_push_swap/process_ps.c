/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:19:57 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/30 04:05:56 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_exec(int exec)
{
	if (exec == PA)
		ft_putstr("pa\n");
	else if (exec == PB)
		ft_putstr("pb\n");
	else if (exec == RA)
		ft_putstr("ra\n");
	else if (exec == RB)
		ft_putstr("rb\n");
	else if (exec == RR)
		ft_putstr("rr\n");
	else if (exec == RRA)
		ft_putstr("rra\n");
	else if (exec == RRB)
		ft_putstr("rrb\n");
	else if (exec == RRR)
		ft_putstr("rrr\n");
	else if (exec == SA)
		ft_putstr("sa\n");
	else if (exec == SB)
		ft_putstr("sb\n");
	else if (exec == SS)
		ft_putstr("ss\n");
}

void		process_ps(int *stack_a, int *stack_b, int size, t_list *lst)
{
	t_stack	*data;
	t_list	*tmp;

	if (!(data = (t_stack*)ft_memalloc(sizeof(t_stack))))
		failure();
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	data->size_a = size;
	data->size_b = 0;
	tmp = lst;
	check_backstack(data, tmp);
	check_upstack(data, tmp);
	if (!check_stack(data))
	{
		if (size <= 3)
			three_sort();
		else
			quick_sort();
	}
	while (lst)
	{
		print_exec((int)lst->content_size);
		lst = lst->next;
	}
}
