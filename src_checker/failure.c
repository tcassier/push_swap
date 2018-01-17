/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failure.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 07:07:49 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/17 16:03:36 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	failure(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
