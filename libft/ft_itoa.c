/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 19:00:20 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/11 23:10:56 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_number_length(long n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		sign;
	long	number;
	char	*s;
	int		len;

	sign = 0;
	number = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (number < 0)
		sign = 1;
	if (sign)
		number = -number;
	len = get_number_length(number);
	s = (char *)malloc(len + sign + 1);
	if (sign)
		s[0] = '-';
	s[len + sign] = '\0';
	while (number > 0)
	{
		s[(len--) + sign - 1] = number % 10 + '0';
		number /= 10;
	}
	return (s);
}
/*
 int	main(void)
 {
		printf("%s", 	ft_itoa(134));
 }*/
