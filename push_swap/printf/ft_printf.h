/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 00:04:30 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/03 17:14:57 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(int n);
int	ft_putnbr_unsigned(unsigned int number);
int	ft_hexa(unsigned int n, char format_char);
int	number_length(long number);
int	number_length_hexa(unsigned long number);
int	ft_putpointer(unsigned long number);
int	number_length_unsigned(unsigned int number);
#endif
