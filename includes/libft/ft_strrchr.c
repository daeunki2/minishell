/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:27:13 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:27:15 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*last;

	last = NULL;
	while (*str)
	{
		if (*str == (char)c)
			last = (char *)str;
		str++;
	}
	if (c == '\0')
		last = (char *)str;
	return (last);
}

/*
int main(int argc, char **argv)
{
	char *valeur;

	if (argc != 3)
	{
		printf("Veuillez rentrer une chaine de charactere, et un character a \
			rechercher");
		return (0);
	}
	valeur = ft_strrchr(argv[1], argv[2][0]);
	if (valeur == 0)
	{
		printf("Aucune occurence n'a ete trouvee");
		return (0);
	}
	else
	{
		printf("le charactere ' %c ' a ete trouver dans la chaine ' %s ' \
			a l'adresse %p", *valeur, argv[1], valeur);
		return (0);
	}
}
*/