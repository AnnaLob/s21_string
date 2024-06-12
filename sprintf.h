//
// Created by Anna on 04.06.2024.
//
#include "s21_string/s21_string.h"

#ifndef STRING21__SPRINTF_H
#define STRING21__SPRINTF_H

void s21_sprintf ( char * str, const char * format, ... );
void s21_itos(unsigned long long int num, char* str);
char* s21_dtos(long double num, char* str);


#endif //STRING21__SPRINTF_H
