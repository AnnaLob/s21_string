#include <stdio.h>
#include <stdlib.h>
#include <string.h> // убрать по окончанию !!!!

#define s21_size_t unsigned long long
#define s21_NULL (void*)0

char * s21_to_upper(const char * str);
char * s21_to_lower(const char *str);
char * s21_insert(const char *src, const char *str, s21_size_t start_index);
char * s21_trim(const char *src, const char *trim_chars);

int main() {

    char gift[100] = "Put string ->  <- close";
    char gift2[100] = "*Inside*"; // строка для вставки в первую стр
    char gift3[] = "Putose "; // строка с символами которые удаляем
    char * str = malloc(sizeof(char) * 100);
    strcpy(str, gift);
    char * Upstr = s21_to_upper(str);
    char * lowstr = s21_to_lower(Upstr);
    char * newstr = s21_insert(gift, gift2, 13);
    char * strtrim = s21_trim(gift, gift3);

    printf("Old ---- %s\nNewUp -- %s\nNewlow - %s\n", str, Upstr, lowstr);
    printf("insert - %s\n", newstr);
    printf("trim --- %s", strtrim);

    free(strtrim);
    free(newstr);
    free(lowstr);
    free(str);
    free(Upstr);

    return 0;
}

char * s21_to_upper(const char * str) {

    s21_size_t lenght = strlen(str); // по окончанию переключить strlen на s21_strlen  !!!!
    char * Upstr = malloc(sizeof(char) * lenght + 1);
    if(Upstr != s21_NULL) {
        for(s21_size_t i = 0; i < lenght; i++) {
            if(str[i] >= 97 && str[i] <= 122) {
                Upstr[i] = str[i] - 32;
            }
            else {
                Upstr[i] = str[i];
            }
        }
    }
    return Upstr;
}

char * s21_to_lower(const char *str) {

    s21_size_t lenght = strlen(str); // по окончанию переключить strlen на s21_strlen  !!!!
    char * lowstr = malloc(sizeof(char) * lenght + 1);
    if(lowstr != s21_NULL) {
        for(s21_size_t i = 0; i < lenght; i++) {
            if(str[i] >= 65 && str[i] <= 90) {
                lowstr[i] = str[i] + 32;
            }
            else {
                lowstr[i] = str[i];
            }
        }
    }
    return lowstr;
}

char * s21_insert(const char *src, const char *str, s21_size_t start_index) {

    s21_size_t z = 0;
    char * newstr = s21_NULL;
    s21_size_t lenght = strlen(str) + strlen(src) + 1; // по окончанию переключить strlen на s21_strlen  !!!!
    if(start_index <= strlen(src) - 1)
        newstr = malloc(sizeof(char) * lenght);
    if(newstr != s21_NULL) {
        for(s21_size_t i = 0; i < lenght; i++) {
            newstr[i] = src[z++];
            if(i == start_index)
                for(s21_size_t y = 0; y < strlen(str); y++)
                    newstr[++i] = str[y];
        }
        newstr[lenght - 1] = '\0';
    }   
    return newstr;
}

char * s21_trim(const char *src, const char *trim_chars) {

    int y = 0;
    s21_size_t start = 0;
    s21_size_t lenght = strlen(src); // по окончанию переключить strlen на s21_strlen  !!!!
    s21_size_t end = lenght;
    for(s21_size_t i = 0; i < lenght; i++) {
        if(strchr(trim_chars, src[i]) != s21_NULL && start == i) { // по окончанию переключить strchr на s21_strchr  !!!!
            start++;
        }
        if(strchr(trim_chars, src[lenght - i]) != s21_NULL && end == lenght - i) {  // по окончанию переключить strchr на s21_strchr  !!!!
            end--;
        }
        if(start > end)
            break;
    }
    char * strtrim = s21_NULL;
    if(start <= end)
        strtrim = malloc(sizeof(char) * (end - start) + 1);
    if(strtrim) {
        for(s21_size_t i = start; i <= end; i++)
            strtrim[y++] = src[i];
        strtrim[y] = '\0';
    }
    return strtrim;
}