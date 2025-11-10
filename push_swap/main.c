/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:19:44 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/09 17:45:15 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <limits.h>

int	main(int ac, char **av)
{
	t_list	*stack_a;
	int		i;
	long	number;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			free_stack_and_exit(&stack_a);
		number = ft_atoi(av[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_stack_and_exit(&stack_a);
		init_stack(&stack_a, number);
		i++;
	}
	if (!(check_duplicate(stack_a)))
		free_stack_and_exit(&stack_a);
	ft_lstclear(&stack_a, free);
	return (0);
}
