/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_conversion1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:25:18 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/21 17:40:05 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*new_expanded_token(int *lexeme, int start, int len)
{
	t_token	*new;
	int		i;

	new = (t_token *)ft_calloc(1, sizeof (t_token));
	if (new == NULL)
		return (NULL);
	if (len)
		new->str = ft_calloc(sizeof(char), len + 1);
	else
		return (free(new), NULL);
	if (new->str == NULL)
		return (free(new), NULL);
	i = 0;
	while (i < len)
		new->str[i++] = (char)lexeme[start++];
	return (new);
}

void	copy_lexemes_to_int(int	*lexeme, t_lexeme *current, int *i, int *j)// j == 0 //echo
{
	*i = 0;
	while (current->str[*i])
	{
		if (is_ifs(current->str[*i]) && current->type == 0)// \n \t white space == word
		{
			lexeme[(*j)] = -1;//list
			(*j)++;
		}
		else
		{
			lexeme[(*j)] = current->str[*i];
			(*j)++;
		}
		(*i)++;
	}
}

/*returns an int array in which IFS will be translated into -1,
and used as separator to perform field splitting.
if not IFS, each element is stored as ascii value of the original character.
the returned array is NULL-terminated.*/
int	*lexemes_to_int(t_lexeme *lexemes, t_ttype type)
{
	t_lexeme	*current;
	int			*lexeme;
	int			i;
	int			j;

	j = 0;
	lexeme = (int *)ft_calloc(lexemelen(lexemes, type) + 1, sizeof(int));//"$hone"
	current = lexemes;
	while (current && lexeme)
	{
		while (current && current->exp == TRUE //"$homo" uq #homo == empty line
		&& current->p_found == FALSE && type != heredoc)//skip $value skip envp vlaue heredoc $ho333
			current = current->next;
		if (current == 0)
			break ;
		copy_lexemes_to_int(lexeme, current, &i, &j);
		current = current->next;
	}
	return (lexeme);
}

t_token	*iword_to_tokens(int *lexeme)//skip
{
	t_token	*result;
	int		start;
	int		len;

	result = 0;
	start = 0;
	while (lexeme[start])
	{
		while (lexeme[start] == -1)//white space
			start++;
		len = 0;
		while (lexeme[start + len] && lexeme[start + len] != -1)//len of the word
			len++;
		if (append_token(&result, new_expanded_token(lexeme, start, len)) == -1)
			return (result);
		start += len;
	}
	return (result);
}
