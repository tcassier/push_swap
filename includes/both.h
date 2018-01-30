/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 08:08:02 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/30 03:35:11 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOTH_H
# define BOTH_H
# include "libft.h"

typedef struct	s_stack
{
	int			*stack_a;
	int			*stack_b;
	int			size_a;
	int			size_b;
}				t_stack;

int				check_stack(t_stack *data);
void			exec_pa(t_stack *data);
void			exec_pb(t_stack *data);
void			exec_ra(t_stack *data);
void			exec_rb(t_stack *data);
void			exec_rr(t_stack *data);
void			exec_rra(t_stack *data);
void			exec_rrb(t_stack *data);
void			exec_rrr(t_stack *data);
void			exec_sa(t_stack *data);
void			exec_sb(t_stack *data);
void			exec_ss(t_stack *data);
void			failure(void);
int				parser(int ac, char **av, int **stack_a, int **stack_b);
#endif
