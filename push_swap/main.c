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
#include <stdlib.h>

static void	free_list_and_exit(t_list **stack)
{
	if (stack && *stack)
		ft_lstclear(stack, free);
	ft_putendl_fd("Error", 2);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*new_node;
	int		*content;
	int		i;
	long	number;

	if (ac < 2)
		return (0);
	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		if (!is_number(av[i]))
			free_list_and_exit(&stack_a);
		number = ft_atoi(av[i]);
		if (number > INT_MAX || number < INT_MIN)
			free_list_and_exit(&stack_a);
		content = malloc(sizeof(int));
		if (!content)
			free_list_and_exit(&stack_a);
		*content = (int)number;
		new_node = ft_lstnew(content);
		if (!new_node)
		{
			free(content);
			free_list_and_exit(&stack_a);
		}
		ft_lstadd_back(&stack_a, new_node);
		i++;
	}
	ft_lstclear(&stack_a, free);
	return (0);
}
