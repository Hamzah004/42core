/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 20:53:47 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/03 16:59:39 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsigned(unsigned int number)
{
	int	len;

	len = number_length_unsigned(number);
	if (number <= 9)
		ft_putchar(number + '0');
	if (number > 9)
	{
		ft_putnbr_unsigned(number / 10);
		ft_putnbr_unsigned(number % 10);
	}
	return (len);
}
