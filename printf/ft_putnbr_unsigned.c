/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:53:47 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/31 21:00:59 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr_unsigned(unsigned int number)
{
	int	len;

	len = number_length(number);
	if (number <= 9)
		ft_putchar(number + '0');
	if (number > 9)
	{
		ft_putnbr_unsigned(number / 10);
		ft_putnbr_unsigned(number % 10);
	}
	return (len);
}
