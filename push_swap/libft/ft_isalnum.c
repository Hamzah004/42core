/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:30:27 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/07 14:30:37 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
int	main(void)
{
	printf("me(alpha): %d\n",ft_isalnum('a'));
	printf("me(digit): %d\n",ft_isalnum('1'));
	printf("me(false): %d\n",ft_isalnum('+'));

	printf("original(alpha): %d\n",isalnum('a'));
	printf("original(digit): %d\n",isalnum('1'));
	printf("original(false): %d\n",isalnum('+'));
}*/
