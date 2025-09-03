/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 16:44:02 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/03 17:34:08 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	number_length_hexa(unsigned long number)
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

int	number_length(long number)
{
	int	i;

	i = 1;
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	return (i);
}

int	number_length_unsigned(unsigned int number)
{
	int	i;

	i = 1;
	while (number >= 10)
	{
		number /= 10;
		i++;
	}
	return (i);
}
