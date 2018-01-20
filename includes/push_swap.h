/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 13:48:56 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 17:45:58 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "both.h"

enum { NONE, PA, PB, RA, RR, RB, RRA, RRB, RRR, SA, SB, SS };

t_list				*check_backstack(t_stack *data, t_list *lst);
t_list				*exec_save(t_stack *data, t_list *lst, int exec);
void				process_ps(int *stack_a, int *stack_b, int size,
					t_list *lst);
void				quick_sort(t_stack *data, t_list *lst);
#endif
