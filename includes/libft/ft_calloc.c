/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:19:05 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:20:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementSize, size_t elementCount)
{
	void	*new_mem;

	if (elementSize != 0 && elementCount > (size_t) - 1 / elementSize)
		return (NULL);
	new_mem = malloc(elementCount * elementSize);
	if (new_mem == NULL)
		return (NULL);
	ft_bzero(new_mem, (elementCount * elementSize));
	return (new_mem);
}
/*
int	main() 
{
	char	*mem;
	int i = 0;
	mem = ft_calloc(10, 4);
	while (i < 10)
	{
		printf("%d", mem[i]);
		i++;
	}	
}
*/