/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 10:43:37 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/30 06:52:45 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	case_a_b(t_stack *data, int *size_a, int *size_b)
{
	while (*size_a > *size_b)
	{
		ft_printf(" %-10d %-10c\n", data->stack_a[*size_a - 1], ' ');
		(*size_a)--;
	}
}

static void	case_b_a(t_stack *data, int *size_a, int *size_b)
{
	while (*size_b > *size_a)
	{
		ft_printf(" %-10c %-10d\n", ' ', data->stack_b[*size_b - 1]);
		(*size_b)--;
	}
}

void		print_stack(t_stack *data)
{
	int		size_a;
	int		size_b;

	ft_printf("\n---        ---\n");
	size_a = data->size_a;
	size_b = data->size_b;
	case_a_b(data, &size_a, &size_b);
	case_b_a(data, &size_a, &size_b);
	while (size_a > 0 && size_b > 0)
	{
		ft_printf(" %-10d %-10d\n", data->stack_a[size_a - 1],
		data->stack_b[size_b - 1]);
		size_a--;
		size_b--;
	}
	ft_printf("---        ---\n a          b \n---        ---\n\n");
}
