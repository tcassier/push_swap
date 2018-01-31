/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:48:21 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/31 08:04:10 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			check_backstack(t_stack *data, t_list *lst)
{
	int			index;

	index = data->size_a;
	if (data->size_a > 3)
	{
		while (--index > 1)
		{
			if (data->stack_a[index] > data->stack_a[index - 1])
				return ;
		}
		if (data->stack_a[1] > data->stack_a[0] &&
		data->stack_a[0] > data->stack_a[2])
		{
			lst = exec_save(data, lst, RRA);
			lst = exec_save(data, lst, RRA);
			lst = exec_save(data, lst, SA);
			lst = exec_save(data, lst, RA);
			exec_save(data, lst, RA);
		}
	}
}
