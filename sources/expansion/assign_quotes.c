/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:23:50 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 17:23:50 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*assign_single_quote(char *line, int *i, int *quote_info, t_qtype *type)
{
	int		start;
	int		size;
	char	*result;

	*type = sq;
	size = 0;
	(*i)++;
	start = *i;
	if (line[(*i)] == '\'' && quote_info[*i] == 1)
	{
		result = ft_substr(line, start, 0);
		return ((*i)++, result);
	}
	while (line[(*i)] && line[(*i)] != '\'' && quote_info[*i] == 1)
	{
		size++;
		(*i)++;
	}
	(*i)++;
	result = ft_substr(line, start, size);
	return (result);
}

char	*assign_double_quote(char *line, int *i, int *quote_info, t_qtype *type)
{
	int		start;
	int		size;
	char	*result;

	*type = dq;
	size = 0;
	(*i)++;
	start = *i;
	if (line[(*i)] == '\"' && quote_info[*i] == 2)
	{
		result = ft_substr(line, start, 0);
		return ((*i)++, result);
	}
	while (line[(*i)] && line[(*i)] != '\"' && quote_info[*i] == 2)
	{
		size++;
		(*i)++;
	}
	(*i)++;
	result = ft_substr(line, start, size);
	return (result);
}

char	*assign_non_quote(char *line, int *i, int *quote_info, t_qtype *type)
{
	int		start;
	int		size;
	char	*result;

	*type = uq;
	size = 0;
	start = *i;
	while (line[*i] && quote_info[*i] == 0)
	{
		(*i)++;
		size++;
	}
	result = ft_substr(line, start, size);
	return (result);
}
