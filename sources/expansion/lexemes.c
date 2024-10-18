/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexemes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theveste <theveste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:25:03 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/18 16:44:05 by theveste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexeme	*new_lexeme(char *str, t_qtype type)
{
	t_lexeme	*new;

	new = (t_lexeme *)ft_calloc(1, sizeof (t_lexeme));
	if (new == NULL)
		return (NULL);
	new->str = str;
	if (new->str == NULL)
		return (free(new), NULL);
	new->type = type;
	return (new);
}

int	append_lexeme(t_lexeme **lexemes, t_lexeme *new)
{
	t_lexeme	*current;

	if (new == 0)
		return (-1);
	if (*lexemes == 0)
		*lexemes = new;
	else
	{
		current = *lexemes;
		while (current->next)
			current = current->next;
		current->next = new;
	}
	return (0);
}

int	lexemelen(t_lexeme *lexemes, t_ttype type)
{
	t_lexeme	*current;
	int			i;
	int			count;

	count = 0;
	current = lexemes;
	while (current)
	{
		i = 0;
		while (current->str[i])
		{
			if (current->exp == TRUE && current->p_found == FALSE
				&& type != heredoc)
				break ;
			i++;
			count++;
		}
		current = current->next;
	}
	return (count);
}

t_lexeme	*word_to_lexemes(char *str)
{
	int			i;
	char		*newstr;
	t_lexeme	*result;
	t_qtype		type;
	int			*quote_info;

	quote_info = create_quote_info(str); // quote marking for double validation of quoting in the string
	if (quote_info == 0)
		return (NULL);
	result = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && quote_info[i] == 1) // double checking
			newstr = assign_single_quote(str, &i, quote_info, &type); // new str would be the string without the quote, and the type, sq, uq, dq, would be given to the new str
		else if (str[i] == '\"' && quote_info[i] == 2)
			newstr = assign_double_quote(str, &i, quote_info, &type);
		else if (str[i] && quote_info[i] == 0)
			newstr = assign_non_quote(str, &i, quote_info, &type);
		append_lexeme(&result, new_lexeme(newstr, type)); // we append the new unquoted string to a list, with the type given to, so that we can pass to the expansion and expand or not
	}
	split_expansions(result); // expanding
	return (free(quote_info), result);
}
