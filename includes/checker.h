/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 07:33:15 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 09:43:15 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "both.h"

void			print_stack(t_stack *data);
int				process(int *stack_a, int *stack_b, int size, int print);
#endif
