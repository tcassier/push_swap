/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 07:34:29 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/31 05:56:07 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_stack *data, int *stack)
{
	if (data->size_a == 3)
	{
		if (stack[2] < stack[1] && stack[2] < stack[0])
		{
			data->lst = exec_save(data, data->lst, RRA);
			data->lst = exec_save(data, data->lst, SA);
		}
		else if (stack[2] > stack[1] && stack[2] < stack[0])
			data->lst = exec_save(data, data->lst, SA);
		else if (stack[0] < stack[1] && stack[2] > stack[0])
			data->lst = exec_save(data, data->lst, RRA);
		else if (stack[0] > stack[1] && stack[2] > stack[0] &&
		stack[1] < stack[0])
			data->lst = exec_save(data, data->lst, RA);
		else if (stack[0] > stack[1] && stack[2] > stack[0] &&
		stack[1] > stack[0])
		{
			data->lst = exec_save(data, data->lst, RA);
			data->lst = exec_save(data, data->lst, SA);
		}
	}
	else
		exec_save(data, data->lst, SA);
}
