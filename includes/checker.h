/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 07:29:35 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/31 07:29:37 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "both.h"

void			print_stack(t_stack *data);
int				process_ck(int *stack_a, int *stack_b, int size, int print);
#endif
