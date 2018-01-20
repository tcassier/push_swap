/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 07:33:15 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 16:19:52 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "both.h"

void			print_stack(t_stack *data);
int				process_ck(int *stack_a, int *stack_b, int size, int print);
#endif
