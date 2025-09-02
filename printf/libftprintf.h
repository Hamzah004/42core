/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:04:30 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/02 16:52:14 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <ctype.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c);
int	ft_putstr(char	*s);
int	ft_putnbr(int n);
int	number_length(long number);
int	ft_putnbr_unsigned(unsigned long number);
int ft_hexa(unsigned int n, char format_char);
int	number_length_hexa(long number);
int ft_putpointer(unsigned long long number);
#endif
