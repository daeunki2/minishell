/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:24:27 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/21 13:42:46 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*IFS characters are '\n', '\t' and ' ' by default in POSIX shell.*/
bool	is_ifs(char c)
{
	if (c == '\n' || c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

int	len_lvname(char *str)//validate the str
{
	int	i;

	if (ft_isdigit(str[1]) || str[1] == '?') //$?, $12
		return (2);//fail
	i = 1;
	while (ft_isalnum(str[i]) || str[i] == '_')//$home_theo 
		i++;
	return (i);//give back the len of "$name of value"
}
