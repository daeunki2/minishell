/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:12 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:25:14 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	nb = n;
	if (nb >= 10)
		ft_putnbr_fd(nb / 10, fd);
	nb = nb % 10;
	ft_putchar_fd((nb + 48), fd);
}
