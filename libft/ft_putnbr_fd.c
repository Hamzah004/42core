/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   by: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   created: 2025/08/17 21:53:34 by hbani-at          #+#    #+#             */
/*   updated: 2025/08/17 21:54:10 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd) // 1234
{
	long	number;

	number = n;
	if (number < 0)
	{
		ft_putchar_fd('-', fd);
		number *= -1;
	}
        if (n >= 0 && n <= 9)
                ft_putchar_fd(n + '0',fd);
	if (number > 9)
	{
		ft_putnbr_fd(number / 10,fd);
		ft_putnbr_fd(number % 10,fd);
	}
}
