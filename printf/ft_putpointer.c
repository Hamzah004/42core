/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 16:44:29 by hbani-at          #+#    #+#             */
/*   Updated: 2025/09/02 16:54:36 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_putpointer(unsigned long long number)
{
    if (!number)
       return (ft_putstr("(nil)"));
    ft_putstr("0x");
    ft_hexa(number,'x');
    return (number_length_hexa(number + 2));
}