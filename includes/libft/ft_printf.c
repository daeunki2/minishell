/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:24:34 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:24:36 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	iterate(const char *str, t_flags *flags, va_list args)
{
	int	i;
	int	len;
	int	format;

	len = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == '%')
		{
			format = ft_re_setflags(flags, &str[i + 1], args);
			len += ft_checktype(args, str[i + 1 + format], flags);
			i += format + 1;
		}
		else
			len += write(1, &str[i], 1);
	}
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;
	t_flags	*flags;

	if (!str)
		return (-1);
	flags = create_struct();
	va_start(args, str);
	len = iterate(str, flags, args);
	va_end(args);
	free(flags);
	return (len);
}
