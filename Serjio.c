#include "stdio.h"
#include "string.h"

size_t s21_strlen(const char *str);    //Вычисляет длину строки str, не включая завершающий нулевой символ.
char *s21_strpbrk(const char *str1,
                  const char *str2); //Находит первый символ в строке str1, который соответствует любому символу, указанному в str2.
char *s21_strrchr(const char *str,
                  int c);    //Выполняет поиск последнего вхождения символа c (беззнаковый тип) в строке, на которую указывает аргумент str.
char *s21_strstr(const char *haystack,
                 const char *needle);    //Находит первое вхождение всей строки //needle (не включая завершающий нулевой символ), которая появляется в строке haystack.
char *s21_strtok(char *str, const char *delim); //	Разбивает строку str на ряд токенов, разделенных delim.


int main() {
    char s[20] = {0};
    scanf("%s", &s);

    char *token = s21_strtok(s, ", .");

    // Пока есть токены...
    while (token != NULL) {
        printf("%s\n", token);
        token = s21_strtok(NULL, ", ."); // Для следующего токена передаем NULL
    }
    return 0;
}

size_t s21_strlen(const char *str) {
    size_t result = 0;
    if (str != NULL) {
        for (size_t i = 0; str[i] != 0; i++) {
            result = i + 1;
        }
    }
    return result;
}

char *s21_strpbrk(const char *str1, const char *str2) {
    char *result = NULL;
    for (char *ptr = (char *) str1; *ptr != '\0' && result == NULL; ptr++) {
        for (char *ptr2 = (char *) str2; *ptr2 != '\0'; ptr2++) {
            if (*ptr == *ptr2) {
                result = ptr;
                break;
            }
        }
    }
    return result;
}

char *s21_strrchr(const char *str, int c) {
    char *result = NULL;
    for (size_t i = s21_strlen(str); i > 0; i--) {
        if (str[i] == c) {
            result = (char *) (str + i);
            break;
        }
    }
    return result;
}

char *s21_strstr(const char *haystack, const char *needle) {
    char *result = NULL;
    char *temp = s21_strpbrk(haystack, needle);
    if (s21_strlen(temp) >= s21_strlen(needle)) {
        for (size_t i = 0; i < s21_strlen(needle); i++) {
            if (*(temp + i) != *(needle + i)) {
                break;
            }
            if (i == strlen(needle) - 1) {
                result = temp;
            }
        }
    }
    return result;
}

char *s21_strtok(char *str, const char *delim) {
    static char *tmp = NULL;
    if (str) {
        tmp = str;
        while (*tmp && strchr(delim, *tmp)) {
            tmp++;
        }
    }
    if (tmp) {
        if (*tmp) {
            str = tmp;
            while (strchr(delim, *str)) {
                str++;
                tmp++;
            }
            while (*tmp && !strchr(delim, *tmp)) {
                tmp++;
            }
            if (*tmp && strchr(delim, *tmp)) {
                *tmp++ = 0;
            }
        } else {
            str = NULL;
        }
    } else {
        str = NULL;
    }
    return str;
}