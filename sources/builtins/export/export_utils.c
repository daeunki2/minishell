/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:22:54 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 17:55:34 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	first_is_valid(char c)
{
	if (c == '=')
		return (1);
	if (ft_isalpha(c) == 0 && c != '_')
		return (1);
	return (0);
}

int	middle_is_valid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\\')
			i++;
		if (str[i] == '=' && i == 0)
			return (1);
		if (str[i] == '=' && i != 0)
			break ;
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	middle_error_case(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] == '\\')
			i++;
		if (str[i] == '=' && i == 0)
			return (1);
		if (str[i] == '=' && i != 0)
		{
			break ;
		}
		if (ft_isalnum(str[i]) == 0 && str[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

void	export_error(char *str)
{
	write(2, "bash: export: \'", 15);
	write(2, str, ft_strlen(str));
	write(2, "\': not a valid identifier\n", 26);
	g_exit_stat = 1;
}

void	export_env(int fd)
{
	t_env	**env;
	t_env	*temp;
	t_env	*current;

	env = get_env_address();
	current = copy_env_list(*env);
	temp = current;
	ft_sorted_envp(current);
	if (!current)
		return ;
	while (current)
	{
		ft_putstr_fd("export ", fd);
		if ((ft_strchr(current->str, '=') != NULL && \
		*(ft_strchr(current->str, '=') + 1)) || \
		(ft_strchr(current->str, '=') == NULL))
			ft_putstr_fd(current->str, fd);
		else
			ft_putstr_fd(current->str, fd);
		ft_putstr_fd("\n", fd);
		current = current->next;
	}
	clear_temp_env(temp);
}
