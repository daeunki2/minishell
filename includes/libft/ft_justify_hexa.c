/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_justify_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:21:30 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:21:32 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_hexaflag_left(char *str, t_flags *flags, char c, unsigned int nb)
{
	int	ret;
	int	len;
	int	i;
	int	v;

	v = 0;
	i = 0;
	len = ft_strlen(str);
	ret = 0;
	if (flags->hash == 1 && nb != 0)
	{
		if (c == 'x')
			ft_printstr("0x");
		else
			ft_printstr("0X");
		v = 2;
	}
	write(1, str, len);
	while (i++ < (flags->width - len - v))
		ret += write(1, " ", 1);
	return (ret + len + v);
}

int	ft_hexaflag_right_zero(char *str, t_flags *flags, char c, unsigned int nb)
{
	int	ret;
	int	len;
	int	i;
	int	v;

	i = 0;
	len = ft_strlen(str);
	ret = 0;
	v = 0;
	if (flags->hash == 1 && nb != 0)
		v = 2;
	while (i++ < (flags->width - len - v))
		ret += write(1, "0", 1);
	if (flags->hash == 1 && nb != 0)
	{
		if (c == 'x')
			ft_printstr("0x");
		else
			ft_printstr("0X");
		v = 2;
	}
	write(1, str, len);
	return (len + ret + v);
}

int	ft_hexaflag_right(char *str, t_flags *flags, char c, unsigned int nb)
{
	int	ret;
	int	len;
	int	i;
	int	v;

	v = 0;
	i = 0;
	len = ft_strlen(str);
	ret = 0;
	if (flags->hash == 1 && nb != 0)
		v = 2;
	while (i++ < (flags->width - len - v))
		ret += write(1, " ", 1);
	if (flags->hash == 1 && nb != 0)
	{
		if (c == 'x')
			ft_printstr("0x");
		else
			ft_printstr("0X");
		v = 2;
	}
	write(1, str, len);
	return (len + ret + v);
}

int	ft_hexaflag_zero(char *str, t_flags *flags)
{
	int	ret;
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	ret = 0;
	while (i++ <= (flags->width - len))
		ret += write(1, " ", 1);
	write(1, 0, 0);
	return (ret);
}
