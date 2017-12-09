/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rrb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:09:11 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/09 10:26:38 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_rrb(t_stack *data)
{
	int	tmp;
	int	index;

	if (data->size_b > 1)
	{
		index = -1;
		tmp = data->stack_b[0];
		while (++index < data->size_b - 1)
			data->stack_b[index] = data->stack_b[index + 1];
		data->stack_b[index] = tmp;
	}
}
