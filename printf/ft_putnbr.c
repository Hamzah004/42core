/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:01:03 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/03 17:13:41 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	len = number_length(number) + sign;
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
/*#include <limits.h>
int	main (void)
{
		int result = ft_printf(" %d ", INT_MIN);
		printf("%d",result);
}*/