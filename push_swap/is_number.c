/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:02:29 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/07 22:02:29 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	is_number(char *number)
{
	int	i;

	i = 0;
	if (number[i] == '+' || number[i] == '-')
		i++;
	if (number[i] == '\0')
		return (0);
	while (number[i] != '\0')
	{
		if (!(ft_isdigit(number[i])))
			return (0);
		i++;
	}
	return (1);
}
