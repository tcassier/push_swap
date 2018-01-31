/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 04:15:33 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/31 05:49:12 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*get_stack(int *stack, int big_size, int size)
{
	int		*ret;

	if (!(ret = (int*)ft_memalloc(sizeof(int) * size)))
		failure();
	while (size-- && big_size--)
		ret[size] = stack[big_size];
	return (ret);
}

static void	bubble_sort(int *stack, int size)
{
	int		index;
	int		tmp;

	index = 0;
	while (index < size - 1)
	{
		if (stack[index] < stack[index + 1])
		{
			tmp = stack[index];
			stack[index] = stack[index + 1];
			stack[index + 1] = tmp;
			index = 0;
		}
		else
			index++;
	}
}

int			get_median(int *stack, int big_size, int size)
{
	int		*tmp;
	int		ret;

	tmp = get_stack(stack, big_size, size);
	bubble_sort(tmp, size);
	if (size % 2 != 0)
		ret = tmp[size / 2];
	else
		ret = tmp[size / 2 - 1];
	free(tmp);
	return (ret);
}
