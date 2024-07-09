//Created by Nekrasov Sergey and Lobanova Anna

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

typedef struct Flags {
    int plus;
    int minus;
    int space;
    int acc_flag;
    int accuracy;
    int length;
    int parsing_process;
    int lonG;
    int shorT;
} flag_t;

int s21_sprintf(char *str, const char *format, ...);
void parse(char *str, char *format);
void int_function(char **str);
void double_function(char **str);
void round_dub(double dub, char ***str);
void char_function(char **str);
void string_function(char **str);
void unsigned_int_function(char **str);
void percent_function(char **str);
void acc_width_function(char *format);
int num_length(long int n);
int num_length_unsigned(unsigned int n);

va_list factor;         // указатель на необязательный параметр
flag_t f = {0};

int main() {
    static char s1[1024] = {"\0"};
    static char s2[1024] = {"\0"};

    sprintf(s1, "%+5.12f %% %-2.0f %-40.20d % 12f %-20c %-40.15fA\n", 0.0, -123.456, 1982634, 34531345.34565342, 'f',
            1234567.987654345678987654);
    printf("%s", s1);
    s21_sprintf(s2, "%+5.12f %% %-2.0f %-40.20d % 12f %-20c %-40.15fA\n", 0.0, -123.456, 1982634, 34531345.34565342,
                'f', 1234567.987654345678987654);
    printf("%s", s2);
    return 0;
}

int s21_sprintf(char *str, const char *format, ...) {
    va_start(factor, format);// устанавливаем указатель
    parse(str, (char *) format);
    va_end(factor);
    return (int)strlen(str);
}

void parse(char *str, char *format) {
    while (*format != '\0') {
        if (*format == '%' && !f.parsing_process) {
            f.parsing_process = 1;
        } else {
            if (f.parsing_process) {
                switch (*format) {
                    case 'd': {
                        int_function(&str);
                        break;
                    }
                    case 'f': {
                        double_function(&str);
                        break;
                    }
                    case 'c': {
                        char_function(&str);
                        break;
                    }
                    case 's': {
                        string_function(&str);
                        break;
                    }
                    case 'u': {
                        unsigned_int_function(&str);
                        break;
                    }
                    case '%': {
                        percent_function(&str);
                        break;
                    }
                    case ' ':
                        if (!f.plus) {
                            f.space = 1;
                        }
                        break;
                    case '-':
                        f.minus = 1;
                        break;
                    case '+':
                        f.plus = 1;
                        f.space = 0;
                        break;
                    case '.':
                        f.acc_flag = 1;
                        break;
                    case 'h':
                        f.shorT = 1;
                        break;
                    case 'l':
                        f.lonG = 1;
                        break;
                    default:
                        if ((*format) >= '0' && (*format) <= '9') {
                            acc_width_function(format);
                            break;
                        } else {
                            return;
                        }
                }
            } else {
                *str++ = *format;
            }
        }
        format++;
    }
    *str = '\0';
}

void int_function(char **str) {
    long int d = va_arg(factor, long int);
    if (f.shorT) {
        d = (short int) d;
    }
    if (f.lonG) {
        d = (long int)d;
    }

    int nulls = f.accuracy ? ((f.accuracy - num_length(d)) < 0 ? 0 : f.accuracy - num_length(d)) : 0;

    int spaces = f.length - num_length(d) - f.plus - f.space - nulls;
    if (!f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }
    if (d >= 0) {
        if (f.plus) {
            *(*str)++ = '+';
        }
        if (f.space) {
            *(*str)++ = ' ';
        }
    }
    if (d == 0) {
        *(*str)++ = '0';
    }
    if (d < 0) {
        d *= -1;
        *(*str)++ = '-';
    }
    if (f.acc_flag) {
        for (int i = 0; i < nulls; i++) {
            *(*str)++ = '0';
        }
    }
    long int d_copy = d;
    int digit = 0;
    for (int i = num_length(d) - 1; i > -1; i--) {
        digit = (int) (d_copy / pow(10, i));
        *(*str)++ = '0' + digit;
        d_copy -= digit * (int) pow(10, i);
    }
    if (f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }
    f = (struct Flags) {0};
}

void double_function(char **str) {
    double dub = va_arg(factor, double);
    int spaces = f.length - num_length(dub) - f.acc_flag - (f.accuracy ? f.accuracy : 6) - f.plus - f.space -
                 (dub < 0 ? 1 : 0);

    if (!f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }

    if (dub >= 0) {
        if (f.plus) {
            *(*str)++ = '+';
        }
        if (f.space) {
            *(*str)++ = ' ';
        }
    }

    if (dub < 0) {
        dub *= -1;
        *(*str)++ = '-';
    }
    if (dub) {
        round_dub(dub, &str);
    } else {
        *(*str)++ = '0';
        *(*str)++ = '.';
        for (int i = 0; i < f.accuracy; i++) {
            *(*str)++ = '0';
        }
    }

    if (f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }

    f = (struct Flags) {0};
}

void round_dub(double dub, char ***str) {
    int dub_main = (int) dub;
    double shift = pow(10, f.accuracy ? f.accuracy : 6);
    double fract = round((dub - dub_main) * shift);
    dub = dub_main + fract / shift;
    int dub_main_result = (int) dub;
    long int dub_fract_result = (long int) fract;

    long int d_copy = dub_main_result;
    int digit = 0;
    for (int i = num_length(dub_main_result) - 1; i > -1; i--) {
        digit = (int) (d_copy / pow(10, i));
        *(*(*str))++ = '0' + digit;
        d_copy -= digit * (int) pow(10, i);
    }

    if (f.acc_flag && f.accuracy == 0) {
        return;
    }

    *(*(*str))++ = '.';

    d_copy = dub_fract_result;
    digit = 0;
    for (int i = num_length(dub_fract_result) - 1; i > -1; i--) {
        digit = (long int) (d_copy / pow(10, i));
        *(*(*str))++ = '0' + digit;
        d_copy -= digit * (long int) pow(10, i);
    }
}

void char_function(char **str) {
    char c = va_arg(factor, int);
    int spaces = f.length - 1;

    if (!f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }

    *(*str)++ = (char) (c);

    if (f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }
    f = (struct Flags) {0};
}

void string_function(char **str) {
    char *str_copy = va_arg(factor, char*);

    int nulls = f.accuracy ? strlen(str_copy) - f.accuracy : 0;
    int spaces = f.length - strlen(str_copy) + (nulls > 0 ? nulls : 0);
    f.accuracy = f.accuracy > (int) strlen(str_copy) ? (int) strlen(str_copy) : f.accuracy;

    if (!f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }

    if (f.acc_flag) {
        for (int i = 0; i < f.accuracy; i++) {
            *(*str)++ = *str_copy++;
        }
    } else {
        while (*str_copy != 0) {
            *(*str)++ = *str_copy++;
        }
    }

    if (f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }

    f = (struct Flags) {0};
}

void unsigned_int_function(char **str) {
    int a = va_arg(factor, int);
    unsigned int u = a;

    if (f.shorT) {
        u = (short unsigned int) u;
    }

    int nulls = f.accuracy - num_length_unsigned(u);
    int spaces = f.length - num_length_unsigned(u) - f.plus - f.space - nulls;

    if (!f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }
        if (f.plus) {
            *(*str)++ = '+';
        }
        if (f.space) {
            *(*str)++ = ' ';
        }

    if (u == 0) {
        *(*str)++ = '0';
    }

    if (f.acc_flag) {
        for (int i = 0; i < nulls; i++) {
            *(*str)++ = '0';
        }
    }
    unsigned int u_copy = u;
    unsigned int digit = 0;
    for (int i = num_length_unsigned(u) - 1; i > -1; i--) {
        digit = (unsigned int) (u_copy / pow(10, i));
        *(*str)++ = '0' + digit;
        u_copy -= digit * (unsigned int) pow(10, i);
    }
    if (f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }
    f = (struct Flags) {0};
}

void percent_function(char **str) {
    int spaces = f.length - 1;
    if (!f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }

    *(*str)++ = '%';

    if (f.minus) {
        for (int i = 0; i < spaces; i++) {
            *(*str)++ = ' ';
        }
    }

    f = (struct Flags) {0};
}

void acc_width_function(char *format) {
    if (f.acc_flag) {
        f.accuracy = f.accuracy * 10 + *format - '0';
    } else {
        f.length = f.length * 10 + *format - '0';
    }
}

int num_length(long int n) {
    long int n_copy = n < 0 ? -n : n;
    int count = 0;
    while (n_copy > 0) {
        count++;
        n_copy /= 10;
    }
    return count;
}

int num_length_unsigned(unsigned int n) {
    unsigned int n_copy = n;
    int count = 0;
    while (n_copy > 0) {
        count++;
        n_copy /= 10;
    }
    return count;
}