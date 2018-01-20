/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_rra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 10:09:11 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 08:16:51 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

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
