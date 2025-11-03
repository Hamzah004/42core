/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 21:09:28 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/03 17:34:20 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
