/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <hbani-at@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:39:42 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/21 17:56:26 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdatomic.h>
#include <stdint.h>
#include <stdio.h>

static size_t	count_words(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_result(char **result, size_t count)
{
	while (count--)
	{
		free(result[count]);
	}
	free(result);
}

static int	fill_result(char **result, const char *s, char c)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > start)
		{
			result[j] = ft_substr(s, start, i - start);
			if (!result[j])
				return (free_result(result, j), 0);
			j++;
		}
	}
	result[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**result;

	result = malloc(sizeof(char *) * count_words(s, c) + 1);
	if (!result)
		return (NULL);
	if (!fill_result(result, s, c))
		return (NULL);
	return (result);
}

int	main(void)
{
	size_t		i;
	char const	*s;
	char		**e;

	i = 0;
	s = "this is hamzah from 42";
	e = ft_split(s, ' ');
	while (e[i] != (void *)0)
	{
		printf("%s\n", e[i]);
		i++;
	}
}
