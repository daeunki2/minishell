/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 22:28:58 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 19:51:12 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*prompt_line(void)
{
	char	*cwd;
	char	*prompt;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("getcwd");
		return (NULL);
	}
	prompt = ft_strjoin(cwd, ">");
	free(cwd);
	return (prompt);
}

void	print_welcome(void)
{
	printf("\033[1;33m");
	printf("\n");
	printf("      __S'il     __Vous    __Plaît      Duckyshell\n");
	printf("    <(o )_     <(o )_    <(o )_         by...\n");
	printf("     (  3 )     (  3 )    (  3 )        Daeun & Theo\n");
	printf("\033[1;34m");
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   ");
	printf("\033[1;32m");
	printf("Ecole42, Paris, ");
	printf("\033[1;34m");
	printf("█");
	printf("\033[1;37m");
	printf("█");
	printf("\033[1;31m");
	printf("█\n");
	printf("\033[0m");
	printf("\n");
}
