/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:03:23 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/03 17:34:20 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	ft_printf_fromat_output(va_list list, char format_char)
{
	int	val;

	val = 0;
	if (format_char == 'c')
		val = ft_putchar(va_arg(list, int));
	else if (format_char == 's')
		val = ft_putstr(va_arg(list, char *));
	else if (format_char == 'd' || format_char == 'i')
		val = ft_putnbr(va_arg(list, int));
	else if (format_char == 'u')
		val = ft_putnbr_unsigned(va_arg(list, unsigned int));
	else if (format_char == 'x' || format_char == 'X')
		val = ft_hexa(va_arg(list, unsigned int), format_char);
	else if (format_char == 'p')
		val = ft_putpointer(va_arg(list, unsigned long));
	else if (format_char == '%')
		val = ft_putchar('%');
	return (val);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		i;
	int		printf_output_len;

	i = 0;
	printf_output_len = 0;
	va_start(list, format);
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			printf_output_len += ft_printf_fromat_output(list, format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			printf_output_len++;
		}
		i++;
	}
	va_end(list);
	return (printf_output_len);
}
