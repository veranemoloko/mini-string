#ifndef S21_STRING_H
#define S21_STRING_H

#include <stddef.h>

size_t s21_strlen(const char *str);
int s21_strcmp(const char *s1, const char *s2);
char *s21_strcpy(char *restrict dest, const char *restrict src);
char *s21_strcat(char *restrict dest, const char *restrict src);
const char *s21_strchr(const char *s, int c);
void *s21_memcpy(void *restrict dest, const void *restrict src, size_t n);
void *s21_memset(void *s, int c, size_t n);
char *s21_strstr(const char *haystack, const char *needle);

#endif 
