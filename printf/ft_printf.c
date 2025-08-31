/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:03:23 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/30 00:04:46 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

int	ft_printf_fromat_output(va_list list, char format_char)
{
	int	val;

	val = 0;
	if (format_char == 'c')
		val = ft_putchar(va_arg(list,int));
	else if (format_char == 's')
		val = ft_putstr(va_arg(list,char *));
	else if (format_char == 'd' || format_char == 'i')
		val = ft_putnbr(va_arg(list, int));
	return (val);
}

int ft_printf(const char *format, ...)
{
	va_list	list;
	int	i;
	int	printf_output_len;

	i = 0;
	printf_output_len = 0;
	va_start(list, format);
	if (!format)
		return -1;
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

int	main(void)
{
	int	result = ft_printf("%d",-123456);
	printf("\n");
	printf("%d", result);
}
