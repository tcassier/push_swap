/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 04:15:33 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/30 08:40:22 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			get_median(int *stack, int size)
{
	int		*tmp;
	int		ret;

	if (!(tmp = (int*)ft_memdup((const void*)stack, size * sizeof(int))))
		failure();
	bubble_sort(tmp, size);
	if (size % 2 != 0)
		ret = tmp[size / 2];
	else
		ret = tmp[size / 2 - 1];
	free(tmp);
	return (ret);
}
