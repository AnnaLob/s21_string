
//
// Created by Anna on 04.06.2024.
//

#include "sprintf.h"
#include "stdarg.h"
#include "stdio.h"
#include "string.h"


void s21_itos(unsigned long long int num, char *str);

void setFlags(int n, int value, ...) {
    va_list factor;
    va_start(factor, value);
    for (int i = 0; i < n; i++) {
        *va_arg(factor, int*) = value;
    }
    va_end(factor);
}

void s21_sprintf(char *str, const char *format, ...) {

    int d;
    double f;
    //флаги
    int plusFlag = 0;
    int minusFlag = 0;
    int spaceFlag = 0;
    int percentFlag = 0;
    int calculatingAcc = 0;
    int calculating = 0;
    //длина и точность
    int length = 0;
    int acc = 0;

    static char num[1024] = {"\0"};
    va_list factor;         // указатель на необязательный параметр
    va_start(factor, format);   // устанавливаем указатель

    for (const char *c = format; *c; c++) {
        if (percentFlag) {
            if (*c >= '0' && *c <= '9') {
                calculating = 1;
                if (calculatingAcc) {
                    acc = acc * 10 + *c - '0';
                } else {
                    length = length * 10 + *c - '0';
                }
                continue;
            }
            if (!calculating) {
                switch (*c) {
                    case ' ':
                        spaceFlag = 1;
                        break;
                    case '+':
                        plusFlag = 1;
                        break;
                    case '-':
                        minusFlag = 1;
                        break;
                }
                continue;
            }
            switch (*c) {
                case '.':
                    //TODO если уже точка встречалась отмена нахуй всего ♥
                    calculatingAcc = 1;
                    break;
                case 'd':
                    d = va_arg(factor, int);
                    s21_itos(d < 0 ? -d : d, num);

                    if (minusFlag) {
                        length = 0;
                    }

                    int l = strlen(num);
                    int nulls = l > acc ? 0 : acc - l;
                    int spaces = length - nulls - l - (d < 0 || (plusFlag || spaceFlag) && d > 0);
                    int index = 0;

                    for (index = 0; index < spaces; index++) {
                        *str++ = ' ';
                    }

                    if (d < 0) {
                        *str++ = '-';
                    } else if ((plusFlag || spaceFlag) && d > 0) {
                        *str++ = plusFlag ? '+' : ' ';
                    }

                    for (int i = 0; i < nulls; index++, i++) {
                        *str++ = '0';
                    }

                    for (int i = 0; i < l; index++, i++) {
                        *str++ = num[i];
                    }

                    if (spaces < 0) {
                        spaces *= -1;
                        for (index = 0; index < spaces; index++) {
                            *str++ = ' ';
                        }
                    }

                    setFlags(8, 0, &plusFlag, &minusFlag, &spaceFlag, &percentFlag, &calculatingAcc, &length, &acc,
                             &calculating); //сбрасывает флаги;
                    break;

                case 'f':
                    f = va_arg(factor,double);
                    str = s21_dtos(f, str);
                    break;
            }
        } else if (*c == '%') {
            percentFlag = 1;
        } else {
            *str = *c;
            str++;
            continue;
        }
    }
    va_end(factor);
}

void s21_itos(unsigned long long int num, char *str) {
    long long unsigned int pow = 0, a = num;
    for (pow = 1; a >= 10; a /= 10) pow = pow * 10;
    for (; pow > 0; pow /= 10) {
        *str++ = '0' + num / pow;
        num %= pow;
    }
    *str = '\0';
}

char *s21_dtos(long double num, char *str) {
    if (num < 0) {
        *str++ = '-';
        num *= -1;
    }

    long long int intNum = num;

    long long unsigned int pow = 0;
    long double a = num;
    for (pow = 1; a >= 0; a /= 10.0) {
        pow = pow * 10;
    }
    for (; pow > 0; pow /= 10) {
        *str++ = '0' + num / pow;
        num /= pow;
    }
    *str = '\0';
    return str;


}

/*
int main(void)
{
    char s[20];
    s21_sprintf(s, "Count: %d \tPrice: %f", 24, 68.4);
    return 0;
}*/

int main() {
    static char s[1024] = {"\0"};
    static char s1[1024] = {"\0"};
    sprintf(s, "%-40.20dL\n", 8);
    printf("%s", s);
    s21_sprintf(s1, "%-40.20dL\n", 8);
    printf("%s", s1);
}