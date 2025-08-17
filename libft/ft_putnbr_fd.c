/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 21:53:34 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/17 21:54:10 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	long	number;
	size_t	i;
	char	arr_number[10];

	number = n;
	i = 0;
	if (number < 0)
	{
		ft_putchar_fd('-',fd);
		number *= -1;
	}
	while (number > 9)
	{
		arr_number[i] = (number % 10) + '0';
		number = number / 10;
		i++;
	}
	if (number <= 9)
	{
		arr_number[i] = number + '0';
		i++;
	}
	while (arr_number[i] != '\0')
	{
		ft_putchar_fd(fd, arr_number[i]);
		i--;
	}
}
