/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 13:41:57 by ksener            #+#    #+#             */
/*   Updated: 2026/02/10 14:05:54 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

/* --- STANDARD ANSI COLOR CODES --- */
#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW  "\033[0;33m"
#define BLUE    "\033[0;34m"
#define CYAN    "\033[0;36m"
#define ITALIC  "\033[3m"
#define RESET   "\033[0m"

/* --- HELPER FUNCTIONS --- */
int g_tests_passed = 0;
int g_tests_total = 0;

void print_header(char *name)
{
    printf("\n%s=== TESTING: %s ===%s\n", CYAN, name, RESET);
}

/* THE CHECK FUNCTION: Controls Green/Red Logic */
void check(int condition, char *msg)
{
    g_tests_total++;
    if (condition)
    {
        g_tests_passed++;
        printf("  %s[OK]%s   %s\n", GREEN, RESET, msg);
    }
    else
    {
        printf("  %s[FAIL]%s %s\n", RED, RESET, msg);
    }
}

/* --- MOCK FUNCTIONS FOR ITERATORS --- */
char    mock_strmapi(unsigned int i, char c)
{
    (void)i;
    return (c - 32); // To Upper
}

void    mock_striteri(unsigned int i, char *c)
{
    (void)i;
    *c = *c - 32; // To Upper
}

void    mock_del(void *content)
{
    (void)content; 
}

void    *mock_lstmap(void *content)
{
    char *c = (char *)content;
    return strdup(c); 
}

/* ========================================================================== */
/* MAIN FUNCTION                                */
/* ========================================================================== */
int main(void)
{
    printf("%s*****************************************************\n", YELLOW);
    printf("* ULTIMATE LIBFT TESTER v2.2              *\n");
    printf("* Target: kerem - sener                   *\n");
    printf("*****************************************************%s\n", RESET);
    
    printf("%s%sDISCLAIMER: This tester is a local development tool.\n", ITALIC, RED);
    printf("It mimics common edge cases but does not guarantee a 100%% score.\n");
    printf("Always trust your own logic and the official Moulinette.%s\n", RESET);

    /* ---------------------- PART 1: LIBC FUNCTIONS ---------------------- */

    // 1. ISALPHA
    print_header("ft_isalpha");
    check(ft_isalpha('A') && ft_isalpha('z'), "Checks alphabetic chars");
    check(!ft_isalpha('1') && !ft_isalpha('-'), "Checks non-alpha chars");

    // 2. ISDIGIT
    print_header("ft_isdigit");
    check(ft_isdigit('0') && ft_isdigit('9'), "Checks digits");
    check(!ft_isdigit('a') && !ft_isdigit(' '), "Checks non-digits");

    // 3. ISALNUM
    print_header("ft_isalnum");
    check(ft_isalnum('A') && ft_isalnum('9'), "Checks alphanumeric");
    check(!ft_isalnum('-') && !ft_isalnum(' '), "Checks symbols");

    // 4. ISASCII
    print_header("ft_isascii");
    check(ft_isascii(0) && ft_isascii(127), "Checks valid ASCII range");
    check(!ft_isascii(128), "Checks outside ASCII range");

    // 5. ISPRINT
    print_header("ft_isprint");
    check(ft_isprint(32) && ft_isprint(126), "Checks printable range");
    check(!ft_isprint(31) && !ft_isprint(127), "Checks non-printable");

    // 6. STRLEN
    print_header("ft_strlen");
    check(ft_strlen("kerem") == 5, "Length of 'kerem'");
    check(ft_strlen("") == 0, "Length of empty string");

    // 7. MEMSET
    print_header("ft_memset");
    char buff1[20] = "kerem - sener";
    char buff2[20] = "kerem - sener";
    ft_memset(buff1, 'x', 5);
    memset(buff2, 'x', 5);
    check(memcmp(buff1, buff2, 20) == 0, "Set 5 bytes to 'x'");

    // 8. BZERO
    print_header("ft_bzero");
    char bz1[10] = "keremsener";
    char bz2[10] = "keremsener";
    ft_bzero(bz1, 5);
    bzero(bz2, 5);
    check(memcmp(bz1, bz2, 10) == 0, "Zeroed first 5 bytes");

    // 9. MEMCPY
    print_header("ft_memcpy");
    char src_cp[] = "kerem";
    char dst_cp1[10] = {0};
    char dst_cp2[10] = {0};
    ft_memcpy(dst_cp1, src_cp, 5);
    memcpy(dst_cp2, src_cp, 5);
    check(memcmp(dst_cp1, dst_cp2, 10) == 0, "Copy 'kerem' to buffer");
    
    // 10. MEMMOVE
    print_header("ft_memmove");
    char mv1[] = "kerem - sener";
    char mv2[] = "kerem - sener";
    ft_memmove(mv1 + 2, mv1, 5); 
    memmove(mv2 + 2, mv2, 5);
    check(memcmp(mv1, mv2, 13) == 0, "Overlap check (src < dst)");

    // 11. STRDUP
    print_header("ft_strdup");
    char *dup_str = ft_strdup("kerem - sener");
    check(strcmp(dup_str, "kerem - sener") == 0, "String duplication correct");
    free(dup_str);

    // 12. STRLCPY
    print_header("ft_strlcpy");
    char lcpy_dst[10];
    size_t ret_lcpy = ft_strlcpy(lcpy_dst, "kerem", 10);
    check(strcmp(lcpy_dst, "kerem") == 0 && ret_lcpy == 5, "Copy with sufficient size");
    ret_lcpy = ft_strlcpy(lcpy_dst, "kerem - sener", 3);
    check(strlen(lcpy_dst) == 2 && ret_lcpy == 13, "Truncation check (size 3)");

    // 13. STRLCAT (MOULINETTE TRAP)
    print_header("ft_strlcat");
    char lcat_dst[20] = "kerem";
    char lcat_src[] = " - sener";
    
    // Test 1: Normal
    size_t ret_lcat = ft_strlcat(lcat_dst, lcat_src, 20);
    check(strcmp(lcat_dst, "kerem - sener") == 0 && ret_lcat == 13, "Normal concatenate");

    // Test 2: Edge Case (Size < Dst Length)
    char lcat_dst2[20] = "kerem";
    size_t ret_lcat2 = ft_strlcat(lcat_dst2, lcat_src, 3);
    // Expectation: Dst not changed, return = size + strlen(src)
    check(strcmp(lcat_dst2, "kerem") == 0, "Dst not changed when size < strlen(dst)");
    check(ret_lcat2 == (3 + strlen(lcat_src)), "Return val correct when size < strlen(dst)");

    // 14. STRCHR & STRRCHR
    print_header("ft_strchr / ft_strrchr");
    check(ft_strchr("kerem", 'r') != NULL, "strchr found 'r'");
    check(ft_strchr("kerem", 'z') == NULL, "strchr not found");
    check(ft_strrchr("kerem", 'e') == (ft_strchr("kerem", '\0') - 2), "strrchr found last 'e'");

    // 15. STRNCMP
    print_header("ft_strncmp");
    check(ft_strncmp("kerem", "keraz", 3) == 0, "Match first 3 chars");
    check(ft_strncmp("kerem", "keraz", 4) != 0, "Mismatch at 4th char");

    // 16. MEMCHR & MEMCMP
    print_header("ft_memchr / ft_memcmp");
    check(ft_memchr("kerem", 'r', 5) != NULL, "memchr found 'r'");
    // Corrected to size 5 to check the difference between 'm' and 'z'
    check(ft_memcmp("kerem", "kerez", 5) != 0, "memcmp diff found");

    // 17. STRNSTR
    print_header("ft_strnstr");
    char *big = "kerem - sener 42 kocaeli";
    check(ft_strnstr(big, "sener", 20) != NULL, "Found needle in haystack");
    check(ft_strnstr(big, "kocaeli", 10) == NULL, "Needle out of scope");
    check(ft_strnstr(big, "", 20) == big, "Empty needle returns haystack");

    // 18. ATOI (MOULINETTE TRAP)
    print_header("ft_atoi");
    check(ft_atoi("  -42") == -42, "Negative with spaces");
    check(ft_atoi("  +123") == 123, "Positive with plus sign");
    check(ft_atoi("2147483647") == INT_MAX, "INT_MAX");
    check(ft_atoi("-2147483648") == INT_MIN, "INT_MIN");
    check(ft_atoi(" --42") == 0, "Double signs should fail/stop");
    check(ft_atoi(" +-42") == 0, "Mixed signs should fail/stop");

    // 19. CALLOC
    print_header("ft_calloc");
    int *ptr_calloc = (int *)ft_calloc(5, sizeof(int));
    int is_zero = 1;
    for(int i=0; i<5; i++) if(ptr_calloc[i] != 0) is_zero = 0;
    check(is_zero, "Memory allocated and zeroed");
    free(ptr_calloc);

    // 20. TOUPPER / TOLOWER
    print_header("ft_toupper / ft_tolower");
    check(ft_toupper('a') == 'A', "toupper 'a' -> 'A'");
    check(ft_tolower('Z') == 'z', "tolower 'Z' -> 'z'");

    /* ---------------------- PART 2: ADDITIONAL FUNCTIONS ---------------------- */

    // 21. SUBSTR (MOULINETTE TRAP)
    print_header("ft_substr");
    char *sub = ft_substr("kerem - sener", 8, 5);
    check(strcmp(sub, "sener") == 0, "Extract 'sener'");
    free(sub);
    
    // Critical: Start index > string length
    sub = ft_substr("kerem", 50, 5);
    check(sub != NULL, "Should return allocated memory, not NULL");
    check(strcmp(sub, "") == 0, "Should be empty string");
    free(sub);

    // 22. STRJOIN
    print_header("ft_strjoin");
    char *joined = ft_strjoin("kerem", " sener");
    check(strcmp(joined, "kerem sener") == 0, "Joined successfully");
    free(joined);

    // 23. STRTRIM
    print_header("ft_strtrim");
    char *trimmed = ft_strtrim("xxkerem - senerxx", "x");
    check(strcmp(trimmed, "kerem - sener") == 0, "Trimmed 'x' from both ends");
    free(trimmed);

    // 24. SPLIT (MOULINETTE TRAP)
    print_header("ft_split");
    // Hardcore: Consecutive delimiters and delimiters at ends
    char **split = ft_split("zzkeremzzz-zsenerzz", 'z');
    if (split) {
        check(strcmp(split[0], "kerem") == 0, "Hardcore Split[0] ok");
        check(strcmp(split[1], "-") == 0,     "Hardcore Split[1] ok");
        check(strcmp(split[2], "sener") == 0, "Hardcore Split[2] ok");
        check(split[3] == NULL, "Null terminator ok");
        // Free split
        int i = 0;
        while(split[i]) free(split[i++]);
        free(split);
    } else {
        check(0, "Split failed to allocate");
    }

    // 25. ITOA
    print_header("ft_itoa");
    char *num_str = ft_itoa(-1234);
    check(strcmp(num_str, "-1234") == 0, "itoa handled negative");
    free(num_str);
    num_str = ft_itoa(0);
    check(strcmp(num_str, "0") == 0, "itoa handled zero");
    free(num_str);

    // 26. STRMAPI
    print_header("ft_strmapi");
    char *mapi = ft_strmapi("abcd", mock_strmapi);
    check(strcmp(mapi, "ABCD") == 0, "Applies function to new string");
    free(mapi);

    // 27. STRITERI
    print_header("ft_striteri");
    char iteri_str[] = "abcd";
    ft_striteri(iteri_str, mock_striteri);
    check(strcmp(iteri_str, "ABCD") == 0, "Modified string in place");

    // 28. FILE DESCRIPTOR FUNCTIONS
    print_header("ft_put*_fd");
    printf("%s[INFO] Check terminal output manually below:%s\n", YELLOW, RESET);
    ft_putstr_fd("-> ft_putstr_fd: kerem - sener\n", 1);
    ft_putendl_fd("-> ft_putendl_fd: 42 kocaeli", 1);
    ft_putnbr_fd(42, 1); printf("\n");

    /* ----------------------LINKED LISTS ---------------------- */

    print_header("LINKED LISTS");
    
    // LSTNEW
    char *content1 = strdup("kerem");
    t_list *node1 = ft_lstnew(content1);
    check(node1 != NULL && strcmp((char *)node1->content, "kerem") == 0, "lstnew created node");

    // LSTADD_FRONT
    char *content2 = strdup("sener");
    t_list *node2 = ft_lstnew(content2);
    ft_lstadd_front(&node1, node2); 
    check(strcmp((char *)node1->content, "sener") == 0, "lstadd_front updated head");

    // LSTSIZE
    check(ft_lstsize(node1) == 2, "lstsize counts 2 nodes");

    // LSTLAST
    t_list *last = ft_lstlast(node1);
    check(strcmp((char *)last->content, "kerem") == 0, "lstlast found tail");

    // LSTADD_BACK
    char *content3 = strdup("42");
    t_list *node3 = ft_lstnew(content3);
    ft_lstadd_back(&node1, node3); 
    check(ft_lstsize(node1) == 3, "lstadd_back added to end");

    // LSTMAP
    t_list *new_list = ft_lstmap(node1, mock_lstmap, mock_del);
    if (new_list) {
        check(ft_lstsize(new_list) == 3, "lstmap created new list of size 3");
        ft_lstclear(&new_list, free);
    } else {
        check(0, "lstmap failed");
    }

    // LSTCLEAR
    ft_lstclear(&node1, free); 
    check(node1 == NULL, "lstclear set head to NULL");

    /* ---------------------- SUMMARY ---------------------- */
    printf("\n%s=====================================================\n", BLUE);
    if (g_tests_passed == g_tests_total)
        printf("%s  ALL TESTS PASSED! PERFECT SCORE ( %d / %d )%s\n", GREEN, g_tests_passed, g_tests_total, RESET);
    else
        printf("%s  SOME TESTS FAILED. SCORE: ( %d / %d )%s\n", RED, g_tests_passed, g_tests_total, RESET);
    printf("%s=====================================================%s\n", BLUE, RESET);

    return (0);
}