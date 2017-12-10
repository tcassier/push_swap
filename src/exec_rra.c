/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:09:11 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/10 11:16:56 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rra(t_stack *data)
{
	int	tmp;
	int	index;

	if (data->size_a > 1)
	{
		index = -1;
		tmp = data->stack_a[0];
		while (++index < data->size_a - 1)
			data->stack_a[index] = data->stack_a[index + 1];
		data->stack_a[index] = tmp;
	}
}
