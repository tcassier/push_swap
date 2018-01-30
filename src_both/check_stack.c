/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 10:04:15 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/30 03:20:21 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "both.h"

int			check_stack(t_stack *data)
{
	int		index;

	if (data->size_b || !data->size_a)
		return (0);
	index = data->size_a;
	while (--index)
	{
		if (data->stack_a[index] > data->stack_a[index - 1])
			return (0);
	}
	return (1);
}
