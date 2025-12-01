/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:09:54 by hbani-at          #+#    #+#             */
/*   Updated: 2025/11/01 19:15:06 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

int		is_sorted(t_list *stack_a);
void	init_stack(t_list **stack_a, int number);
char	*push_swap(char *input);
void	push(t_list **stack_a, t_list **stack_b);
void	rotate(t_list **stack);
void	swap(t_list **stack);
void	rev_rotate(t_list **stack);
void	free_stack_and_exit(t_list **stack);
int		is_number(char *number);
int		check_duplicate(t_list *node);
int		find_max(t_list *node);
void	mini_sort(t_list **stack_a);
#endif
