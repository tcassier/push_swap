/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 11:55:55 by tcassier          #+#    #+#             */
/*   Updated: 2018/01/17 21:48:56 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_imaxtoa_base(intmax_t n, int base)
{
	int		len;
	char	*str;

	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (n == 0)
		return (ft_strdup("0"));
	len = ft_nbrlen_imax_base(n, base);
	if (!(str = ft_strnew(len)))
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len--] = '\0';
	while (n > 0)
	{
		if (n % base < 10)
			str[len--] = n % base + '0';
		else
			str[len--] = n % base - 10 + 'a';
		n /= base;
	}
	return (str);
}
