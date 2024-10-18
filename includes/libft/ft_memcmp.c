/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:23:54 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:23:55 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t size)
{
	size_t				i;
	unsigned const char	*p1;
	unsigned const char	*p2;

	p1 = (unsigned const char *)ptr1;
	p2 = (unsigned const char *)ptr2;
	if (p1 == NULL && p2 == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		if (p1[i] != p2[i])
		{
			return (p1[i] - p2[i]);
		}
		i++;
	}
	return (0);
}
/*
int main(void)
{
	char a[] = "iello";
	char b[] = "hello";

	if (ft_memcmp(a, b, 5) == 0)
	{
		printf("les deux bloc memoire sont egaux");
		return (0);
	}
	else if (ft_memcmp(a, b, 5) > 0)
	{
		printf("le bloc memoire 1 est superieur");
		return (0);
	}
	else
	{
		printf("le bloc memoire 2 est superieur");
		return (0);
	}
}
*/
