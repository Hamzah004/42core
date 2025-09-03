/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:44:29 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/03 17:35:02 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexa_ptr(unsigned long n, char format_char)
{
	char	*s;

	if (format_char == 'x')
		s = "0123456789abcdef";
	else
		s = "0123456789ABCDEF";
	if (n > 15)
		ft_hexa_ptr((n / 16), format_char);
	ft_putchar(s[n % 16]);
	return (number_length_hexa(n));
}

int	ft_putpointer(unsigned long number)
{
	int	count;

	count = 0;
	if (!number)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += ft_hexa_ptr(number, 'x');
	return (count);
}
