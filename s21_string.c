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

void *s21_memcpy(void *restrict dest, const void *restrict src, size_t n) {
    if (dest == NULL || src == NULL) return NULL;
    
    char *d = dest;
    const char *s = src;
    
    if (d > s && d < s + n) {
        d += n;
        s += n;
        while (n--) {
            *--d = *--s;
        }
    } else {
        while (n--) {
            *d++ = *s++;
        }
    }
    
    return dest;
}

void *s21_memset(void *s, int c, size_t n) {
    if (s == NULL) return NULL;
    
    unsigned char *p = s;
    while (n--) {
        *p++ = (unsigned char)c;
    }
    
    return s;
}

char *s21_strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) return NULL;
    if (*needle == '\0') return (char *)haystack;
    
    for (; *haystack; haystack++) {
        const char *h = haystack;
        const char *n = needle;
        
        while (*h && *n && (*h == *n)) {
            h++;
            n++;
        }
        
        if (*n == '\0') return (char *)haystack;
    }
    
    return NULL;
}
