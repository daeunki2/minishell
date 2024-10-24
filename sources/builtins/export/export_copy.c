/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_copy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:05:26 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 16:11:49 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sorted_envp(t_env *head)
{
	int		checker;
	t_env	*current;
	t_env	*last_pointer;
	char	*temp;

	last_pointer = NULL;
	while (1)
	{
		checker = 0;
		current = head;
		while (current->next != last_pointer)
		{
			if (ft_strncmp(current->str, current->next->str, ft_strlen(current->str)) > 0)
			{
				temp = current->str;
				current->str = current->next->str;
				current->next->str = temp;
				checker = 1;
			}
			current = current->next;
		}
		last_pointer = current;
		if (checker == 0)
			break ;
	}
}

t_env	*create_new_node(const char *str)
{
	t_env	*new_node;

	new_node = (t_env *)malloc(sizeof(t_env));
	if (!new_node)
		return (NULL);

	new_node->str = strdup(str);
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
	t_env	*new_head = NULL;
	t_env	*current = head;
	t_env	*new_node;

	if (!head)
		return (NULL);
	while (current)
	{
		new_node = create_new_node(current->str);
		if (!new_node)
		{
			while (new_head)
			{
				t_env *tmp = new_head;
				new_head = new_head->next;
				free(tmp->str);
				free(tmp);
			}
			return (NULL);
		}
		append_node(&new_head, new_node);
		current = current->next;
	}
	return (new_head);
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

// t_env	*copy_env_list(t_env *head)
// {
// 	t_env	*new_head = NULL;
// 	t_env	*new_node = NULL;
// 	t_env	*current = head;
// 	t_env	*prev = NULL;

// 	if (!head)
// 		return (NULL);
// 	while (current)
// 	{
// 		new_node = (t_env *)malloc(sizeof(t_env));
// 		if (!new_node)
// 		{
// 			while (new_head)
// 			{
// 				t_env *tmp = new_head;
// 				new_head = new_head->next;
// 				free(tmp->str);
// 				free(tmp);
// 			}
// 			return (NULL);
// 		}
// 		new_node->str = strdup(current->str);
// 		if (!new_node->str)
// 		{
// 			free(new_node); // 새로 할당한 노드 해제
// 			while (new_head)
// 			{
// 				t_env *tmp = new_head;
// 				new_head = new_head->next;
// 				free(tmp->str);  // 문자열 메모리 해제
// 				free(tmp);       // 노드 메모리 해제
// 			}
// 			return (NULL);
// 		}
// 		new_node->next = NULL;
// 		if (!new_head)
// 			new_head = new_node;
// 		else
// 			prev->next = new_node;
// 		prev = new_node;
// 		current = current->next;
// 	}
// 	return (new_head);
// }