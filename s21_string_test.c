#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

void s21_strlen_test(const char *s, size_t expected);
void s21_strcmp_test(const char *s1, const char *s2, int expected);
void s21_strcpy_test(char *dest, const char *src, const char *expected);
void s21_strcat_test(char *dest, const char *src, const char *expected);
void s21_strchr_test(const char *s, int c, const char *expected);


int main() {
    printf("=== STRLEN TESTS ===\n");
    s21_strlen_test("", 0);
    s21_strlen_test(" ", 1);
    s21_strlen_test("123456789", 9);
    s21_strlen_test("A b C d?", 8);
    s21_strlen_test(NULL, 0);  
    
    printf("\n=== STRCMP TESTS ===\n");
    s21_strcmp_test("", "", 0);
    s21_strcmp_test("abc", "acb", -1);
    s21_strcmp_test("a", " ", 1);
    s21_strcmp_test(NULL, " ", -1);
    s21_strcmp_test("", NULL, 1);
    s21_strcmp_test(NULL, NULL, 0);
    
    printf("\n=== STRCPY TESTS ===\n");
    char buf[22] = {0};
    s21_strcpy_test(buf, "I love Wombats!", "I love Wombats!");
    s21_strcpy_test(buf, "I", "I");
    s21_strcpy_test(buf, "", "");
    s21_strcpy_test(buf, NULL, NULL); 
    s21_strcpy_test(NULL, "test", NULL); 
    
    printf("\n=== STRCAT TESTS ===\n");
    char s1[22] = "I hate ";
    s21_strcat_test(s1, "Verter!", "I hate Verter!");
    char s2[22] = "I";
    s21_strcat_test(s2, "", "I");
    char s3[22] = "";
    s21_strcat_test(s3, "", "");
    s21_strcat_test(NULL, "test", NULL);  
    s21_strcat_test(s3, NULL, NULL);    
    
    printf("\n=== STRCHR TESTS ===\n");
    const char *s = "VEROCHKA";
    s21_strchr_test(s, 'R', s + 2);
    s21_strchr_test("", '\0', "");
    s21_strchr_test("", 'a', NULL);
    s21_strchr_test("abc", '\0', "abc" + 3);
    s21_strchr_test("abc", 'd', NULL);
    s21_strchr_test(NULL, 'd', NULL);

    printf("\n=== MEMCPY TESTS ===\n");
    char buf1[20] = {0};
    s21_memcpy_test(buf1, "Hello, VERTER", 14, "Hello, VERTER");
    
    char buf2[] = "abcdefghij";
    s21_memcpy_test(buf2 + 3, buf2, 4, "abcabcdhij");
    
    s21_memcpy_test(NULL, "test", 5, NULL);
    s21_memcpy_test(buf1, NULL, 5, NULL);
    
    printf("\n=== MEMSET TESTS ===\n");
    char buf3[10] = {0};
    s21_memset_test(buf3, 'A', 10, "AAAAAAAAAA");
    
    char buf4[5] = "test";
    s21_memset_test(buf4, 'X', 2, "XXst");
    
    s21_memset_test(NULL, 'A', 10, NULL);
    
    printf("\n=== STRSTR TESTS ===\n");
    const char *str = "The quick brown fox jumps over the lazy dog";
    s21_strstr_test(str, "fox", "fox jumps over the lazy dog");
    s21_strstr_test(str, "cat", NULL);
    s21_strstr_test(str, "", str);
    s21_strstr_test("", "test", NULL);
    s21_strstr_test(NULL, "test", NULL);
    
    return 0;
}

void s21_strlen_test(const char *s, size_t expected) {
    size_t res = s21_strlen(s);
    printf("Input: %s\n", s ? s : "NULL");
    printf("Result: %zu\n", res);
    printf("Test: %s\n\n", res == expected ? "SUCCESS" : "FAIL");
}

void s21_strcmp_test(const char *s1, const char *s2, int expected) {
    int res = s21_strcmp(s1, s2);
    printf("Input1: %s\n", s1 ? s1 : "NULL");
    printf("Input2: %s\n", s2 ? s2 : "NULL");
    printf("Result: %d\n", res);
    printf("Test: %s\n\n", res == expected ? "SUCCESS" : "FAIL");
}

void s21_strcpy_test(char *dest, const char *src, const char *expected) {
    char *res = s21_strcpy(dest, src);
    printf("Dest: %s\n", dest ? dest : "NULL");
    printf("Src: %s\n", src ? src : "NULL");
    printf("Result: %s\n", res ? res : "NULL");
    
    int test_result;
    if (expected == NULL) {
        test_result = (res == NULL);
    } else {
        test_result = (res != NULL) && (s21_strcmp(res, expected) == 0);
    }
    
    printf("Test: %s\n\n", test_result ? "SUCCESS" : "FAIL");
}

void s21_strcat_test(char *dest, const char *src, const char *expected) {
    char *res = s21_strcat(dest, src);
    printf("Dest: %s\n", dest ? dest : "NULL");
    printf("Src: %s\n", src ? src : "NULL");
    printf("Result: %s\n", res ? res : "NULL");
    
    int test_result;
    if (expected == NULL) {
        test_result = (res == NULL);
    } else {
        test_result = (res != NULL) && (s21_strcmp(res, expected) == 0);
    }
    
    printf("Test: %s\n\n", test_result ? "SUCCESS" : "FAIL");
}

void s21_strchr_test(const char *s, int c, const char *expected) {
    const char *res = s21_strchr(s, c);
    printf("String: %s\n", s ? s : "NULL");
    printf("Char: %c\n", c);
    printf("Result: %s\n", res ? res : "NULL");
    printf("Test: %s\n\n", res == expected ? "SUCCESS" : "FAIL");
}

void s21_memcpy_test(void *dest, const void *src, size_t n, const char *expected) {
    char *res = s21_memcpy(dest, src, n);
    
    printf("Dest: %s\n", dest ? (char*)dest : "NULL");
    printf("Src: %s\n", src ? (char*)src : "NULL");
    printf("Size: %zu\n", n);
    
    int test_result;
    if (expected == NULL) {
        test_result = (res == NULL);
    } else {
        char buf[256] = {0};
        s21_memcpy(buf, dest, n < sizeof(buf) ? n : sizeof(buf));
        test_result = (res != NULL) && (s21_strcmp(buf, expected) == 0);
    }
    
    printf("Result: %s\n", res ? "SUCCESS" : "FAIL");
    printf("Test: %s\n\n", test_result ? "SUCCESS" : "FAIL");
}

void s21_memset_test(void *s, int c, size_t n, const char *expected) {
    void *res = s21_memset(s, c, n);
    
    printf("Buffer: %s\n", s ? "VALID" : "NULL");
    printf("Char: %c\n", c);
    printf("Size: %zu\n", n);
    
    int test_result;
    if (expected == NULL) {
        test_result = (res == NULL);
    } else {
        char buf[256] = {0};
        s21_memcpy(buf, s, n < sizeof(buf) ? n : sizeof(buf));
        test_result = (res != NULL) && (s21_strcmp(buf, expected) == 0);
    }
    
    printf("Result: %s\n", res ? "SUCCESS" : "FAIL");
    printf("Test: %s\n\n", test_result ? "SUCCESS" : "FAIL");
}

void s21_strstr_test(const char *haystack, const char *needle, const char *expected) {
    const char *res = s21_strstr(haystack, needle);
    
    printf("Haystack: %s\n", haystack ? haystack : "NULL");
    printf("Needle: %s\n", needle ? needle : "NULL");
    
    int test_result;
    if (expected == NULL) {
        test_result = (res == NULL);
    } else {
        test_result = (res != NULL) && (s21_strcmp(res, expected) == 0);
    }
    
    printf("Result: %s\n", res ? res : "NULL");
    printf("Test: %s\n\n", test_result ? "SUCCESS" : "FAIL");
}

