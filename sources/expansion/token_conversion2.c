/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_conversion2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:25:25 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/24 10:28:59 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_allexp(t_lexeme *lexemes)//"$hone"
{
	bool	allexp;

	allexp = TRUE;
	while (lexemes)
	{
		if (lexemes->exp == FALSE || // it is sq 
		(lexemes->type == dq && lexemes->exp)) // dq and ($ is , '' no exist) (uq stay true)
			allexp = FALSE;
		lexemes = lexemes->next;
	}
	return (allexp);
}

static bool	quote_is_found(t_lexeme *lexemes)
{
	bool	found;

	found = FALSE;
	while (lexemes)
	{
		if (lexemes->type)
			found = TRUE;
		lexemes = lexemes->next;
	}
	return (found);
}

t_token	*token_to_etoken(t_token *old)// echo-> $home->null;
{
	t_lexeme	*lexemes;
	t_token		*result;
	int			*iword;

	lexemes = word_to_lexemes(old->str); // replace the quote so that we have a clean phrase and add tell us if it need to be expanded or not
	if (old->type != heredoc)
		replace_params(lexemes); // find $value and replace
	iword = lexemes_to_int(lexemes, old->type);// "$hone"
	result = iword_to_tokens(iword);//echo "$daeun"
	free(iword);
	if (!is_allexp(lexemes) && !result)
	{
		result = (t_token *)ft_calloc(1, sizeof (t_token));
		if (result)
		result->str = ft_strdup("");
	}// echo hell $home
	if (old->type == heredoc && quote_is_found(lexemes))
		result->hereq = 1;
	clear_lexemes(&lexemes, free);
	return (result);
}
