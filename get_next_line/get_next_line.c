/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:46:10 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/12 01:59:36ani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_line(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	while (stash[i] != '\n')
		i++;
	line = malloc(i + 1);
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*stash;
	ssize_t	offset;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	offset = read(fd, buffer, BUFFER_SIZE);
	if (!stash)
		stash = ft_strdup("");
	while (offset > 0 && buffer)
	{
		 stash = ft_strjoin(stash,buffer);
		if (ft_strchr(stash, '\n'))
			return (get_line(stash));
	}
	buffer[offset] = '\0';
	return (NULL);
}