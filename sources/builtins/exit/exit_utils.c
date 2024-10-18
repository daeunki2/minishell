/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:22:33 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 17:22:33 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_overflow(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
		i++;
	i--;
	if (arg[0] == '-')
	{
		if (ft_atol(arg) % 10 != (arg[i] - '0') * -1)
			return (1);
	}
	else
	{
		if (ft_atol(arg) % 10 != (arg[i] - '0'))
			return (1);
	}
	return (0);
}
