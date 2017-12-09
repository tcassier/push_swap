/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:48:05 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/09 09:47:09 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_sb(t_stack *data)
{
	int	tmp;

	if (data->size_b > 1)
	{
		tmp = data->stack_b[data->size_b - 1];
		data->stack_b[data->size_b - 1] = data->stack_b[data->size_b - 2];
		data->stack_b[data->size_b - 2] = tmp;
	}
}
