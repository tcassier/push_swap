/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_backstack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:48:21 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 18:17:42 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*exec_backswap(t_stack *data, t_list *lst)
{
	t_list		*ret;

	ret = lst;
	ret = exec_save(data, ret, RRA);
	ret = exec_save(data, ret, RRA);
	ret = exec_save(data, ret, SA);
	ret = exec_save(data, ret, RA);
	ret = exec_save(data, ret, RA);
	return (ret);
}

t_list			*check_backstack(t_stack *data, t_list *lst)
{
	t_list		*ret;
	int			index;

	ret = lst;
	index = data->size_a;
	if (data->size_a > 3)
	{
		while (--index > 1)
		{
			if (data->stack_a[index] > data->stack_a[index - 1])
				return (ret);
		}
		if (data->stack_a[1] > data->stack_a[0])
			ret = exec_backswap(data, ret);
	}
	return (ret);
}
