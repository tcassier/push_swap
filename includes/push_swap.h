/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:48:56 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/30 04:00:38 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "both.h"

# define STKA data->stack_a
# define STKB data->stack_b
# define SIZA data->size_a
# define SIZB data->size_b

enum { NONE, PA, PB, RA, RR, RB, RRA, RRB, RRR, SA, SB, SS };

void				check_backstack(t_stack *data, t_list *lst);
void				check_upstack(t_stack *data, t_list *lst);
t_list				*exec_save(t_stack *data, t_list *lst, int exec);
void				process_ps(int *stack_a, int *stack_b, int size,
					t_list *lst);
#endif
