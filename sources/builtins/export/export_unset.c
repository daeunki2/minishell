/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:22:49 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 17:22:49 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pop_env_node(t_env **env, t_env **current, t_env **prev)
{
	if (*prev == 0)
	{
		(*env) = (*current)->next;
		free((free((*current)->str), (*current)));
		(*current) = *env;
	}
	else
	{
		(*prev)->next = (*current)->next;
		free((free((*current)->str), (*current)));
		(*current) = (*prev)->next;
	}
}

int	export_unset(char *key)
{
	t_env	**env;
	t_env	*current;
	t_env	*prev;

	prev = 0;
	env = get_env_address();
	current = (*env);
	while (current)
	{
		if (unset_strncmp(current->str, key, ft_strlen(key)) == -1000)
			return (1);
		if (unset_strncmp(current->str, key, ft_strlen(key)) == 0)
		{
			pop_env_node(env, &current, &prev);
			return (0);
		}
		prev = current;
		current = current->next;
	}
	return (0);
}
