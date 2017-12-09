/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 09:57:01 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/09 12:38:31 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rb(t_stack *data)
{
	int	tmp;
	int index;

	if (data->size_b > 1)
	{
		index = data->size_b;
		tmp = data->stack_b[data->size_b - 1];
		while (--index)
			data->stack_b[index] = data->stack_b[index - 1];
		data->stack_b[index] = tmp;
	}
}
