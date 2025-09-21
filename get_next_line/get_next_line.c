/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:33:12 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/21 21:38:52 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*result;

	if (!s1)
		s1 = ft_strdup("");
	if (!s1)
		return (NULL);
	result = ft_strjoin(s1, s2);
	free(s1);
	return (result);
}

static char	*get_line(char *stash)
{
	char	*line;
	size_t	i;

	if (!stash || !*stash)
		return (NULL);
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	line = ft_substr(stash, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*new_stash(char *stash)
{
	size_t	i;
	char	*new_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	new_stash = ft_substr(stash, i, ft_strlen(stash) - i);
	free(stash);
	if (!new_stash || new_stash[0] == '\0')
	{
		free(new_stash);
		return (NULL);
	}
	return (new_stash);
}

static char	*read_file(int fd, char *stash, char *buffer)
{
	ssize_t	bytes_read;

	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(stash, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stash = ft_strjoin_free(stash, buffer);
		if (!stash)
		{
			free(buffer);
			return (NULL);
		}
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	stash = read_file(fd, stash, buffer);
	if (!stash)
		return (NULL);
	free(buffer);
	line = get_line(stash);
	stash = new_stash(stash);
	return (line);
}
