/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_substr_len.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:25:42 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 19:19:57 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_op(char c)
{
	if (c == '>' || c == '<' || c == '|')
		return (1);
	else
		return (0);
}

bool	is_blank(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int	token_op_len(char *line, int start, int *quote_info)
{
	int	len;

	len = 0;
	if (line[start] == '<' && !quote_info[start])
	{
		if (line[start + 1] == '<' && !quote_info[start + 1])
			len = 2;
		else
			len = 1;
	}
	else if (line[start] == '>')
	{
		if (line[start + 1] == '>' && !quote_info[start + 1])
			len = 2;
		else
			len = 1;
	}
	else if (line[start] == '|')
		len = 1;
	return (len);
}

int	token_word_len(char *line, int start, t_ttype *type, int *quote_info)
{
	int	len;

	len = 0;
	while (!((is_op(line[start + len]) || is_blank(line[start + len]))
			&& !quote_info[start + len])
		&& line[start + len])
		len++;
	*type = word;
	return (len);
}
