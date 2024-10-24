/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:25:10 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/21 14:39:54 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	replace_params(t_lexeme *lexemes)//echo ihate $home 
{
	t_lexeme	*current;
	char		*newstr;

	current = lexemes;
	while (current)
	{
		newstr = 0;
		if (current->exp == TRUE)
		{
			newstr = find_param(&(current->str[1]));//if you can find $home
			if (newstr)
			{
				current->p_found = TRUE;
				free(current->str);
				current->str = newstr;
			}
		}
		current = current->next;
	}
}
