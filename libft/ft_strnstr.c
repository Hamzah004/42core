/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 15:27:43 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/08 15:33:43 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	little_len;

	little_len = ft_strlen(little);
	i = 0;
	if (*little == '\0')
		return ((char *)&big[i]);
	while (big[i] != '\0' && (i + little_len) <= len)
	{
		j = 0;
		while (little[j] != '\0' && (big[i + j] == little[j]))
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}

/*
int	main(void)
{
char	*result;
int		test_num = 1;

printf("=== ft_strnstr Tests ===\n\n");

// Test 1: Basic functionality
printf("Test %d: Basic search\n", test_num++);
result = ft_strnstr("Hello World", "World", 11);
printf("ft_strnstr(\"Hello World\", \"World\", 11) = %s\n",
	result ? result : "NULL");
printf("Expected: World\n\n");

// Test 2: Substring at beginning
printf("Test %d: Substring at beginning\n", test_num++);
result = ft_strnstr("Hello World", "Hello", 11);
printf("ft_strnstr(\"Hello World\", \"Hello\", 11) = %s\n",
	result ? result : "NULL");
printf("Expected: Hello World\n\n");

// Test 3: Empty needle
printf("Test %d: Empty needle\n", test_num++);
result = ft_strnstr("Hello World", "", 11);
printf("ft_strnstr(\"Hello World\", \"\", 11) = %s\n",
	result ? result : "NULL");
printf("Expected: Hello World\n\n");

// Test 4: Needle not found
printf("Test %d: Needle not found\n", test_num++);
result = ft_strnstr("Hello World", "xyz", 11);
printf("ft_strnstr(\"Hello World\", \"xyz\", 11) = %s\n",
	result ? result : "NULL");
printf("Expected: NULL\n\n");

// Test 5: Length too short
printf("Test %d: Length too short\n", test_num++);
result = ft_strnstr("Hello World", "World", 5);
printf("ft_strnstr(\"Hello World\", \"World\", 5) = %s\n",
	result ? result : "NULL");
printf("Expected: NULL\n\n");

// Test 6: Exact length match
printf("Test %d: Exact length match\n", test_num++);
result = ft_strnstr("Hello World", "World", 10);
printf("ft_strnstr(\"Hello World\", \"World\", 10) = %s\n",
	result ? result : "NULL");
printf("Expected: NULL (not enough space for full match)\n\n");

// Test 7: Length exactly fits
printf("Test %d: Length exactly fits\n", test_num++);
result = ft_strnstr("Hello World", "World", 11);
printf("ft_strnstr(\"Hello World\", \"World\", 11) = %s\n",
	result ? result : "NULL");
printf("Expected: World\n\n");

// Test 8: Single character search
printf("Test %d: Single character search\n", test_num++);
result = ft_strnstr("Hello World", "o", 11);
printf("ft_strnstr(\"Hello World\", \"o\", 11) = %s\n",
	result ? result : "NULL");
printf("Expected: o World\n\n");

// Test 9: Needle longer than haystack
printf("Test %d: Needle longer than haystack\n", test_num++);
result = ft_strnstr("Hi", "Hello", 2);
printf("ft_strnstr(\"Hi\", \"Hello\", 2) = %s\n", result ? result : "NULL");
printf("Expected: NULL\n\n");

// Test 10: Zero length
printf("Test %d: Zero length\n", test_num++);
result = ft_strnstr("Hello World", "Hello", 0);
printf("ft_strnstr(\"Hello World\", \"Hello\", 0) = %s\n",
	result ? result : "NULL");
printf("Expected: NULL\n\n");

// Test 11: Partial match at boundary
printf("Test %d: Partial match at boundary\n", test_num++);
result = ft_strnstr("Hello World", "Wor", 8);
printf("ft_strnstr(\"Hello World\", \"Wor\", 8) = %s\n",
	result ? result : "NULL");
printf("Expected: NULL (not enough space)\n\n");

// Test 12: Multiple occurrences
printf("Test %d: Multiple occurrences (first one)\n", test_num++);
result = ft_strnstr("abcabcabc", "abc", 9);
printf("ft_strnstr(\"abcabcabc\", \"abc\", 9) = %s\n",
	result ? result : "NULL");
printf("Expected: abcabcabc (first occurrence)\n\n");

printf("=== All tests completed ===\n");
return (0);
}*/
