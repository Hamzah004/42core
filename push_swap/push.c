/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:00:13 by hbani-at          #+#    #+#             */
/*   Updated: 2025/12/02 17:00:13 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*tmp;

	if (!src || !*src)
		return ;
	tmp = *src;
	*src = tmp->next;
	ft_lstadd_front(dest, tmp);
}

void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putendl_fd("pb", 1);
}

void	push_to_a(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putendl_fd("pa", 1);
}
