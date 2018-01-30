/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_save.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 15:09:50 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/30 07:11:53 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_apply(t_stack *data, int exec)
{
	if (exec == SA)
		exec_sa(data);
	else if (exec == SB)
		exec_sb(data);
	else if (exec == SS)
		exec_ss(data);
	else if (exec == PA)
		exec_pa(data);
	else if (exec == PB)
		exec_pb(data);
	else if (exec == RA)
		exec_ra(data);
	else if (exec == RB)
		exec_rb(data);
	else if (exec == RR)
		exec_rr(data);
	else if (exec == RRA)
		exec_rra(data);
	else if (exec == RRB)
		exec_rrb(data);
	else if (exec == RRR)
		exec_rrr(data);
}

t_list		*exec_save(t_stack *data, t_list *lst, int exec)
{
	exec_apply(data, exec);
	lst->content_size = (size_t)exec;
	if (!(lst->next = ft_lstnew(NULL, 0)))
		failure();
	return (lst->next);
}
