/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:25 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/18 14:20:49 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	assign_nbr(char *result, int size, long nbr)
{
	if (nbr == 0)
		result[0] = '0';
	size--;
	while (nbr)
	{
		result[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
}

static int	count_size(int n)
{
	int	n_digits;
	int	size;

	n_digits = 0;
	size = 0;
	if (n == 0)
		n_digits = 1;
	else
	{
		if (n < 0)
			size++;
		while (n)
		{
			n_digits++;
			n /= 10;
		}
	}
	size += n_digits;
	return (size);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		size;
	long	nbr;

	size = count_size(n);
	nbr = (long)n;
	result = (char *)ft_calloc(sizeof (char), (size + 1));
	if (result == 0)
		return (NULL);
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	assign_nbr(result, size, nbr);
	return (result);
}
