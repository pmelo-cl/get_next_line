/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmelo-cl <pmelo-cl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:00:48 by pmelo-cl          #+#    #+#             */
/*   Updated: 2025/11/04 12:30:41 by pmelo-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

static char	*extract_line(char **storage)
{
	char	*line;
	char	*new_storage;
	char	*nl_pos;

	nl_pos = ft_strchr(*storage, '\n');
	if (nl_pos)
	{
		line = malloc(nl_pos - *storage + 2);
		ft_memcpy(line, *storage, nl_pos - *storage + 1);
		line[nl_pos - *storage + 1] = '\0';
		new_storage = ft_strdup(nl_pos + 1);
		free(*storage);
		*storage = new_storage;
	}
	else
	{
		line = ft_strdup(*storage);
		free(*storage);
		*storage = NULL;
	}
	return (line);
}

static char	*read_to_storage(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;
	char	*tmp;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free_memory(storage, buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(storage, buffer);
		free(storage);
		storage = tmp;
	}
	free(buffer);
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	if (!storage[fd])
		storage[fd] = ft_strdup("");
	storage[fd] = read_to_storage(fd, storage[fd]);
	if (!storage[fd] || !*storage[fd])
	{
		free(storage[fd]);
		storage[fd] = NULL;
		return (NULL);
	}
	line = extract_line(&storage[fd]);
	return (line);
}
