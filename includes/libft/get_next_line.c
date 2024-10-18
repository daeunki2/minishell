/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daeunki2 <daeunki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:27:43 by daeunki2          #+#    #+#             */
/*   Updated: 2024/10/17 15:27:45 by daeunki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = fetch_file(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	buffer = ft_reset(buffer);
	return (line);
}

char	*fetch_file(char *buffer, int fd)
{
	char	*storage;
	int		nb_bytes;

	if (!buffer)
		buffer = ft_calloc_gnl(1, 1);
	storage = ft_calloc_gnl(sizeof(char), (BUFFER_SIZE + 1));
	nb_bytes = 1;
	while (nb_bytes > 0)
	{
		nb_bytes = read(fd, storage, BUFFER_SIZE);
		if (nb_bytes == -1)
		{
			free(storage);
			return (NULL);
		}
		storage[nb_bytes] = '\0';
		buffer = ft_strjoin_gnl(buffer, storage);
		if (ft_strchr_gnl(storage, '\n') == 1)
			break ;
	}
	free(storage);
	return (buffer);
}

char	*ft_line(char *buffer)
{
	char	*line;
	int		len;

	len = 0;
	if (!buffer[len])
		return (NULL);
	while (buffer[len] && buffer[len] != '\n')
		len++;
	line = ft_calloc_gnl(sizeof(char), (len + 2));
	if (!line)
		return (NULL);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
	{
		line[len] = buffer[len];
		len++;
	}
	if (buffer[len] == '\n')
		line[len] = '\n';
	return (line);
}

char	*ft_reset(char *buffer)
{
	int		len;
	int		len_fetch;
	char	*ret;
	int		i;

	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (!buffer[len])
	{
		free(buffer);
		return (NULL);
	}
	len_fetch = ft_strlen(buffer);
	ret = ft_calloc_gnl(sizeof(char), (len_fetch - len + 1));
	if (!ret)
		return (NULL);
	len++;
	i = 0;
	while (buffer[len])
		ret[i++] = buffer[len++];
	free(buffer);
	return (ret);
}
