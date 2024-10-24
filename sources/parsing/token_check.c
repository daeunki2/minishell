/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:46:02 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 11:52:25 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	token_error_check(t_token *tokens)
{
	if (tokens->type == pipe_op && tokens->next && \
		tokens->next->type == pipe_op)
	{
		print_parse_error(&tokens);
		return (1);
	}
	if (tokens->type != word && tokens->type != pipe_op)
	{
		if (tokens->next == NULL || tokens->next->type != word)
		{
			print_parse_error(&tokens);
			return (1);
		}
	}
	if (tokens->type == pipe_op && tokens->next && \
		tokens->next->type == pipe_op)
	{
		print_parse_error(&tokens);
		return (1);
	}
	return (0);
}

int	check_tokens(t_token *tokens)
{
	if (!tokens)
		return (0);
	if (tokens->type == pipe_op)
	{
		print_parse_error(&tokens);
		return (1);
	}
	while (tokens && tokens->str)
	{
		if (token_error_check(tokens))
			return (1);
		tokens = tokens->next;
	}
	return (0);
}

void	print_parse_error(t_token **input)
{
	t_token	*current;

	g_exit_stat = 2;
	current = *input;
	write(2, "bash: syntax error near unexpected token \'", 42);
	if (current->type >= in && current->type <= append)
	{
		if (current->next)
			write(2, current->next->str, ft_strlen(current->next->str));
	}
	else
		write(2, current->str, ft_strlen(current->str));
	write(2, "\'", 1);
	write(2, "\n", 1);
}
