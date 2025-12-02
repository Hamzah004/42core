/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:10:01 by hbani-at          #+#    #+#             */
/*   Updated: 2025/12/02 17:10:01 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if ((*stack)->next == NULL)
		return ;
	if (!stack || !*stack)
		return ;
	first = *stack;
	*stack = first->next;
	last = ft_lstlast(*stack);
	last->next = first;
	first->next = NULL;
}

void	rotate_a(t_list **stack_a)
{
	rotate(stack_a);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_list **stack_b)
{
	rotate(stack_b);
	ft_putendl_fd("rb", 1);
}
