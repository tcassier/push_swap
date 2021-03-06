/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 09:14:25 by tcassier          #+#    #+#             */
/*   Updated: 2018/02/01 04:17:29 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int ac, char **av)
{
	t_list	*lst;
	int		*stack_a;
	int		*stack_b;
	int		size_a;

	stack_a = NULL;
	stack_b = NULL;
	lst = NULL;
	if (ac < 2)
		return (EXIT_SUCCESS);
	size_a = parser(--ac, ++av, &stack_a, &stack_b);
	if (size_a > 1)
	{
		if (!(lst = ft_lstnew(NULL, 0)))
			failure();
		process_ps(stack_a, stack_b, size_a, lst);
	}
	return (EXIT_SUCCESS);
}
