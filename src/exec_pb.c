/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:37:49 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/09 09:46:41 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_pb(t_stack *data)
{
	if (data->size_a > 0)
	{
		if (data->size_b > 0)
			data->stack_b[data->size_b - 1] = data->stack_a[data->size_a - 1];
		else
			data->stack_b[0] = data->stack_a[data->size_a - 1];
		data->size_a--;
		data->size_b++;
	}
}
