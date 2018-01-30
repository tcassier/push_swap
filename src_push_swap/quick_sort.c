/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 04:12:43 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/30 09:29:18 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	sorted(t_stack *data, int size, int pile)
{
	int		count;
	int		index;

	count = 1;
	index = pile ? data->size_a - 1 : data->size_b - 1;
	while (index > 0 &&
	((pile && data->stack_a[index] < data->stack_a[index - 1]) ||
	(!pile && data->stack_b[index] > data->stack_b[index - 1])))
	{
		count++;
		index--;
	}
	if (count >= size)
		return (1);
	return (0);
}

static void	three_sort(t_stack *data, int size, int pile)
{
	if (!sorted(data, size, pile))
	{
		if (!sorted(data, 2, pile))
			data->lst = exec_save(data, data->lst, pile ? SA : SB);
		else
		{
			data->lst = exec_save(data, data->lst, pile ? RA : RB);
			data->lst = exec_save(data, data->lst, pile ? SA : SB);
			data->lst = exec_save(data, data->lst, pile ? RRA : RRB);
		}
		three_sort(data, size, pile);
	}
}

static int	exec_apply(t_stack *data, int pile, int pivot)
{
	if ((pile && data->stack_a[data->size_a - 1] < pivot) ||
	(!pile && data->stack_b[data->size_b - 1] >= pivot))
	{
		data->lst = exec_save(data, data->lst, pile ? PB : PA);
		return (1);
	}
	else
		data->lst = exec_save(data, data->lst, pile ? RA : RB);
	return (0);
}

void		quick_sort(t_stack *data, int size, int pile, int phase)
{
	int		index;
	int		reset;
	int		pivot;

	index = 0;
	reset = 0;
	pivot = get_median(pile ? data->stack_a : data->stack_b, size);
	if (sorted(data, size, pile))
		return ;
	while (size > 3 && index < (size / 2) + (size % 2 && !pile) && ++reset)
		index += exec_apply(data, pile, pivot);
	while (!phase && (reset--) - index)
		data->lst = exec_save(data, data->lst, pile ? RRA : RRB);
	if (index && !pile)
		quick_sort(data, index, !pile, 0);
	if (size - index <= 3)
		three_sort(data, size - index, pile);
	else
		quick_sort(data, size - index, pile, phase == 2 ? phase - 1 : phase);
	if (index && pile)
		quick_sort(data, index, !pile, phase == 2 ? 1 : 0);
	while (index--)
		data->lst = exec_save(data, data->lst, pile ? PA : PB);
}
