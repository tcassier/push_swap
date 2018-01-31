/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_cleaner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 06:53:00 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/31 07:23:08 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_push(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*iter;

	last = NULL;
	iter = *lst;
	while (iter)
	{
		if ((iter->content_size == PA && iter->next->content_size == PB)
		|| (iter->content_size == PB && iter->next->content_size == PA))
		{
			tmp = iter->next->next;
			free(iter->next);
			free(iter);
			if (!last)
				*lst = tmp;
			else
				last->next = tmp;
			return (1);
		}
		last = iter;
		iter = iter->next;
	}
	return (0);
}

static int	rotate_block(t_list *iter)
{
	if ((iter->content_size == RA && iter->next->content_size == RRA)
	|| (iter->content_size == RRA && iter->next->content_size == RA)
	|| (iter->content_size == RB && iter->next->content_size == RRB)
	|| (iter->content_size == RRB && iter->next->content_size == RB))
		return (1);
	return (0);
}

static int	check_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*tmp;
	t_list	*iter;

	last = NULL;
	iter = *lst;
	while (iter)
	{
		if (rotate_block(iter))
		{
			tmp = iter->next->next;
			free(iter->next);
			free(iter);
			if (!last)
				*lst = tmp;
			else
				last->next = tmp;
			return (1);
		}
		last = iter;
		iter = iter->next;
	}
	return (0);
}

void		lst_cleaner(t_list **lst)
{
	int		clean;

	clean = 0;
	clean += check_push(lst);
	clean += check_rotate(lst);
	if (clean)
		lst_cleaner(lst);
}
