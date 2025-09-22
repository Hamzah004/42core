/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 00:21:44 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/23 00:21:45 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int		fd;
	char	*buffer;

	fd = open("test", O_RDWR, 0644);
	while ((buffer = get_next_line(fd)) != NULL)
	{
		printf("%s", buffer);
		free(buffer);
	}
}
