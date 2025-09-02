/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:03:23 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/02 17:06:20 by hbani-at         ###   ########.fr       */
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

#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>

void test_char(void)
{
    printf("=== Testing %%c ===\n");
    printf("ft_printf: ");
    int ft_ret1 = ft_printf("Char: %c\n", 'A');
    printf("printf:    ");
    int std_ret1 = printf("Char: %c\n", 'A');
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);

    printf("ft_printf: ");
    int ft_ret2 = ft_printf("Null char: %c\n", '\0');
    printf("printf:    ");
    int std_ret2 = printf("Null char: %c\n", '\0');
    printf("Return values - ft: %d, std: %d\n\n", ft_ret2, std_ret2);
}

void test_string(void)
{
    printf("=== Testing %%s ===\n");
    printf("ft_printf: ");
    int ft_ret1 = ft_printf("String: %s\n", "Hello World");
    printf("printf:    ");
    int std_ret1 = printf("String: %s\n", "Hello World");
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);

    printf("ft_printf: ");
    int ft_ret2 = ft_printf("Empty: %s\n", "");
    printf("printf:    ");
    int std_ret2 = printf("Empty: %s\n", "");
    printf("Return values - ft: %d, std: %d\n\n", ft_ret2, std_ret2);

    printf("ft_printf: ");
    int ft_ret3 = ft_printf("NULL: %s\n", (char *)NULL);
    printf("printf:    ");
    int std_ret3 = printf("NULL: %s\n", (char *)NULL);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret3, std_ret3);
}

void test_integers(void)
{
    printf("=== Testing %%d and %%i ===\n");
    printf("ft_printf: ");
    int ft_ret1 = ft_printf("Int: %d, %i\n", 42, -42);
    printf("printf:    ");
    int std_ret1 = printf("Int: %d, %i\n", 42, -42);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);

    printf("ft_printf: ");
    int ft_ret2 = ft_printf("Zero: %d\n", 0);
    printf("printf:    ");
    int std_ret2 = printf("Zero: %d\n", 0);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret2, std_ret2);

    printf("ft_printf: ");
    int ft_ret3 = ft_printf("Max: %d, Min: %d\n", INT_MAX, INT_MIN);
    printf("printf:    ");
    int std_ret3 = printf("Max: %d, Min: %d\n", INT_MAX, INT_MIN);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret3, std_ret3);
}

void test_unsigned(void)
{
    printf("=== Testing %%u ===\n");
    printf("ft_printf: ");
    int ft_ret1 = ft_printf("Unsigned: %u\n", 42U);
    printf("printf:    ");
    int std_ret1 = printf("Unsigned: %u\n", 42U);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);

    printf("ft_printf: ");
    int ft_ret2 = ft_printf("Zero: %u\n", 0U);
    printf("printf:    ");
    int std_ret2 = printf("Zero: %u\n", 0U);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret2, std_ret2);

    printf("ft_printf: ");
    int ft_ret3 = ft_printf("Max: %u\n", UINT_MAX);
    printf("printf:    ");
    int std_ret3 = printf("Max: %u\n", UINT_MAX);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret3, std_ret3);
}

void test_hex(void)
{
    printf("=== Testing %%x and %%X ===\n");
    printf("ft_printf: ");
    int ft_ret1 = ft_printf("Hex: %x, %X\n", 255, 255);
    printf("printf:    ");
    int std_ret1 = printf("Hex: %x, %X\n", 255, 255);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);

    printf("ft_printf: ");
    int ft_ret2 = ft_printf("Zero: %x, %X\n", 0, 0);
    printf("printf:    ");
    int std_ret2 = printf("Zero: %x, %X\n", 0, 0);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret2, std_ret2);

    printf("ft_printf: ");
    int ft_ret3 = ft_printf("Large: %x, %X\n", 0xDEADBEEF, 0xDEADBEEF);
    printf("printf:    ");
    int std_ret3 = printf("Large: %x, %X\n", 0xDEADBEEF, 0xDEADBEEF);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret3, std_ret3);
}

void test_pointer(void)
{
    printf("=== Testing %%p ===\n");
    int test_var = 42;
    char *test_str = "test";
    
    printf("ft_printf: ");
    int ft_ret1 = ft_printf("Pointer: %p\n", &test_var);
    printf("printf:    ");
    int std_ret1 = printf("Pointer: %p\n", &test_var);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);

    printf("ft_printf: ");
    int ft_ret2 = ft_printf("String ptr: %p\n", test_str);
    printf("printf:    ");
    int std_ret2 = printf("String ptr: %p\n", test_str);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret2, std_ret2);

    printf("ft_printf: ");
    int ft_ret3 = ft_printf("NULL ptr: %p\n", (void *)NULL);
    printf("printf:    ");
    int std_ret3 = printf("NULL ptr: %p\n", (void *)NULL);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret3, std_ret3);
}

void test_percent(void)
{
    printf("=== Testing %%%% ===\n");
    printf("ft_printf: ");
    int ft_ret1 = ft_printf("Percent: %%\n");
    printf("printf:    ");
    int std_ret1 = printf("Percent: %%\n");
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);

    printf("ft_printf: ");
    int ft_ret2 = ft_printf("Multiple: %% %% %%\n");
    printf("printf:    ");
    int std_ret2 = printf("Multiple: %% %% %%\n");
    printf("Return values - ft: %d, std: %d\n\n", ft_ret2, std_ret2);
}

void test_mixed(void)
{
    printf("=== Testing Mixed Formats ===\n");
    printf("ft_printf: ");
    int ft_ret1 = ft_printf("Mixed: %c %s %d %u %x %p %%\n", 'A', "test", -42, 42U, 255, &ft_ret1);
    printf("printf:    ");
    int std_ret1 = printf("Mixed: %c %s %d %u %x %p %%\n", 'A', "test", -42, 42U, 255, &std_ret1);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);
}

void test_edge_cases(void)
{
    printf("=== Testing Edge Cases ===\n");
    
    // Test NULL format
    printf("NULL format test:\n");
    printf("ft_printf: ");
    int ft_ret1 = ft_printf(NULL);
    printf("printf:    ");
    int std_ret1 = printf((char *)NULL);
    printf("Return values - ft: %d, std: %d\n\n", ft_ret1, std_ret1);
    
    // Test empty format
    printf("ft_printf: ");
    int ft_ret2 = ft_printf("");
    printf("printf:    ");
    int std_ret2 = printf("");
    printf("Return values - ft: %d, std: %d\n\n", ft_ret2, std_ret2);
    
    // Test format with no specifiers
    printf("ft_printf: ");
    int ft_ret3 = ft_printf("No specifiers here!");
    printf("printf:    ");
    int std_ret3 = printf("No specifiers here!");
    printf("Return values - ft: %d, std: %d\n\n", ft_ret3, std_ret3);
}

int main(void)
{
    printf("Testing ft_printf implementation\n");
    printf("=================================\n\n");
    
    test_char();
    test_string();
    test_integers();
    test_unsigned();
    test_hex();
    test_pointer();
    test_percent();
    test_mixed();
    test_edge_cases();
    
    printf("=== Testing Complete ===\n");
    return (0);
}
