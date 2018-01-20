/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 14:49:53 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 18:18:17 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*swap_part(t_stack *data, t_list *lst)
{
	t_list		*ret;

	ret = lst;
	if (data->stack_a[data->size_a - 1] > data->stack_a[data->size_a - 2] &&
	data->stack_b[data->size_b - 1] < data->stack_b[data->size_b - 2] &&
	data->size_a >= 2 && data->size_b >= 2)
		ret = exec_save(data, lst, SS);
	else if (data->stack_a[data->size_a - 1] > data->stack_a[data->size_a - 2]
	&& data->size_a >= 2)
		ret = exec_save(data, lst, SA);
	else if (data->stack_b[data->size_b - 1] < data->stack_b[data->size_b - 2]
	&& data->size_b >= 2)
		ret = exec_save(data, lst, SB);
	return (ret);
}

void			quick_sort(t_stack *data, t_list *lst)
{
	int			index;

	index = data->size_a;
	while (index > 0)
	{
		lst = swap_part(data, lst);
		lst = exec_save(data, lst, PB);
		index--;
	}
	index = data->size_b;
	while (index > 0)
	{
		lst = swap_part(data, lst);
		lst = exec_save(data, lst, PA);
		index--;
	}
	if (!check_stack(data))
		quick_sort(data, lst);
}
