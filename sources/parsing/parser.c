/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:26:11 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 11:52:39 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_type(t_token *current, t_token *next)
{
	if (next->type != word && next->type != pipe_op)
	{
		next->next->type = next->type;
		current->next = next->next;
		next->next = NULL;
		free(next->str);
		free(next);
	}
}

t_token	*parse_tokens(t_token **lst, void (*del)(void *))
{
	t_token	*current;
	t_token	*result;
	t_token	*temp;
	t_token	*next;

	if (lst == 0 || del == 0 || *lst == 0)
		return (NULL);
	result = *lst;
	current = *lst;
	if (current->type != word && current->next)
	{
		temp = current;
		current->next->type = current->type;
		current = current->next;
		result = result->next;
		temp->next = NULL;
		free((free(temp->str), temp));
	}
	while (current && current->next)
	{
		next = current->next;
		change_type(current, next);
		current = current->next;
	}
	return (result);
}
