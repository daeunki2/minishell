/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:08 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:21:10 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (2);
	return (0);
}

/*
int main()
{
	printf("%d\n", ft_isascii('Z'));
	printf("%d\n", ft_isascii('\\'));
	printf("%d\n", ft_isascii('8'));
}
*/
