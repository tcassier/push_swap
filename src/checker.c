/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 22:44:54 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/05 09:44:15 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	check_av(int ac, char **av)
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
			if (!ft_strncmp(av[index], av[index_tab]) && index != index_tab)
				return (-1);
		}
		index_str = -1;
		while ((*av)[++index_str])
		{
			if (!isdigit((*av)[index_str]))
				return (-1);
		}
	}
	return (0);
}

static int	parser(int ac, char **av, int **stack_a, int **stack_b)
{
	int		index;

	if (ac > 1 && check_av(ac, av) != -1)
	{
		if ((!stack_a = (int**)ft_memalloc(sizeof(int) * ac)) ||
				(!(stack_b = (int**)ft_memalloc(sizeof(int) * ac))))
			return (-1);
		index = -1;
		while (++index < ac)
		{
			if (ft_strlen(av[index]) > 2 && ft_atoi(av[index]) == -1)
				return (-1);
			stack_a[index] = ft_atoi(av[index]);
		}
		return (0);
	}
	return (-1);
}

int			main(int ac, char **av)
{
	int		**stack_a;
	int		**stack_b;
	int		ret;

	stack_a = NULL;
	stack_b = NULL;
	if (parser(--ac, ++av, stack_a, stack_b) == -1)
	{
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (!process(stack_a, stack_b, ac))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	free(stack_a);
	free(stack_b);
	return (0);
}
