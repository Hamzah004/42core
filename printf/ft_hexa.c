/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:09:28 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/02 16:43:28 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	number_length_hexa(long number)
{
	int	i;

	i = 1;
	while (number >= 16)
	{
		number /= 16;
		i++;
	}
	return (i);
}

int	ft_hexa(unsigned int n, char format_char)
{
	char	*s;

	if (format_char == 'x')
		s = "0123456789abcdef";
	else
		s = "0123456789ABCDEF";
	if (n > 15)
		ft_hexa((n / 16), format_char);
	ft_putchar(s[n % 16]);
	return (number_length_hexa(n));
}
