/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:01:03 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/31 21:01:02 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	number_length(int number)
{
	int	i;

	i = 1;
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	long	number;
	int		len;
	int		sign;

	number = n;
	sign = 0;
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
		sign = 1;
	}
	len = number_length(number);
	if (sign)
		len = number_length(number) + 1;
	if (number >= 0 && number <= 9)
	{
		ft_putchar(number + '0');
	}
	if (number > 9)
	{
		ft_putnbr(number / 10);
		ft_putnbr(number % 10);
	}
	return (len);
}
