/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:19 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:21:21 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int character)
{
	if (character >= ' ' && character < 127)
		return (2);
	return (0);
}

/*
int main()
{
	printf("%d\n", ft_isprint(28));
	printf("%d\n", ft_isprint('\\'));
	printf("%d\n", ft_isprint('8'));
}
*/
