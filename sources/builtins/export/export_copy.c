/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:05:26 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/29 10:32:28 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*create_new_node(const char *str)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);
	new_node->str = ft_strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->next = NULL;
	return (new_node);
}

void	append_node(t_env **new_head, t_env *new_node)
{
	t_env	*temp;

	if (!*new_head)
	{
		*new_head = new_node;
	}
	else
	{
		temp = *new_head;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

t_env	*copy_env_list(t_env *head)
{
	t_env	*new_head;
	t_env	*new_node;

	new_head = NULL;
	if (!head)
		return (NULL);
	while (head)
	{
		new_node = create_new_node(head->str);
		if (!new_node)
		{
			free_env_list(&new_head);
			return (NULL);
		}
		append_node(&new_head, new_node);
		head = head->next;
	}
	return (new_head);
}

void	free_env_list(t_env **head)
{
	t_env	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->str);
		free(tmp);
	}
}

void	clear_temp_env(t_env *head)
{
	t_env	*current;
	t_env	*next;

	current = head;
	while (current)
	{
		next = current->next;
		if (current->str)
			free(current->str);
		free(current);
		current = next;
	}
}
