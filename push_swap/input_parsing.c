/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:18:06 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/05 14:24:44 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"

int	input_parsing(char *str)
{
	int		i;
	char	**number;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	i = 0;
	number = ft_split(str, ' ');
	if (!number)
		return (1);
	while (number[i] != (void *)0)
	{
		int j = 0;
		if (number[i][j] == '+' || number[i][j] == '-')
		{
			j++;
		}
		if (number[i][j] == '\0')
			return (1);
		while (number[i][j])
		{
			if (!ft_isdigit(number[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
