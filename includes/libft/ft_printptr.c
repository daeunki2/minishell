/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:24:56 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:28:39 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	lenhexptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	while (ptr > 0)
	{
		ptr >>= 4;
		i++;
	}
	return (i);
}

char	*ft_ptoa(unsigned long long nbr, t_flags *flags)
{
	char	*array;
	int		i;
	int		len;

	len = lenhexptr(nbr);
	if (flags->precisize > len)
		len = flags->precisize;
	array = (char *)malloc(sizeof(char) * len + 1);
	if (!array)
		return (0);
	array[len] = '\0';
	i = len - 1;
	while (nbr > 0)
	{
		array[i] = "0123456789abcdef"[nbr % 16];
		nbr /= 16;
		i--;
	}
	while (i >= 0)
	{
		array[i] = '0';
		i--;
	}
	return (array);
}

int	justify_putflags_precisize_ptr(t_flags *flags)
{
	int	ret;
	int	i;

	i = 0;
	ret = 0;
	if (flags->plus == 1)
		ft_integer_flag('+');
	else if (flags->plus == 0 && flags->space == 1)
		ft_integer_flag(' ');
	while (i++ < flags->width)
		ret += write(1, " ", 1);
	write(1, 0, 0);
	return (ret);
}

int	justifynills(t_flags *flags)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	if (flags->minus == 1)
		write(1, "(nil)", 5);
	while (i++ < (flags->width - 5))
		ret += write(1, " ", 1);
	if (flags->minus == 0)
		write(1, "(nil)", 5);
	return (ret + 5);
}

int	ft_printptr(unsigned long long ptr, t_flags *flags)
{
	int		ret;
	char	*str;

	str = ft_ptoa(ptr, flags);
	ret = 0;
	if (!ptr)
		ret += justifynills(flags);
	else if (flags->precision == 1 && ptr != 0)
		ret += justify_putflags_ptr(str, flags);
	else if (flags->precision == 0 && flags->zero == 1)
		ret += justify_putflags_zero_ptr(str, flags);
	else if (flags->precision == 0)
		ret += justify_putflags_ptr(str, flags);
	else if (ptr == 0 && flags->precision == 1 && flags->precisize == 0)
		ret += justify_putflags_precisize_ptr(flags);
	else if (ptr == 0 && flags->precisize > 0)
		ret += justify_putflags_zero_ptr(str, flags);
	free(str);
	return (ret);
}
