/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 09:48:05 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/10 13:52:16 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_sa(t_stack *data)
{
	int	tmp;

	if (data->size_a > 1)
	{
		tmp = data->stack_a[data->size_a - 1];
		data->stack_a[data->size_a - 1] = data->stack_a[data->size_a - 2];
		data->stack_a[data->size_a - 2] = tmp;
	}
}
