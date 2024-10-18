/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:26:32 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:26:40 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp( const char *first, const char *second, size_t length )
{
	size_t	i;

	i = 0;
	if (length == 0)
		return (0);
	while ((i < length - 1) && (first[i] == second[i]) && first[i] != '\0')
	{
		i++;
	}
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
/*
int main() 
{

    printf("%d", ft_strncmp("salut", "saltt", 4));
    return 0;
}
*/