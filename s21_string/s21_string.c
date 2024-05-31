#include "s21_string.h"

// Выполняет поиск первого вхождения символа c (беззнаковый тип) в первых n
// байтах строки, на которую указывает аргумент str
void *s21_memchr(const void *str, int c, s21_size_t n) {
  const char *ptr = str;
  int res = 0;
  for (int i = 0; i < (int)n; i++) {
    if (*ptr == c) {
      res = 1;
      break;
    }
    ptr++;
  }
  if (res == 0) {
    ptr = s21_NULL;
  }
  return (char *)ptr;
}

// Сравнивает первые n байтов str1 и str2
int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;
  for (int i = 0; i < (int)n; i++) {
    if (((char *)str1)[i] > ((char *)str2)[i]) {
      res = 1;
      break;
    }
    if (((char *)str1)[i] < ((char *)str2)[i]) {
      res = -1;
      break;
    } else {
      res = 0;
    }
  }
  return res;
}

// Копирует n символов из src в dest
void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  for (int i = 0; i < (int)n; ++i) {
    ((char *)dest)[i] = ((char *)src)[i];
  }
  return dest;
}

// Копирует символ c (беззнаковый тип) в первые n символов строки, на которую
// указывает аргумент str
void *s21_memset(void *str, int c, s21_size_t n) {
  unsigned char *ptr = (unsigned char *)str;
  unsigned char value = (unsigned char)c;
  for (s21_size_t i = 0; i < n; i++) {
    ptr[i] = value;
  }
  return str;
}

// Добавляет строку, на которую указывает src, в конец строки, на которую
// указывает dest, длиной до n символов
char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *ptr = dest;
  while (*ptr!= '\0') {
    ptr++;
  }
  s21_size_t src_len = strlen(src);
  s21_size_t min_len = (src_len < n)? src_len : n;
  for (s21_size_t i = 0; i < min_len; i++) {
    ptr[i] = src[i];
  }
  ptr[min_len] = '\0';
  return dest;
}
