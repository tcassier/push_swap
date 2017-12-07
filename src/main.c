/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcassier <tcassier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 07:27:20 by tcassier          #+#    #+#             */
/*   Updated: 2017/12/06 10:13:43 by tcassier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>


typedef struct   yolo
{
	int tab[5];
}				lol;

int		main(void)
{
	lol	*yolo;
	int i;

	yolo = malloc(sizeof(lol));
	(yolo->tab)[0] = 5;
	(yolo->tab)[1] = 4;
	(yolo->tab)[2] = 7;
	(yolo->tab)[3] = 12;
	(yolo->tab)[4] = 14;
	i = 0;
	while (i < 5)
	{
		printf("%d\n", yolo->tab[i]);
		i++;
	}
	return (0);
}
