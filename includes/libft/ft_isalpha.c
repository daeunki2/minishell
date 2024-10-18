/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:01 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:21:04 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int character)
{
	if ((character >= 'a' && character <= 'z')
		|| (character >= 'A' && character <= 'Z'))
		return (2);
	return (0);
}

/*
int main()
{
	printf("%d\n", ft_isalpha('Z'));
	printf("%d\n", ft_isalpha('\\'));
	printf("%d\n", ft_isalpha('8'));
}
*/