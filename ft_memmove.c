/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbani-at <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 02:15:48 by hbani-at          #+#    #+#             */
/*   Updated: 2025/08/10 02:21:42 by hbani-at         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, void const *src, size_t n)
{
	unsigned char		*dest_char;
	const unsigned char	*src_char;

	if (!dest || !src)
		return (NULL);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	src_char = (unsigned char *)src;
	dest_char = (unsigned char *)dest;
	while (n > 0)
	{
		dest_char[n - 1] = src_char[n - 1];
		n--;
	}
	return (dest);
}
/*
// Test result comparison
int	test_compare(const char *test_name, void *result, void *expected,
		size_t size, int should_pass) {
	printf("%-40s: ", test_name);

	if (!should_pass) {
		printf("EXPECTED FAILURE - ");
		if (result == NULL) {
			printf("✅ PASS (correctly returned NULL)\n");
			return (1);
		} else {
			printf("❌ FAIL (should have returned NULL)\n");
			return (0);
		}
	}

	if (result == NULL && expected != NULL) {
		printf("❌ FAIL (returned NULL unexpectedly)\n");
		return (0);
	}

	if (memcmp(result, expected, size) == 0) {
		printf("✅ PASS\n");
		return (1);
	} else {
		printf("❌ FAIL\n");
		printf("Expected: ");
		for (size_t i = 0; i < size; i++) {
			printf("%02X ", ((unsigned char*)expected)[i]);
		}
		printf("\nGot:      ");
		for (size_t i = 0; i < size; i++) {
			printf("%02X ", ((unsigned char*)result)[i]);
		}
		printf("\n");
		return (0);
	}
}

// Test 1: Basic non-overlapping copy
void	test_basic_copy(void) {
	printf("\n=== TEST 1: Basic Non-overlapping Copy ===\n");

	char src[] = "Hello, World!";
	char dest[20] = {0};
	char expected[20] = {0};

	ft_memmove(dest, src, 13);
	memmove(expected, src, 13);

	test_compare("Basic string copy", dest, expected, 20, 1);
}

// Test 2: NULL pointer handling
void	test_null_pointers(void) {
	printf("\n=== TEST 2: NULL Pointer Handling ===\n");

	char buffer[10] = "test";

	// Test NULL dest
	void *result1 = ft_memmove(NULL, buffer, 4);
	test_compare("NULL destination", &result1, &(void*){NULL}, sizeof(void*),
		0);

	// Test NULL src
	void *result2 = ft_memmove(buffer, NULL, 4);
	test_compare("NULL source", &result2, &(void*){NULL}, sizeof(void*), 0);

	// Test both NULL
	void *result3 = ft_memmove(NULL, NULL, 4);
	test_compare("Both NULL", &result3, &(void*){NULL}, sizeof(void*), 0);
}

// Test 3: Zero size copy
void	test_zero_size(void) {
	printf("\n=== TEST 3: Zero Size Copy ===\n");

	char src[] = "source";
	char dest[] = "destination";
	char expected[] = "destination";

	ft_memmove(dest, src, 0);

	test_compare("Zero size copy", dest, expected, strlen(expected), 1);
}

// Test 4: Overlapping memory - right shift (dest > src)
void	test_overlap_right_shift(void) {
	printf("\n=== TEST 4: Overlapping Memory - Right Shift ===\n");

	// Test case 1: Simple right shift
	char buffer1[20] = "0123456789";
	char expected1[20] = "0123456789";

	ft_memmove(buffer1 + 3, buffer1, 7);     // Your function
	memmove(expected1 + 3, expected1, 7);    // Standard function

	test_compare("Right shift overlap", buffer1, expected1, 20, 1);

	// Test case 2: Large overlap
	char buffer2[20] = "ABCDEFGHIJKLMNOP";
	char expected2[20] = "ABCDEFGHIJKLMNOP";

	ft_memmove(buffer2 + 5, buffer2, 10);
	memmove(expected2 + 5, expected2, 10);

	test_compare("Large right shift", buffer2, expected2, 20, 1);

	// Test case 3: Single byte shift
	char buffer3[10] = "123456789";
	char expected3[10] = "123456789";

	ft_memmove(buffer3 + 1, buffer3, 8);
	memmove(expected3 + 1, expected3, 8);

	test_compare("Single byte right shift", buffer3, expected3, 10, 1);
}

// Test 5: Overlapping memory - left shift (dest < src)
void	test_overlap_left_shift(void) {
	printf("\n=== TEST 5: Overlapping Memory - Left Shift ===\n");

	// Test case 1: Simple left shift
	char buffer1[20] = "0123456789ABCDEF";
	char expected1[20] = "0123456789ABCDEF";

	ft_memmove(buffer1, buffer1 + 3, 10);
	memmove(expected1, expected1 + 3, 10);

	test_compare("Left shift overlap", buffer1, expected1, 20, 1);

	// Test case 2: Remove from middle
	char buffer2[] = "Hello, World!";
	char expected2[] = "Hello, World!";

	ft_memmove(buffer2 + 5, buffer2 + 7, 7);  // Remove ", "
	memmove(expected2 + 5, expected2 + 7, 7);

	test_compare("Remove from middle", buffer2, expected2, 13, 1);
}

// Test 6: Edge case - same source and destination
void	test_same_pointer(void) {
	printf("\n=== TEST 6: Same Source and Destination ===\n");

	char buffer[] = "unchanged";
	char expected[] = "unchanged";

	ft_memmove(buffer, buffer, 9);

	test_compare("Same src and dest", buffer, expected, 9, 1);
}

// Test 7: Different data types
void	test_different_types(void) {
	printf("\n=== TEST 7: Different Data Types ===\n");

	// Test with integers
	int src_int[] = {1, 2, 3, 4, 5};
	int dest_int[5] = {0};
	int expected_int[5] = {0};

	ft_memmove(dest_int, src_int, 5 * sizeof(int));
	memmove(expected_int, src_int, 5 * sizeof(int));

	test_compare("Integer array copy", dest_int, expected_int, 5 * sizeof(int),
		1);

	// Test with structures
	struct Point {
		int x, y;
		char name[10];
	};

	struct Point src_struct = {10, 20, "Point1"};
	struct Point dest_struct = {0};
	struct Point expected_struct = {0};

	ft_memmove(&dest_struct, &src_struct, sizeof(struct Point));
	memmove(&expected_struct, &src_struct, sizeof(struct Point));

	test_compare("Struct copy", &dest_struct, &expected_struct,
		sizeof(struct Point), 1);
}

// Test 8: Binary data with null bytes
void	test_binary_data(void) {
	printf("\n=== TEST 8: Binary Data with Null Bytes ===\n");

	unsigned char src[] = {0x00, 0xFF, 0x00, 0xAB, 0x00, 0xCD, 0xEF};
	unsigned char dest[7] = {0};
	unsigned char expected[7] = {0};

	ft_memmove(dest, src, 7);
	memmove(expected, src, 7);

	test_compare("Binary data with nulls", dest, expected, 7, 1);
}

// Test 9: Large buffer copy
void	test_large_buffer(void) {
	printf("\n=== TEST 9: Large Buffer Copy ===\n");

	const size_t size = 10000;
	unsigned char *src = malloc(size);
	unsigned char *dest = malloc(size);
	unsigned char *expected = malloc(size);

	if (!src || !dest || !expected) {
		printf("Memory allocation failed\n");
		return ;
	}

	// Fill with pattern
	for (size_t i = 0; i < size; i++) {
		src[i] = i % 256;
	}

	ft_memmove(dest, src, size);
	memmove(expected, src, size);

	test_compare("Large buffer copy", dest, expected, size, 1);

	free(src);
	free(dest);
	free(expected);
}

// Test 10: Overlapping with exact boundary conditions
void	test_boundary_overlap(void) {
	printf("\n=== TEST 10: Boundary Overlap Conditions ===\n");

	// Test case: dest is exactly at the end of src
	char buffer1[20] = "0123456789ABCDEF";
	char expected1[20] = "0123456789ABCDEF";

	ft_memmove(buffer1 + 5, buffer1, 5);  // Copy first 5 chars to position 5
	memmove(expected1 + 5, expected1, 5);

	test_compare("Boundary overlap case 1", buffer1, expected1, 20, 1);

	// Test case: src is exactly at the end of dest region
	char buffer2[20] = "ABCDEFGHIJKLMNOP";
	char expected2[20] = "ABCDEFGHIJKLMNOP";

	ft_memmove(buffer2, buffer2 + 5, 5);
	memmove(expected2, expected2 + 5, 5);

	test_compare("Boundary overlap case 2", buffer2, expected2, 20, 1);
}

// Test 11: Performance comparison (just for info)
void	test_performance_info(void) {
	printf("\n=== TEST 11: Performance Info ===\n");

	const size_t size = 1000000;
	char *buffer = malloc(size);

	if (!buffer) {
		printf("Could not allocate memory for performance test\n");
		return ;
	}

	// Fill buffer
	for (size_t i = 0; i < size; i++) {
		buffer[i] = i % 256;
	}

	printf("Performance test with %zu bytes:\n", size);
	printf("- Non-overlapping: Uses ft_memcpy (faster path)\n");
	printf("- Overlapping: Uses backward copy (your implementation)\n");
	printf("- Standard memmove handles both cases optimally\n");

	free(buffer);
}

// Test 12: String manipulation scenarios
void	test_string_manipulation(void) {
	printf("\n=== TEST 12: String Manipulation Scenarios ===\n");

	// Remove substring
	char str1[] = "Hello, World!";
	char exp1[] = "Hello, World!";

	ft_memmove(str1 + 5, str1 + 7, 7);    // Remove ", "
	memmove(exp1 + 5, exp1 + 7, 7);

	test_compare("Remove substring", str1, exp1, 13, 1);

	// Insert space (shift right)
	char str2[20] = "HelloWorld";
	char exp2[20] = "HelloWorld";

	ft_memmove(str2 + 6, str2 + 5, 6);    // Make space for character
	memmove(exp2 + 6, exp2 + 5, 6);
	str2[5] = exp2[5] = ' ';               // Insert space

	test_compare("Insert character", str2, exp2, 20, 1);
}

int	main(void) {

	printf("COMPREHENSIVE TEST SUITE for ft_memmove\n");
	printf("======================================\n");

	// Run all tests
	test_basic_copy();
	test_null_pointers();
	test_zero_size();
	test_overlap_right_shift();
	test_overlap_left_shift();
	test_same_pointer();
	test_different_types();
	test_binary_data();
	test_large_buffer();
	test_boundary_overlap();
	test_performance_info();
	test_string_manipulation();

	// Note: This is a simplified test framework
	// In a real scenario, you'd track passed/total tests properly

	printf("\n=== CRITICAL EDGE CASES TO VERIFY ===\n");
	printf("1. ✅ NULL pointer handling\n");
	printf("2. ✅ Zero-size copy\n");
	printf("3. ✅ Same source and destination\n");
	printf("4. ✅ Right overlap (dest > src) - uses backward copy\n");
	printf("5. ✅ Left overlap (dest < src) - uses ft_memcpy\n");
	printf("6. ✅ Non-overlapping - uses ft_memcpy\n");
	printf("7. ✅ Binary data with null bytes\n");
	printf("8. ✅ Large buffer handling\n");
	printf("9. ✅ Different data types\n");
	printf("10. ✅ Boundary conditions\n");

	printf("\n=== POTENTIAL ISSUES TO CHECK ===\n");
	printf("⚠️  Make sure ft_memcpy is correctly implemented\n");
	printf("⚠️  Verify cast to unsigned char is correct\n");
	printf("⚠️  Check that n > 0 loop condition works for size_t\n");
	printf("⚠️  Ensure backward copy doesn't go out of bounds\n");

	printf("\nRun these tests and compare output with standard memmove!\n");

	return (0);
}*/
