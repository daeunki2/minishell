/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:27:38 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:27:40 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_calloc_gnl(size_t elementSize, size_t elementCount)
{
	char	*ret;
	size_t	len;

	len = 0;
	ret = (char *)malloc(elementSize * elementCount);
	if (!ret)
		return (NULL);
	while (len < elementCount)
	{
		ret[len] = '\0';
		len++;
	}
	return (ret);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		sizetotal;
	char	*res;
	int		i;
	int		j;

	i = 0;
	sizetotal = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (sizetotal + 1));
	if (!res || !s1 || !s2)
		return (NULL);
	while (s1[i] != 0)
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
		res[i++] = s2[j++];
	res[sizetotal] = 0;
	free(s1);
	return (res);
}

int	ft_strchr_gnl(char *str, char find)
{
	while (*str)
	{
		if (*str == find)
			return (1);
		str++;
	}
	return (0);
}
