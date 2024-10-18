/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:14 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:21:16 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int character)
{
	if (character >= '0' && character <= '9')
		return (2);
	return (0);
}

/*
int main()
{
	printf("%d\n", ft_isdigit('Z'));
	printf("%d\n", ft_isdigit('\\'));
	printf("%d\n", ft_isdigit('8'));
}
*/
