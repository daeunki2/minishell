/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:23:07 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 17:23:07 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(int fd)
{
	char	*print;

	print = getcwd(NULL, 0);
	if (!print)
	{
		ft_putstr_fd("pwd: error retrieving current directory: ", 2);
		ft_putstr_fd("getcwd: cannot access: ", 2);
		ft_putstr_fd("No such file or directory\n", 2);
	}
	else
	{
		ft_putstr_fd(print, fd);
		write(fd, "\n", 1);
		free(print);
	}
	return (0);
}
