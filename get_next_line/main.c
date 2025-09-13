/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 20:49:58 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/10 19:57:27by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// :NOTE: this is a main file used for testing,
// make sure to delete it after your done with the project

#include "get_next_line.h"
#include <stdio.h>

// void fun(int n)
// {
// 	static int	depth = 0;

// 	if (n == 0 || depth > 10)
// 		return ;
// 	printf("%d ", n);

// 	depth++;
// 	fun(n - 1);
// }

// int	main(void)
// {
// 	fun(10);
// // 	int fd;
// // 	fd = open("text.txt", O_CREAT | O_RDWR, 0644);
// // 	char s[] = "";
// // 	int number = read(fd, s, 12);
// // #include "stdio.h"

// // 	printf("%s\n%d\n", s, number);
// return (0);
// }

// Function with static variable
// int	fun(void)
// {
// 	static int	count;

// 	count++;
// 	return (count);
// }
int	main(void)
{
	int	fd = open("text.txt", O_RDWR, 0644);
	// char	*s = "this is a test\nthis is ssss";
	// printf("%s", get_line(s));
	printf("%s",get_next_line(fd));
}
