/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:24:23 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:24:24 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointeur, int value, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)pointeur)[i] = value;
		i++;
	}
	return (pointeur);
}

/*
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Veuillez rentrer une valeur !");
		return (0);
	}
	char *mem = ft_calloc(3, 4);
	if (mem == NULL)
		return (0);
	int i = 0;

	printf("On affiche les valeur de notre tableau en memoire : ");
	while (i < 3)
	{
		printf("%d", mem[i]);
		i++;
	}
	printf("\nOn remplace desormais tout notre tableau en memoire 
		par la valeur voulue : ");
	mem = ft_memset(mem, atoi(argv[1]), 4*3);
	i = 0;
	while (i < 3)
	{
		if (atoi(argv[1]) >= 0 && atoi(argv[1]) <= 127)
			printf("%c ", mem[i]);
		else
			printf("%d ", mem[i]);
		i++;
	}
}
*/