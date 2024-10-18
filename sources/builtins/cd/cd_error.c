/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:21:45 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 17:21:45 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd_nonexist_error(char *str)
{
	g_exit_stat = 1;
	write(2, "bash: cd: ", 10);
	write(2, str, ft_strlen(str));
	write(2, ": No such file or directory\n", 28);
}

void	cd_permission_error(char *str)
{
	g_exit_stat = 1;
	write(2, "bash: cd: ", 10);
	write(2, str, ft_strlen(str));
	write(2, ": Permission denied\n", 20);
}

void	cd_dir_error(char *str)
{
	g_exit_stat = 1;
	if (errno == 13)
	{
		cd_permission_error(str);
		return ;
	}
	write(2, "bash: cd: ", 10);
	write(2, str, ft_strlen(str));
	write(2, ": Not a directory\n", 18);
}

int	invalid_cd(char *path)
{
	int	i;

	i = 0;
	while (path[i])
	{
		if (i != 0 && path[i] == '~')
			return (1);
		i++;
	}
	return (0);
}
