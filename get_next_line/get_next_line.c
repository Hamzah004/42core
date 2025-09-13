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

static char	*get_line(char *stash) // helper function to get the line in each time
{
	size_t	i;

	i = 0;
	while (stash[i] != '\n')
		i++;

	return (ft_substr(stash, 0, i + 1));
}

char	*get_next_line(int fd)
{
	char	*buffer;
	static char	*stash;
	ssize_t	offset;

	if (fd == -1)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return NULL;
	offset = 1;
	if (!stash)
		stash = ft_strdup("");
	while (offset > 0)
	{
		offset = read(fd, buffer, BUFFER_SIZE);
		if (offset > 0)
			buffer[offset] = '\0';
		// I used this move to dianamicly make stash start pointing to a new allocated memory reference, and free the old memory reference
		char	*old_stash = stash;
		stash = ft_strjoin(stash,buffer);
		free(old_stash);
		if (ft_strchr(stash, '\n'))
			break;
	}
	free(buffer);
	return (get_line(stash));
}
