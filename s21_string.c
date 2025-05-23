#include <stddef.h> 

size_t s21_strlen(const char *s) {
    if (s == NULL) return 0;
    
    const char *p = s;
    while (*p) p++;
    return p - s;
}

int s21_strcmp(const char *s1, const char *s2) {
    if (s1 == s2) return 0;
    if (s1 == NULL) return -1;
    if (s2 == NULL) return 1;
    
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

char *s21_strcpy(char *restrict dest, const char *restrict src) {
    if (dest == NULL || src == NULL) return dest;
    
    char *start = dest;
    while ((*dest++ = *src++));
    return start;
}

char *s21_strcat(char *restrict dest, const char *restrict src) {
    if (dest == NULL || src == NULL) return dest;
    
    char *end = dest;
    while (*end) end++;
    
    while ((*end++ = *src++));
    return dest;
}

const char *s21_strchr(const char *s, int c) {
    if (s == NULL) return NULL;
    
    while (*s && *s != (char)c) s++;
    return (*s == (char)c) ? s : NULL;
}
