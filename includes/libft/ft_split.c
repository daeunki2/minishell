/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:25:24 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:25:24 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_lenght(char const *s, char c)
{
	int	count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	return (count);
}

int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			return (count);
		count++;
		while (s[i] && s[i] != c)
			i++;
		if (!s[i])
			return (count);
	}
	return (count);
}

char	*word_cpy(char *dest, char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	*ft_free(char **str, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free (str[i]);
		i++;
	}
	free (str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (ret == NULL || s == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ret[j] = (char *)malloc(sizeof(char) * word_lenght(&s[i], c) + 1);
			if (ret[j] == NULL)
				return (ft_free(ret, j));
			ret[j] = word_cpy(ret[j], &s[i], c);
			i += word_lenght(&s[i], c);
			j++;
		}
		else
			i++;
	}
	ret[j] = NULL;
	return (ret);
}
