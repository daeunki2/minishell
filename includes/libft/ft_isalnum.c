/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:20:56 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:20:58 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if ((character >= 'a' && character <= 'z')
		|| (character >= 'A' && character <= 'Z')
		|| (character >= '0' && character <= '9'))
		return (2);
	else
		return (0);
}

/*
int main()
{
	printf("%d\n", ft_isalnum('Z'));
	printf("%d\n", ft_isalnum('\\'));
	printf("%d\n", ft_isalnum('8'));
}
*/