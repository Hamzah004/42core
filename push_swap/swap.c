/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:11:48 by hbani-at          #+#    #+#             */
/*   Updated: 2025/12/02 17:11:48 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*tmp;

	if ((*stack)->next == NULL)
		return ;
	if (!stack || !*stack)
		return ;
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	ft_lstadd_front(stack, tmp);
}

void	swap_a(t_list **stack_a)
{
	swap(stack_a);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_list **stack_b)
{
	swap(stack_b);
	ft_putendl_fd("sb", 1);
}
