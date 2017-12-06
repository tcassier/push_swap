/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:57:20 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/05 08:08:19 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_atoi(const char *str)
{
	long			ret;
	int				sign;
	int				index;

	index = 0;
	ret = 0;
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(str[index]))
		ret = ret * 10 + str[index++] - '0';
	ret *= sign;
	if (ret > 2147483647 || ret < -2147483648)
		return (-1);
	return ((int)ret);
}
