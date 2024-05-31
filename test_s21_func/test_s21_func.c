#include "test_s21_func.h"

START_TEST(test_memchr1) {
  char str[] = "Hello, world";
  char *result_s21 = s21_memchr(str, 'w', strlen(str)); // заменить strlen на свою функцию
  char *result = memchr(str, 'w', strlen(str));
  ck_assert_ptr_eq(result_s21, result); // функция проверки, что указатели указывают на одно и то же место в памяти
}
END_TEST

START_TEST(test_memchr2) {
  char str[] = "Hello, world";
  char *result_s21 = s21_memchr(str, 'Z', strlen(str));
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

/*
START_TEST(test_memchr5) {
  char str = {0};
  char *result_s21 = s21_memchr(str, 'w', strlen(str));
  char *result = (str, 'w', strlen(str));
  ck_assert_ptr_eq(result_s21, result);
}
END_TEST
*/

START_TEST(test_memcmp1) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, world";
  int result_s21 = s21_memcmp(str1, str2, strlen(str1)); // заменить strlen на свою функцию
  int result = memcmp(str1, str2, strlen(str1));

  // функция проверки, сравнение значений двух переменных int на равенство
  ck_assert_int_eq(result_s21, result);
}
END_TEST

START_TEST(test_memcpy) {
  char dest[20];
  char src[] = "Hello, world";
  char *result_s21 = s21_memcpy(dest, src, strlen(src) + 1); // заменить strlen на свою функцию
  char *result = memcpy(dest, src, strlen(src) + 1);

  ck_assert_ptr_eq(result_s21, result);
}
END_TEST

START_TEST(test_memset) {
  char str1[] = "Hello, world";
  char str2[] = "Hello, world";
  int c = '2';
  int n = 14;

  ck_assert_str_eq(memset(str1, c, n), s21_memset(str2, c, n));
}
END_TEST

START_TEST(test_strncat) {
  char dest[12] = "Hello, ";
  char src[] = "world";
  int n = 10;
  char *result_s21 = s21_strncat(dest, src, n);
  char *result = strncat(dest, src, n);

  ck_assert_str_eq(result_s21, result);
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
  tcase_add_test(test_cases, test_memcpy);
  tcase_add_test(test_cases, test_memset);
  tcase_add_test(test_cases, test_strncat); //когда n равно 0, когда n больше длины src, и когда n больше длины dest

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
