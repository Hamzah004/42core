/* ************************************************************************** */
/*                          ft_itoa.c - TEST ANALYSIS                        */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// // Your original implementation (with issues)
// char    *ft_itoa_original(int n)
// {
//     char    *str;
//     int        sign;
//     int        len;
//     sign = (n < 0) ? -1 : 1;
//     len = (sign == -1) ? 2 : 1;
//     while (n / 10 > 0)  // ❌ BUG: doesn't work for negative numbers
//     {
//         len++;
//     }
//     str = (char *)malloc(len + 1);
//     if (!str)
//         return (NULL);
//     str[len] = '\0';
//     n *= sign;  // ❌ BUG: INT_MIN overflow
//     while (len--)
//     {
//         str[len] = (n % 10) + '0';
//         n /= 10;
//     }
//     if (sign == -1)
//         str[0] = '-';
//     return (str);
// }

// Corrected implementation
char    *ft_itoa_fixed(int n)
{
    char    *str;
    int     sign;
    int     len;
    int     temp;
    
    // Handle special case of INT_MIN
    if (n == INT_MIN)
    {
        str = malloc(12);  // "-2147483648\0"
        if (!str) return (NULL);
        strcpy(str, "-2147483648");
        return (str);
    }
    
    sign = (n < 0) ? -1 : 1;
    len = (sign == -1) ? 2 : 1;  // Start with 1 digit + potential minus
    
    // Calculate length using absolute value
    temp = (n < 0) ? -n : n;
    while (temp >= 10)
    {
        len++;
        temp /= 10;
    }
    
    str = (char *)malloc(len + 1);
    if (!str)
        return (NULL);
    str[len] = '\0';
    
    // Convert to positive for digit extraction
    n = (n < 0) ? -n : n;
    
    // Fill digits from right to left
    while (len-- > (sign == -1 ? 1 : 0))
    {
        str[len] = (n % 10) + '0';
        n /= 10;
    }
    
    if (sign == -1)
        str[0] = '-';
    
    return (str);
}

// Test function
void test_itoa(const char *test_name, int input)
{
    printf("\n=== %s ===\n", test_name);
    printf("Input: %d\n", input);
    
    // char *result_original = ft_itoa_original(input);
    char *result_fixed = ft_itoa_fixed(input);
    
    // Create expected result using sprintf
    char expected[20];
    sprintf(expected, "%d", input);
    
    printf("Expected:        \"%s\"\n", expected);
    printf("Fixed version:   \"%s\"\n", result_fixed ? result_fixed : "NULL");
    
    
    // Check fixed
    if (result_fixed && strcmp(result_fixed, expected) == 0) {
        printf("Fixed: ✅ PASS\n");
    } else {
        printf("Fixed: ❌ FAIL\n");
    }
    
    free(result_fixed);
}

// Debug function to show length calculation issues
void debug_length_calculation()
{
    printf("\n=== DEBUG: LENGTH CALCULATION ISSUES ===\n");
    
    int test_nums[] = {-123, -1, 0};
    
    for (int i = 0; i < 3; i++) {
        int n = test_nums[i];
        printf("\nTesting n = %d:\n", n);
        printf("Your loop condition: n / 10 > 0\n");
        printf("When n = %d: %d / 10 = %d, is %d > 0? %s\n", 
               n, n, n/10, n/10, (n/10 > 0) ? "YES" : "NO");
        
        if (n < 0) {
            printf("❌ Problem: For negative numbers, n/10 is negative, never > 0!\n");
            printf("   Loop will never execute, len stays at initial value\n");
        }
        
        if (n == 0) {
            printf("❌ Problem: For zero, 0/10 = 0, not > 0!\n");
            printf("   Loop will never execute, but we need 1 digit for '0'\n");
        }
    }
}

int main(void)
{
    printf("TESTING ft_itoa IMPLEMENTATION\n");
    printf("==============================\n");
    
    // Show the main issues first
    debug_length_calculation();
    
    printf("\n\nRUNNING COMPREHENSIVE TESTS:\n");
    printf("============================\n");
    
    // Test cases
    test_itoa("Positive number", 12345);
    test_itoa("Negative number", -12345);
    test_itoa("Zero", 0);
    test_itoa("Single digit positive", 7);
    test_itoa("Single digit negative", -7);
    test_itoa("Large positive", 2147483647);  // INT_MAX
    test_itoa("Large negative", -2147483648); // INT_MIN
    test_itoa("Small numbers", -1);
    
    printf("\n=== SUMMARY OF ISSUES IN ORIGINAL CODE ===\n");
    printf("1. ❌ Length calculation: 'n / 10 > 0' fails for negative numbers\n");
    printf("2. ❌ Zero handling: Loop never runs for n=0, but len=1 is correct by luck\n");
    printf("3. ❌ INT_MIN overflow: n *= sign causes undefined behavior\n");
    printf("4. ❌ Logic flaw: negative numbers need abs(n) for length calculation\n");
    
    printf("\n=== RECOMMENDED FIXES ===\n");
    printf("1. ✅ Use absolute value for length calculation\n");
    printf("2. ✅ Handle INT_MIN as special case (or use long)\n");
    printf("3. ✅ Change loop condition to work with absolute values\n");
    printf("4. ✅ Convert to positive after length calculation\n");
    
    return 0;
}
