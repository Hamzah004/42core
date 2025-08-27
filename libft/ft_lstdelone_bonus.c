/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 21:15:00 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/25 16:19:22 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
/*
void	del(void *con)
{
	free(con);
}*/
/*
int	main(void)
{
	t_list	*node1 = ft_lstnew(ft_strdup("hello"));
	t_list	*lst = node1;
	t_list	*node2 = ft_lstnew(ft_strdup("world"));
	t_list	*node3 = ft_lstnew(ft_strdup("hamzah"));
	t_list	*node4 = ft_lstnew(ft_strdup("yazan"));
	t_list	*node5 = ft_lstnew(ft_strdup("mohammad"));
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = NULL;

	printf("before deletion\n");
	while (lst)
	{
		printf("%s\n",(char *)lst->content);
		lst = lst->next;
	}
	node1->next = node5;
	ft_lstdelone(node2, del);
	ft_lstdelone(node3, del);
	ft_lstdelone(node4, del);

	lst = node1;
	printf("after deletion\n");
	while (lst)
	{
		printf("%s\n",(char *)lst->content);
		lst = lst->next;
	}
}*/
