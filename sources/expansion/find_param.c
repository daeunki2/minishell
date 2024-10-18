/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:24:46 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 17:24:46 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_param(char *p_name)
{
	char	*str;
	t_env	*env;

	env = *get_env_address();
	if (ft_strncmp(p_name, "?", 2) == 0)
		return (ft_itoa(g_exit_stat));
	str = 0;
	while (env)
	{
		if (ft_strncmp(env->str, p_name, ft_strlen(p_name)) == 0)
		{
			if (env->str[ft_strlen(p_name)] == '=')
			{
				str = ft_strdup(ft_strchr(env->str, '=') + 1);
				break ;
			}
		}
		env = env->next;
	}
	return (str);
}
