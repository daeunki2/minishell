/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:22:27 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 18:09:45 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_job **lst, int fd)
{
	t_job	*job;
	t_env	**env;
	t_env	*current;

	job = *lst;
	if (job->arg)
	{
		write(fd, "env: \'", 6);
		write(fd, job->arg[0], ft_strlen(job->arg[0]));
		write(fd, "\': No such file or directory\n", 29);
		return ;
	}
	env = get_env_address();
	current = (*env);
	while (current)
	{
		if (ft_strchr(current->str, '=') != NULL)
		{
			write(fd, current->str, ft_strlen(current->str));
			write(fd, "\n", 1);
		}
		current = current->next;
	}
}
