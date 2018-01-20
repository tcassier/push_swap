/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:48:56 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 10:07:51 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "both.h"

enum { PA, PB, RA, RR, RB, RRA, RRB, RRR, SA, SB, SS };

typedef struct		s_exec
{
	int				exec;
	struct s_exec	*next;
}					t_exec;

void				process(int *stack_a, int *stack_b, int size, t_exec *lst);
void				quick_sort(t_stack *data, t_exec *lst);
#endif
