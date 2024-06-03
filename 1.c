#include "test_s21_func/test_s21_func.h"

void test_s21_memchr();
void test_s21_memchr1();
void test_s21_memcmp();
void test_s21_memcmp1();
void test_s21_memcpy();
void test_s21_memcpy1();
void test_s21_memset();
void test_s21_memset1();

int main() {
  test_s21_memchr();
  test_s21_memchr1();
  test_s21_memcmp();
  test_s21_memcmp1();
  test_s21_memcpy();
  test_s21_memcpy1();

  return 0;
}

void test_s21_memchr() {
  char *s21_result = s21_memchr("Hello, world", 'w', 13);
  char *result = memchr("Hello, world", 'w', 13);
  if ((s21_result - result) == 0) {
    printf("memchr: OK\n");
  } else {
    printf("memchr: Error\n");
  }
}
void test_s21_memchr1() {
  char *s21_result = s21_memchr("Hello, world", 'w', 13);
  char *result = memchr("Hello, world", 'W', 13);
  if ((s21_result - result) == 0) {
    printf("memchr_1: OK\n");
  } else {
    printf("memchr_1: Error\n");
  }
}

void test_s21_memcmp() {
  int a = s21_memcmp("Hello, world", "Hello, world", 13);
  int b = memcmp("Hello, world", "Hello, world", 13);
  if ((a - b) == 0) {
    printf("memcmp: OK\n");
  } else {
    printf("memcmp: Error\n");
  }
}

void test_s21_memcmp1() {
  int a = s21_memcmp("Hello, world", " ", 13);
  int b = memcmp("Hello, world", "Hello, world", 13);
  if (a == b) {
    printf("memcmp_1: OK\n");
  } else {
    printf("memcmp_1: Error\n");
  }
}

void test_s21_memcpy() {
  char dest[14];
  char *s21_result = s21_memcpy(dest, "Hello, world", 13);
  char *result = memcpy(dest, "Hello, world", 13);
  if (s21_result == result) {
    printf("memcpy: OK\n");
  } else {
    printf("memcpy: Error\n");
  }
}

void test_s21_memcpy1() {
  char s21_dest[15];
  char dest[15];
  char *s21_result = s21_memcpy(s21_dest, "Hello, world!", 14);
  char *result = memcpy(dest, "Hello, world", 14);
  if (s21_result == result) {
    printf("memcpy_1: OK\n");
  } else {
    printf("memcpy_1: Error\n");
  }
}

/*
void test_s21_memset() {
  char *buffer = "Hello, world";
  memset(buffer, 33, 14);
  char *s21_result = s21_memset(buffer, 33, 14);
  if (s21_result != NULL && memcmp(s21_result, buffer, 14) == 0) {
    printf("memset: OK\n");
  } else {
    printf("memset: Error\n");
  }
}
*/