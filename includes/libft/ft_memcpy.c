/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:24:07 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:24:08 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	i = 0;
	while (i < count)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int	main(void)
{
	int	og[4] = {1, 58, 2147483647, -25};
	int	*temp_mem = malloc(sizeof(int) * 4);
	if (temp_mem == NULL)
		return (0);
	temp_mem = ft_memcpy(temp_mem, og, 4*4);
	int	i = 0;
	while (i < 4)
	{
		printf("%d ", temp_mem[i]);
		i++;
	}
}
*/
