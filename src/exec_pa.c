/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:37:49 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/07 19:29:33 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_pa(t_stack *data)
{
	if (data->size_b > 0)
	{
		if (data->size_a > 0)
			data->stack_a[data->size_a - 1] = data->stack_b[data->size_b - 1];
		else
			data->stack_a[0] = data->stack_b[data->size_b - 1];
		data->size_a++;
		data->size_b--;
	}
}