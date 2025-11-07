/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:19:44 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/05 14:55:39 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>

int	main(int ac, char **av)
{
	int		i;
	long	number;

	if (ac == 1)
		return (0);
	i = 1;
	while (av[i])
	{
		if (!is_number(av[i]))
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		number = ft_atoi(av[i]);
		if (number > INT_MAX || number < INT_MIN)
		{
			ft_putendl_fd("Error", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
