/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:26:51 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 17:26:51 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	**get_env_address(void)
{
	static t_env	*env;

	return (&env);
}

void	clear_env(void)
{
	t_env	*current;
	t_env	*next;

	current = *get_env_address();
	while (current)
	{
		next = current->next;
		if (current->str)
			free(current->str);
		free(current);
		current = next;
	}
}

void	init_surpressed_env(void)
{
	char	*pwd;
	char	*line;
	t_env	**env;

	env = get_env_address();
	*env = ft_calloc(1, sizeof (t_env));
	(*env)->str = ft_strdup("_=/usr/bin/env");
	pwd = getcwd(NULL, 0);
	if (pwd)
	{
		line = ft_strjoin("PWD=", pwd);
		free(pwd);
		add_to_env(line);
		free(line);
	}
	add_to_env("SHLVL=1");
}

void	init_env_var(char **envp)
{
	int		i;
	t_env	**env;
	t_env	*current;

	env = get_env_address();
	if (!envp[0])
	{
		init_surpressed_env();
		return ;
	}
	*env = (t_env *)ft_calloc(1, sizeof (t_env));
	(*env)->str = ft_strdup("_=/usr/bin/env");
	current = (*env);
	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "_=", 2) != 0)
		{
			current->next = (t_env *)ft_calloc(1, sizeof (t_env));
			current->next->str = ft_strdup(envp[i]);
			current = current->next;
		}
		i++;
	}
}
