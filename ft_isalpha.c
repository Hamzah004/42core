/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 20:41:33 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/06 20:41:34 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <ctype.h>
// #include <stdio.h>

int	ft_isalpha(int arg)
{
	if ((arg >= 97 && arg <= 122) || (arg >= 65 && arg <= 90))
		return (1024);
	return (0);
}
/*
int main (void)
{
	printf("%d\n",isalpha(34));
	printf("\n%d",ft_isalpha(90));
}*/
