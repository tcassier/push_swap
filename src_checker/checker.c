/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:03:07 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/20 05:58:29 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	check_tab(int size, char **tab)
{
	int		index_tab;
	int		index_str;
	int		index;

	index_tab = -1;
	while (++index_tab < size)
	{
		index = -1;
		while (++index < size)
		{
			if (!ft_strcmp(tab[index], tab[index_tab]) && index != index_tab)
				failure();
		}
		index_str = -1;
		if (tab[index_tab][0] == '-' || tab[index_tab][0] == '+')
			index_str++;
		while (tab[index_tab][++index_str])
		{
			if (!ft_isdigit(tab[index_tab][index_str]))
				failure();
		}
	}
}

static int	new_tab(int ac, char **av, char ***tab)
{
	char	**tmp;
	int		index_tab;
	int		index_av;
	int		index;
	int		count;

	count = 0;
	index_av = -1;
	while (++index_av < ac)
		count += ft_count_word(av[index_av], ' ');
	if (!(*tab = (char**)ft_memalloc(sizeof(char*) * count)))
		failure();
	index_av = -1;
	index_tab = 0;
	while (++index_av < ac)
	{
		if (!(tmp = ft_strsplit(av[index_av], ' ')))
			failure();
		index = -1;
		while (++index < ft_count_word(av[index_av], ' '))
			(*tab)[index_tab++] = tmp[index];
		free(tmp);
	}
	return (count);
}

static int	parser(int ac, char **av, int **stack_a, int **stack_b)
{
	int		size;
	int		index;
	int		index_rev;
	char	**tab;

	tab = NULL;
	size = new_tab(ac, av, &tab);
	check_tab(size, tab);
	if (size >= 1)
	{
		if (!(*stack_a = (int*)ft_memalloc(sizeof(int) * size)) ||
		(!(*stack_b = (int*)ft_memalloc(sizeof(int) * size))))
			failure();
		index = -1;
		index_rev = size;
		while (++index < size && --index_rev >= 0)
		{
			if (ft_strlen(tab[index]) > 2 && ft_atoi_sec(tab[index]) == -1)
				failure();
			(*stack_a)[index_rev] = ft_atoi_sec(tab[index]);
		}
	}
	return (size);
}

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
	if (!process(stack_a, stack_b, size_a, print))
		ft_putstr("KO\n");
	else
		ft_putstr("OK\n");
	return (EXIT_SUCCESS);
}
