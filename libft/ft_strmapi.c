/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 18:38:00 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/16 21:57:47 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int i, char c))
{
	char	*array;
	size_t	i;

	i = 0;
	array = (char *)malloc(ft_strlen(s) + 1);
	while (s[i] != '\0')
	{
		array[i] = f(i, s[i]);
		i++;
	}
	array[i] = '\0';
	return (array);
}
/*
int	main(void)
{
	printf("%s",ft_strmapi("abc", f));
}*/
