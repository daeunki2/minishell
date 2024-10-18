/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:26:13 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:26:15 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
int main(int ac, char **av)
{
	if (ac != 2)
		return 0;
	printf("%d\n", ft_strlen(av[1]));
	printf("On oublie pas que il y a bien %d lettres au mot choisis , 
		cepedant en memoire un dernier octet e
		est attribue pour le '\\0' qui termine les chaine de character en C\n", 
			ft_strlen(av[1]));
	printf("Si l'on voulait attribuer un espace memoire pour le mot il nous 
		faudrait char *tab[%d] d'espace", 
		(ft_strlen(av[1]) + 1));
	return 0;
}
*/