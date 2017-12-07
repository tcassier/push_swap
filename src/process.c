/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 09:19:59 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/07 19:32:52 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_stack(t_stack *data)
{
	int		index;

	if (data->size_b)
		return (0);
	index = data->size_a;
	while (--index)
	{
		if (data->stack_a[index] > data->stack_a[index - 1])
			return (0);
	}
	return (1);
}

/*static void	reader(t_stack *data)
{
}*/

int			process(int *stack_a, int *stack_b, int ac)
{
	t_stack	*data;

	if (!(data = (t_stack*)ft_memalloc(sizeof(t_stack))))
		failure();
	data->stack_a = stack_a;
	data->stack_b = stack_b;
	data->size_a = ac;
	data->size_b = 0;
//	reader(data);
	return (check_stack(data));
}
