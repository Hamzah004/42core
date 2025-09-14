/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 13:33:12 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/13 19:35:31 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	ft_check(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

static char	*get_line(char *stash)
{
	size_t	i;
	char	*ss;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if (stash[i] == '\n')
		i++;
	ss = ft_substr(stash, 0, i);
	if (!ss)
		return (NULL);
	return (ss);
}

char	*read_file(ssize_t offset, char *buffer, char *stash, int fd)
{
	char	*old_stash;

	while (offset > 0)
	{
		offset = read(fd, buffer, BUFFER_SIZE);
		if (offset > 0)
			buffer[offset] = '\0';
		if (offset == -1)
		{
			free(stash);
			free(buffer);
			return (NULL);
		}
		old_stash = stash;
		stash = ft_strjoin(stash, buffer);
		free(old_stash);
		if (ft_check(stash, '\n'))
			break ;
	}
	free(buffer);
	return (get_line(stash));
}

static char	*new_stash(char *stash)
{
	size_t	i;
	char	*old_stash;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	old_stash = stash;
	stash = ft_substr(stash, i, ft_strlen(stash) - i + 1);
	free(old_stash);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*line;
	ssize_t		offset;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	offset = 1;
	if (!stash)
		stash = ft_strdup("");
	line = read_file(offset, buffer, stash, fd);
	stash = new_stash(stash);
	return (line);
}
