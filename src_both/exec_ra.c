/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_ra.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 09:57:01 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 08:16:20 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

void	exec_ra(t_stack *data)
{
	int	tmp;
	int index;

	if (data->size_a > 1)
	{
		index = data->size_a;
		tmp = data->stack_a[data->size_a - 1];
		while (--index)
			data->stack_a[index] = data->stack_a[index - 1];
		data->stack_a[index] = tmp;
	}
}
