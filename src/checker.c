/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:44:54 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/10 12:15:09 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_av(int ac, char **av)
{
	int		index_tab;
	int		index_str;
	int		index;

	index_tab = -1;
	while (++index_tab < ac)
	{
		index = -1;
		while (++index < ac)
		{
			if (!ft_strcmp(av[index], av[index_tab]) && index != index_tab)
				failure();
		}
		index_str = -1;
		if (av[index_tab][0] == '-' || av[index_tab][0] == '+')
			index_str++;
		while (av[index_tab][++index_str])
		{
			if (!ft_isdigit(av[index_tab][index_str]))
				failure();
		}
	}
}

static void	parser(int ac, char **av, int **stack_a, int **stack_b)
{
	int		index;
	int		index_rev;

	check_av(ac, av);
	if (ac > 1)
	{
		if (!(*stack_a = (int*)ft_memalloc(sizeof(int) * ac)) ||
		(!(*stack_b = (int*)ft_memalloc(sizeof(int) * ac))))
			failure();
		index = -1;
		index_rev = ac;
		while (++index < ac && --index_rev >= 0)
		{
			if (ft_strlen(av[index]) > 2 && ft_atoi(av[index]) == -1)
				failure();
			(*stack_a)[index_rev] = ft_atoi(av[index]);
		}
	}
}

int			main(int ac, char **av)
{
	int		*stack_a;
	int		*stack_b;
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
	parser(--ac, ++av, &stack_a, &stack_b);
	if (!process(stack_a, stack_b, ac, print))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (EXIT_SUCCESS);
}
