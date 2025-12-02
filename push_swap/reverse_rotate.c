/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:05:26 by hbani-at          #+#    #+#             */
/*   Updated: 2025/12/02 17:09:49 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*last;
	t_list	*tmp;

	if ((*stack)->next == NULL)
		return ;
	if (!stack || !*stack)
		return ;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	ft_lstadd_front(stack, last);
	tmp->next = NULL;
}

void	reverse_rotate_a(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_putendl_fd("rra", 1);
}

void	reverse_rotate_b(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_putendl_fd("rrb", 1);
}
