/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/16 20:51:57 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/16 21:57:50 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void f(unsigned int i, char *c)
{
	c = c + i;
}
void	ft_striteri(char *s, void (*f)(unsigned int i, char* c))
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s);
		i++;
	}
}

int	main(void)
{
	char	*s = "abc";
	ft_striteri(s,f);
	printf("%s", s);
}
