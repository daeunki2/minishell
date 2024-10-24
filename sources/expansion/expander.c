/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:24:20 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 11:18:16 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	chop_lexeme_str(t_lexeme **crnt, t_lexeme **next)// echo-> $home-> null
{                                                        // echo $home->    
	int			i;
	t_lexeme	*new;

	i = 0;
	while ((*crnt)->type != 1 && (*crnt)->str[i])
	{
		if ((*crnt)->str[i] == '$' && (*crnt)->type != 1)
			i += len_lvname(&((*crnt)->str[i]));//4
		else
			while ((*crnt)->str[i] && (*crnt)->str[i] != '$')
				i++;
		if ((*crnt)->str[i])//echo ihate$HOME null >> echo ihate $home null
		{
			new = new_lexeme(ft_strdup(&((*crnt)->str[i])), (*crnt)->type);//new node 
			if (new)
			{
				(*crnt)->next = new;
				(*crnt)->next->next = (*next);
				(*crnt)->str[i] = '\0';
			}
		}
	}
}

void	split_expansions(t_lexeme *lexemes)// echo &hoem nulll with type
{
	t_lexeme	*crnt;
	t_lexeme	*next;

	crnt = lexemes;
	while (crnt)
	{
		next = crnt->next;
		chop_lexeme_str(&crnt, &next); //if ihate$home >> cutcut to ihate $home
		crnt = crnt->next;
	}
	while (lexemes)
	{
		if (lexemes->str[0] == '$' \
			&& lexemes->str[1] != '\0' \
			&& lexemes->type != 1)// ""/ 
			lexemes->exp = TRUE; // if there is a dollar sign and the type is 1 so sq , we put exp to TRUE and will use it after
		lexemes = lexemes->next;
	}
}

void	replace_tokens(t_token **tokens, t_token **expanded, \
t_token **next, t_token **prev)// odiginal modify  2nd node, first. 
{
	if (*prev == 0)
		*tokens = *expanded;// first node 
	else
		(*prev)->next = *expanded;
	while ((*expanded)->next)
		(*expanded) = (*expanded)->next;
	(*expanded)->next = *next;
	*prev = *expanded;
}// connect the expanded token(s) to origin token 


int	treat_empty_exp(t_token **tokens, t_token **crnt, \
t_token **next, t_token **prev)
{
	if ((*crnt)->type == in || (*crnt)->type == out || (*crnt)->type == append)
	{
		(*crnt)->type = amb_redir;
		*prev = *crnt;
		*crnt = *next;
		return (-1);
	}
	else if (*prev == 0)
		*tokens = *next;
	else
		(*prev)->next = *next;
	return (0);
}

void	expansion(t_token **tokens)
{
	t_token	*crnt;
	t_token	*next;
	t_token	*prev;
	t_token	*expanded;

	prev = 0;
	crnt = *tokens;
	while (crnt)
	{
		next = crnt->next;
		expanded = token_to_etoken(crnt); //TRY TO expande token
		if (expanded)
			expanded->type = crnt->type;//COpy he origin type
		if (expanded)
			replace_tokens(tokens, &expanded, &next, &prev);
		else if (!expanded)
		{
			if (treat_empty_exp(tokens, &crnt, &next, &prev))
				continue ;
		}
		free((free(crnt->str), crnt));
		crnt = next;
	}
}
