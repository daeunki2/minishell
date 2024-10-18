/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:58 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:26:00 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		total_length;
	char	*ret;
	int		i;

	i = 0;
	total_length = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * total_length + 1);
	if (!(ret))
		return (NULL);
	while (*s1 != '\0')
	{
		ret[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		ret[i] = *s2;
		i++;
		s2++;
	}
	ret[i] = '\0';
	return (ret);
}

/*
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		printf("Veuillez rentrer deux chaine de character pls !");
		return (0);
	}
	char *new_chaine;
	new_chaine = ft_strjoin(argv[1], argv[2]);
	printf("La nouvelle chaine est desormais ' %s '", new_chaine);
}
*/