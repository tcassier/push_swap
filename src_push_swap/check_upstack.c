/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_upstack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 03:51:49 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/31 08:04:16 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_upstack(t_stack *data, t_list *lst)
{
	int		index;

	index = data->size_a - 1;
	if (data->size_a > 3)
	{
		while (--index > 0)
		{
			if (data->stack_a[index] > data->stack_a[index - 1])
				return ;
		}
		if (data->stack_a[data->size_a - 1] > data->stack_a[data->size_a - 2]
		&& data->stack_a[data->size_a - 1] < data->stack_a[data->size_a - 3])
			exec_save(data, lst, SA);
	}
}
