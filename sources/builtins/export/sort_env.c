/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:00:56 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 18:04:35 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_sorted_envp(t_env *head)
{
	int		checker;
	t_env	*now;
	t_env	*last_pointer;
	char	*temp;

	last_pointer = NULL;
	while (1)
	{
		checker = 0;
		now = head;
		while (now->next != last_pointer)
		{
			if (ft_strncmp(now->str, now->next->str, ft_strlen(now->str)) > 0)
			{
				temp = now->str;
				now->str = now->next->str;
				now->next->str = temp;
				checker = 1;
			}
			now = now->next;
		}
		last_pointer = now;
		if (checker == 0)
			break ;
	}
}
