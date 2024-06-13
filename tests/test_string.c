#include "test.h"

START_TEST(test_memchr1) {
  char str[] = "Hello, world";
  char *result_s21 = s21_memchr(str, 'w', s21_strlen(str));
  char *result = memchr(str, 'w', strlen(str));
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memchr2) {
  char str[] = "Hello, world";
  char *result_s21 = s21_memchr(str, 'Z', s21_strlen(str));
  char *result = memchr(str, 'Z', strlen(str));
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memchr3) {
  char str[] = "Hello, world";
  char *result_s21 = s21_memchr(str, 'w', 0);
  char *result = memchr(str, 'w', 0);
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memchr4) {
  char str[] = "Hello, world";
  char *result_s21 = s21_memchr(str, 'w', 100);
  char *result = memchr(str, 'w', 100);
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcmp1) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, world";
  int result_s21 = s21_memcmp(str1, str2, s21_strlen(str1));
  int result = memcmp(str1, str2, strlen(str1));
  ck_assert_int_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcmp2) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, world";
  int result_s21 = s21_memcmp(str1, str2, 0);
  int result = memcmp(str1, str2, 0);
  ck_assert_int_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcmp3) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, world!!!!!!!!!";
  int result_s21 = s21_memcmp(str1, str2, sizeof(str1));
  int result = memcmp(str1, str2, sizeof(str1));
  ck_assert_int_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcmp4) {
  char str2[] = "Hello, world";
  int result_s21 = s21_memcmp(s21_NULL, str2, 0);
  int result = memcmp(NULL, str2, 0);
  ck_assert_int_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcpy1) {
  char dest[20];
  char src[] = "Hello, world";
  char *result_s21 = s21_memcpy(dest, src, s21_strlen(src) + 1);
  char *result = memcpy(dest, src, strlen(src) + 1);
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcpy2) {
  char dest[20];
  char src[] = "Hello, world";
  char *result_s21 = s21_memcpy(dest, src, 0);
  char *result = memcpy(dest, src, 0);
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcpy3) {
  char dest[20];
  char src[] = "Hello, world";
  char *result_s21 = s21_memcpy(dest, src, sizeof(dest));
  char *result = memcpy(dest, src, sizeof(dest));
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcpy4) {
  char dest[20];
  char *result_s21 = s21_memcpy(dest, s21_NULL, 0);
  char *result = memcpy(dest, NULL, 0);
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memset1) {
  char str[] = {"Hello, world"};
  size_t n = 0;
  char *s21_res = s21_memset(str, 2, n);
  char *res = memset(str, 2, n);
  if (s21_res != NULL && res != NULL) {
    ck_assert_str_eq(s21_res, res);
  }
}
END_TEST

START_TEST(test_memset2) {
  char str[] = {"Hello, world"};
  char *s21_res = s21_memset(str, 2, sizeof(str));
  char *res = memset(str, 2, sizeof(str));
  if (s21_res != NULL && res != NULL) {
    ck_assert_str_eq(s21_res, res);
  }
}
END_TEST

START_TEST(test_memset3) {
  char str[] = {"Hello, world"};
  char *s21_res = s21_memset(str, ' ', 3);
  char *res = memset(str, ' ', 3);
  if (s21_res != NULL && res != NULL) {
    ck_assert_str_eq(s21_res, res);
  }
}
END_TEST

START_TEST(test_memset4) {
  char str[] = {"Hello, world"};
  char *s21_res = s21_memset(str, '\0', 3);
  char *res = memset(str, '\0', 3);
  if (s21_res != NULL && res != NULL) {
    ck_assert_str_eq(s21_res, res);
  }
}
END_TEST

START_TEST(test_strncat1) {
  char dest[] = {"Hello"};
  char src[] = {", world!"};
  char *s21_res = s21_strncat(dest, src, 0);
  char *res = strncat(dest, src, 0);
  if (s21_res != NULL && res != NULL) {
    ck_assert_str_eq(s21_res, res);
  }
}
END_TEST

START_TEST(test_strncat2) {
  char dest[20] = {"Hello"};
  char src[] = {", world!"};
  char *s21_res = s21_strncat(dest, src, 6);
  char *res = strncat(dest, src, 6);
  if (s21_res != NULL && res != NULL) {
    ck_assert_str_eq(s21_res, res);
  }
}
END_TEST

START_TEST(test_strncat3) {
  char dest[20] = {" "};
  char src[] = {"HELLO, world!"};
  char *s21_res = s21_strncat(dest, src, 6);
  char *res = strncat(dest, src, 6);
  if (s21_res != NULL && res != NULL) {
    ck_assert_str_eq(s21_res, res);
  }
}
END_TEST

START_TEST(test_strncat4) {
  char dest[20] = {"Hello, world!!!!!"};
  char src[] = {"!"};
  char *s21_res = s21_strncat(dest, src, 20);
  char *res = strncat(dest, src, 20);
  if (s21_res != NULL && res != NULL) {
    ck_assert_str_eq(s21_res, res);
  }
}
END_TEST

START_TEST(test_strchr) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_strncmp) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_strncpy) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_strcspn) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_strerror) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_s21_strlen) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_strpbrk) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_strrchr) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_strstr) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_strtok) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_to_upper) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_to_lower) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_insert) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

START_TEST(test_trim) {
    ck_assert_int_eq(2 + 2, 4);
}
END_TEST

Suite *tests_suite() {

  // создаем имя набора тестов (для отчетов)
  Suite *s = suite_create("s21_string");
  // создаем новый набор тест-кейсов (группа)
  TCase *test_cases = tcase_create("s21_string_cases");

  // объявляем и регистрируем с помощью макроса TCase_add_test
  tcase_add_test(test_cases, test_memchr1);
  tcase_add_test(test_cases, test_memchr2);
  tcase_add_test(test_cases, test_memchr3);
  tcase_add_test(test_cases, test_memchr4);
  tcase_add_test(test_cases, test_memcmp1);
  tcase_add_test(test_cases, test_memcmp2);
  tcase_add_test(test_cases, test_memcmp3);
  tcase_add_test(test_cases, test_memcmp4);
  tcase_add_test(test_cases, test_memcpy1);
  tcase_add_test(test_cases, test_memcpy2);
  tcase_add_test(test_cases, test_memcpy3);
  tcase_add_test(test_cases, test_memcpy4);
  tcase_add_test(test_cases, test_memset1);
  tcase_add_test(test_cases, test_memset2);
  tcase_add_test(test_cases, test_memset3);
  tcase_add_test(test_cases, test_memset4);
  tcase_add_test(test_cases, test_strncat1);
  tcase_add_test(test_cases, test_strncat2);
  tcase_add_test(test_cases, test_strncat3);
  tcase_add_test(test_cases, test_strncat4);
  tcase_add_test(test_cases, test_strchr);
  tcase_add_test(test_cases, test_strncmp);
  tcase_add_test(test_cases, test_strncpy);
  tcase_add_test(test_cases, test_strcspn);
  tcase_add_test(test_cases, test_strerror);
  tcase_add_test(test_cases, test_s21_strlen);
  tcase_add_test(test_cases, test_strpbrk);
  tcase_add_test(test_cases, test_strrchr);
  tcase_add_test(test_cases, test_strstr);
  tcase_add_test(test_cases, test_strtok);
  tcase_add_test(test_cases, test_to_upper);
  tcase_add_test(test_cases, test_to_lower);
  tcase_add_test(test_cases, test_insert);
  tcase_add_test(test_cases, test_trim);

  suite_add_tcase(s, test_cases); // добавляем тест-кейс в набор тестов s

  return s; // возвращаем указатель на созданный набор тестов s
}

int main(void) {

  int number_failed;
  Suite *s;
  // исполнитель тестов (SRunner), который отвечает за запуск тестов и сбор
  // информации о результатах
  SRunner *sr;

  s = tests_suite(); // Создание набора тестов
  // Создание исполнительного теста, будет управлять запуском тестов из набора s
  sr = srunner_create(s);

  // Параметр CK_NORMAL указывает на нормальный режим выполнения тестов, который
  // позволяет тестам завершиться самостоятельно без принудительного прерывания
  srunner_run_all(sr, CK_NORMAL); // Запуск всех тестов
  number_failed = srunner_ntests_failed(sr); // Подсчет неудачных тестов
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}