/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:37:49 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 08:16:00 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

void	exec_pb(t_stack *data)
{
	if (data->size_a > 0)
	{
		if (data->size_b > 0)
			data->stack_b[data->size_b] = data->stack_a[data->size_a - 1];
		else
			data->stack_b[0] = data->stack_a[data->size_a - 1];
		data->size_a--;
		data->size_b++;
	}
}
