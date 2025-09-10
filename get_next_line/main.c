/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:49:58 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/10 19:40:00 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// :NOTE: this is a main file used for testing,
// make sure to delete it after your done with the project

#include "get_next_line.h"

int	main(void)
{
	int fd;
	fd = open("text.txt", O_CREAT | O_RDWR, 0644);
	char s[] = "";
	int number = read(fd, s, 12);
#include "stdio.h"

	printf("%s\n%d\n", s, number);
}