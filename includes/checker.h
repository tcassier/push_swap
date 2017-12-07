/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 07:33:15 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/06 15:24:21 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "libft.h"

typedef struct	s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
}				t_stack;

void	exec_pa(t_stack *data);
void	exec_pb(t_stack *data);
void	exec_ra(t_stack *data);
void	exec_rb(t_stack *data);
void	exec_rr(t_stack *data);
void	exec_rra(t_stack *data);
void	exec_rrb(t_stack *data);
void	exec_rrr(t_stack *data);
void	exec_sa(t_stack *data);
void	exec_sb(t_stack *data);
void	exec_ss(t_stack *data);
void	failure(void);
int		process(int *stack_a, int *stack_b, int ac);
#endif
