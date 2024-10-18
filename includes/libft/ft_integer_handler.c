/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_handler.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:20:50 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:20:53 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	justify_putflags_precisize(t_flags *flags, int n)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	if (n < 0)
		ft_integer_flag('-');
	if (n >= 0 && flags->plus == 1)
		ft_integer_flag('+');
	else if (n >= 0 && flags->plus == 0 && flags->space == 1)
		ft_integer_flag(' ');
	while (i++ < flags->width)
		ret += write(1, " ", 1);
	write(1, 0, 0);
	return (ret);
}

int	integer_handler(int n, t_flags *flags)
{
	int		len;
	int		ret;
	char	*str;

	ret = 0;
	len = ft_int_len(n);
	str = ft_itoa_printf(n, flags, len);
	if (n == 0)
		ret += justify_putflags_zero2(str, flags);
	else if (flags->precision == 1 && n != 0)
		ret += justify_putflags_integer(str, flags, n);
	else if (flags->precision == 0 && flags->zero == 1)
		ret += justify_putflags_zero(str, flags, n);
	else if (flags->precision == 0)
		ret += justify_putflags_integer(str, flags, n);
	free(str);
	return (ret);
}

/**
 * 	else if (n == 0 && flags->precision == 1 && flags->precisize == 0)
		ret += justify_putflags_precisize(flags, n);
	else if (n == 0 && flags->precisize > 0)
		ret += justify_putflags_zero(str, flags, n);
*/