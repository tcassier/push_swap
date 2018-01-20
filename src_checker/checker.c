/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:03:07 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 18:10:48 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int			main(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
	int		size_a;
	int		print;

	print = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		failure();
	if (!ft_strcmp(av[1], "-v"))
	{
		print++;
		av++;
		ac--;
	}
	size_a = parser(--ac, ++av, &stack_a, &stack_b);
	if (!process_ck(stack_a, stack_b, size_a, print))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (EXIT_SUCCESS);
}
