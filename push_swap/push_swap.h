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
void	push_to_a(t_list **stack_b, t_list **stack_a);
void	push_to_b(t_list **stack_a, t_list **stack_b);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	free_stack_and_exit(t_list **stack);
int		is_number(char *number);
int		check_duplicate(t_list *node);
int		find_max(t_list *node);
int		find_min_pos(t_list *node);
void	mini_sort(t_list **stack_a, t_list **stack_b);
#endif
