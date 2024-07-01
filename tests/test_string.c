#include "test.h"

int sign_int(int x) {
    if (x > 0) {
        return 1;
    } else if (x < 0) {
        return -1;
    } else {
        return 0;
    }
}

START_TEST(test_memchr1) {
    char str[] = "Hello, w0rld";
    char *s21_result = s21_memchr(str, 'w', 100);
    char *result = memchr(str, 'w', 100);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memchr2) {
    char str[] = "Hello, w0rld";
    char *s21_result = s21_memchr(str, 'Z', s21_strlen(str));
    char *result = memchr(str, 'Z', strlen(str));
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memchr3) {
    char str[] = "Hello, w0rld";
    char *s21_result = s21_memchr(str, 'W', s21_strlen(str));
    char *result = memchr(str, 'W', s21_strlen(str));
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memchr4) {
    char str[] = "Hello, w0rld";
    char *s21_result = s21_memchr(str, '\0', 5);
    char *result = memchr(str, '\0', 5);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST
    
START_TEST(test_memchr5) {
    char str[] = "Hello, w0rld";
    char *s21_result = s21_memchr(str, '0', 10);
    char *result = memchr(str, '0', 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memchr6) {
    char str[] = "Hello, w\0rld";
    char *s21_result = s21_memchr(str, '\0', 18);
    char *result = memchr(str, '\0', 18);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST    

START_TEST(test_memcmp1) {
    char str1[] = "Hello, w0rld";
    char str2[] = "Hello, w0rld";
    int s21_result = s21_memcmp(str1, str2, s21_strlen(str1));
    int result = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_memcmp2) {
    char str1[] = "";
    char str2[] = "";
    int s21_result = s21_memcmp(str1, str2, s21_strlen(str1));
    int result = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_memcmp3) {
    char str1[] = "Hello, world";
    char str2[] = "Hello, w0rld!!!!!!!!!";
    int s21_result = s21_memcmp(str1, str2, 10);
    int result = memcmp(str1, str2, 10);
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_memcmp4) {
    char str1[] = "0123456789qwerty";
    char str2[] = "qwerty01234567";
    int s21_result = s21_memcmp(str1, str2, s21_strlen(str1));
    int result = memcmp(str1, str2, strlen(str1));
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_memcmp5) {
    char str1[] = "0123456789qwerty";
    char str2[] = "Hello";
    int s21_result = s21_memcmp(str1, str2, 1);
    ck_assert_int_eq(sign_int(s21_result), -1);
}
END_TEST

START_TEST(test_memcmp6) {
    char str1[] = "Hello";
    char str2[] = "0123456789qwerty";
    int s21_result = s21_memcmp(str1, str2, 1);
    ck_assert_int_eq(sign_int(s21_result), 1);
}
END_TEST

START_TEST(test_memcmp7) {
    char str1[] = "";
    char str2[] = "0123456789qwerty";
    int s21_result = s21_memcmp(str1, str2, 1);
    ck_assert_int_eq(sign_int(s21_result), -1);
}
END_TEST

START_TEST(test_memcpy1) {
    char dest[20];
    char src[] = "Hello, w0rld";
    char *s21_result = s21_memcpy(dest, src, s21_strlen(src) + 1);
    char *result = memcpy(dest, src, strlen(src) + 1);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memcpy2) {
    char dest[20] = "foo ";
    char src[] = "Hello, w0rld";
    char *s21_result = s21_memcpy(dest, src, 10);
    char *result = memcpy(dest, src, 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memcpy3) {
    char dest[20] = "12345678901234567890";
    char src[] = "Hello, w0rld";
    char *s21_result = s21_memcpy(dest, src, sizeof(dest));
    char *result = memcpy(dest, src, sizeof(dest));
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST
    
START_TEST(test_memcpy4) {
    char dest[20] = "Hello, w0rld";
    char src[] = "\n\0";
    char *s21_result = s21_memcpy(dest, src, 18);
    char *result = memcpy(dest, src, 18);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memcpy5) {
    char dest[20] = "Hello, w0rld";
    char src[] = "\t";
    char *s21_result = s21_memcpy(dest, src, sizeof(dest));
    char *result = memcpy(dest, src, sizeof(dest));
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memcpy6) {
    char dest[20] = "\0";
    char src[] = "Hello, w0rld";
    char *s21_result = s21_memcpy(dest, src, 5);
    char *result = memcpy(dest, src, 5);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_memset1) {
    char str[] = "Hello, w0rld";
    size_t n = 0;
    char *s21_res = s21_memset(str, 2, n);
    char *res = memset(str, 2, n);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_memset2) {
    char str[] = "Hello, w0rld";
    char *s21_res = s21_memset(str, 2, sizeof(str));
    char *res = memset(str, 2, sizeof(str));
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_memset3) {
    char str[] = "Hello, w0rld";
    char *s21_res = s21_memset(str, ' ', 3);
    char *res = memset(str, ' ', 3);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_memset4) {
    char str[] = "Hello, w0rld";
    char *s21_res = s21_memset(str, '\0', 3);
    char *res = memset(str, '\0', 3);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST
    
START_TEST(test_memset5) {
    char str[] = "\0";
    char *s21_res = s21_memset(str, 'r', 3);
    char *res = memset(str, 'r', 3);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_memset6) {
    char str[20] = "Hello, w0rld!";
    char *s21_res = s21_memset(str, '!', 20);
    char *res = memset(str, '!', 20);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_strncat1) {
    char dest[] = "Hello";
    char src[] = ", w0rld!";
    char *s21_res = s21_strncat(dest, src, 0);
    char *res = strncat(dest, src, 0);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_strncat2) {
    char dest[20] = "Hello";
    char src[] = ", w0rld!";
    char *s21_res = s21_strncat(dest, src, 6);
    char *res = strncat(dest, src, 6);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_strncat3) {
    char dest[20] = " ";
    char src[] = "HELLO, w0rld!";
    char *s21_res = s21_strncat(dest, src, 6);
    char *res = strncat(dest, src, 6);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_strncat4) {
    char dest[20] = "Hello, w0rld!!!!!";
    char src[] = "!";
    char *s21_res = s21_strncat(dest, src, 20);
    char *res = strncat(dest, src, 20);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_strncat5) {
    char dest[20] = "\0";
    char src[] = "!11111*";
    char *s21_res = s21_strncat(dest, src, 20);
    char *res = strncat(dest, src, 20);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_strncat6) {
    char dest[20] = "Hello, w0rld!!!!!";
    char src[] = "t\t\t";
    char *s21_res = s21_strncat(dest, src, 5);
    char *res = strncat(dest, src, 5);
    if (s21_res != NULL && res != NULL) {
        ck_assert_str_eq(s21_res, res);
    }
}
END_TEST

START_TEST(test_strchr1) {
    const char str[] = "Hello, w0rld";
    char *s21_result = s21_strchr(str, ',');
    char *result = strchr(str, ',');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strchr2) {
    const char str[] = "Hello, w0rld";
    char *s21_result = s21_strchr(str, 'L');
    char *result = strchr(str, 'L');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strchr3) {
    const char str[] = "Hello, w0rld";
    char *s21_result = s21_strchr(str, '\0');
    char *result = strchr(str, '\0');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strchr4) {
    const char str[] = "";
    char *s21_result = s21_strchr(str, 'H');
    char *result = strchr(str, 'H');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strchr5) {
    const char str[] = "Hello, w0rld";
    char *s21_result = s21_strchr(str, 'v');
    char *result = strchr(str, 'v');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strchr6) {
    const char str[] = "\n\n\n\\\"";
    char *s21_result = s21_strchr(str, '\n');
    char *result = strchr(str, '\n');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strncmp1) {
    char str1[] = "Hello, w0rld";
    char str2[] = "Hello, w0rld";
    int s21_result = s21_strncmp(str1, str2, sizeof(str1));
    int result = strncmp(str1, str2, sizeof(str1));
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_strncmp2) {
    const char *str1 = "Hello, w0rld!";
    const char *str2 = "Goodbye, w0rld";
    int s21_result = s21_strncmp(str1, str2, 10);
    int result = strncmp(str1, str2, 10);
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_strncmp3) {
    const char *str1 = "Hello, w0rld!";
    const char *str2 = "Hello, everyone!";
    int s21_result = s21_strncmp(str1, str2, 16);
    int result = strncmp(str1, str2, 16);
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_strncmp4) {
    const char *str1 = "";
    const char *str2 = "!";
    int s21_result = s21_strncmp(str1, str2, 16);
    int result = strncmp(str1, str2, 16);
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_strncmp5) {
    const char *str1 = "Hell\0, everyone!";
    const char *str2 = "Hello, everyone!";
    int s21_result = s21_strncmp(str1, str2, 16);
    int result = strncmp(str1, str2, 16);
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_strncmp6) {
    const char *str1 = "\nHello, w0rld";
    const char *str2 = "Hello, w0rld";
    int s21_result = s21_strncmp(str1, str2, 16);
    int result = strncmp(str1, str2, 16);
    ck_assert_int_eq(sign_int(s21_result), sign_int(result));
}
END_TEST

START_TEST(test_strncpy1) {
    char dest[20];
    char src[] = "Hello, w0rld";
    char *s21_result = s21_strncpy(dest, src, sizeof(dest));
    char *result = strncpy(dest, src, sizeof(dest));
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strncpy2) {
    char dest[5] = "\n";
    char src[] = "Hello, w0rld";
    char *s21_result = s21_strncpy(dest, src, 10);
    char *result = strncpy(dest, src, 10);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strncpy3) {
    char dest[20] = "12345678901234567";
    char src[] = "Hello, w0rld";
    char *s21_result = s21_strncpy(dest, src, 20);
    char *result = strncpy(dest, src, 20);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strncpy4) {
    char dest[20] = "";
    char src[] = "Hell\0, w\0rld";
    char *s21_result = s21_strncpy(dest, src, 20);
    char *result = strncpy(dest, src, 20);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strncpy5) {
    char dest[50] = "\t\\\\%###";
    char src[] = "Hello, w0rld\n";
    char *s21_result = s21_strncpy(dest, src, 20);
    char *result = strncpy(dest, src, 20);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strncpy6) {
    char dest[20] = "Hello, w0rld";
    char src[] = "";
    char *s21_result = s21_strncpy(dest, src, 3);
    char *result = strncpy(dest, src, 3);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strcspn1) {
    const char *str = "Hello, w0rld!";
    const char *reject = ",";
    s21_size_t s21_result = s21_strcspn(str, reject);
    size_t result = strcspn(str, reject);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_strcspn2) {
    const char *str = "\0";
    const char *reject = ",";
    s21_size_t s21_result = s21_strcspn(str, reject);
    size_t result = strcspn(str, reject);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_strcspn3) {
    const char *str = "!!!!!!!!!!!!!!";
    const char *reject = "!";
    s21_size_t s21_result = s21_strcspn(str, reject);
    size_t result = strcspn(str, reject);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_strcspn4) {
    const char *str = "Hello, w0rld!";
    const char *reject = "\0";
    s21_size_t s21_result = s21_strcspn(str, reject);
    size_t result = strcspn(str, reject);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_strcspn5) {
    const char *str = "Hello, w0rld!";
    const char *reject = "w0rld";
    s21_size_t s21_result = s21_strcspn(str, reject);
    size_t result = strcspn(str, reject);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_strcspn6) {
    const char *str = "";
    const char *reject = "";
    s21_size_t s21_result = s21_strcspn(str, reject);
    size_t result = strcspn(str, reject);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_strerror1) {
    int errnums[] = {0, 1, -2, 180, 123456789};
    for (int i = 0; i < 5; i++) {
        char *s21_result = s21_strerror(errnums[i]);
        char *result = strerror(errnums[i]);
        ck_assert_str_eq(s21_result, result);
    }
}
END_TEST

START_TEST(test_s21_strlen1) {
    const char *str = "Hello, w0rld!";
    int s21_result = s21_strlen(str);
    int result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strlen2) {
    const char *str = " Hello, %%%%%% w0rld! ";
    int s21_result = s21_strlen(str);
    int result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strlen3) {
    const char *str = "H e l l o , \t w o r l d ! ";
    int s21_result = s21_strlen(str);
    int result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strlen4) {
    const char *str = "Hello, \nw0rld!";
    int s21_result = s21_strlen(str);
    int result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strlen5) {
    const char *str = "\0\0\0\0";
    int s21_result = s21_strlen(str);
    int result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_s21_strlen6) {
    const char *str = "           ";
    int s21_result = s21_strlen(str);
    int result = strlen(str);
    ck_assert_int_eq(s21_result, result);
}
END_TEST

START_TEST(test_strpbrk1) {
    const char str1[] = "Hello, w0rld!";
    const char str2[] = "hELLO, W0RLD!";
    const char *s21_result = s21_strpbrk(str1, str2);
    const char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strpbrk2) {
    const char str1[] = "Hello, w0rld!";
    const char str2[] = "";
    const char *s21_result = s21_strpbrk(str1, str2);
    const char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strpbrk3) {
    const char str1[] = "Hello, w0rld!\t";
    const char str2[] = "\t0";
    const char *s21_result = s21_strpbrk(str1, str2);
    const char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strpbrk4) {
    const char str1[] = "Hello, w0rld!";
    const char str2[] = "\0";
    const char *s21_result = s21_strpbrk(str1, str2);
    const char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strpbrk5) {
    const char str1[] = "Hello, w0rld!";
    const char str2[] = "TTT";
    const char *s21_result = s21_strpbrk(str1, str2);
    const char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strpbrk6) {
    const char str1[] = "\0Hello, w0rld!";
    const char str2[] = "Hello";
    const char *s21_result = s21_strpbrk(str1, str2);
    const char *result = strpbrk(str1, str2);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strrchr1) {
    const char str[] = "Hello, w0rld";
    char *s21_result = s21_strrchr(str, 'X');
    char *result = strrchr(str, 'X');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strrchr2) {
    const char str[] = "";
    char *s21_result = s21_strrchr(str, 'l');
    char *result = strrchr(str, 'l');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strrchr3) {
    const char str[] = "Hello, w0rld";
    char *s21_result = s21_strrchr(str, '\0');
    char *result = strrchr(str, '\0');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strrchr4) {
    const char str[] = "_Hello_,__w0rld_!_";
    char *s21_result = s21_strrchr(str, '_');
    char *result = strrchr(str, '_');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strrchr5) {
    const char str[] = "Hello\n, w\0rld\n";
    char *s21_result = s21_strrchr(str, '\n');
    char *result = strrchr(str, '\n');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strrchr6) {
    const char str[] = "\0\0\00\0";
    char *s21_result = s21_strrchr(str, '0');
    char *result = strrchr(str, '0');
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strstr1) {
    const char str[] = "HellO, world!!!";
    const char chr[] = "o";
    char *s21_result = s21_strstr(str, chr);
    char *result = strstr(str, chr);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strstr2) {
    const char str[] = "Hello, world! !!";
    const char chr[] = "orld! ";
    char *s21_result = s21_strstr(str, chr);
    char *result = strstr(str, chr);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strstr3) {
    const char str[] = "Hello, w0rld!!!";
    const char chr[] = "qrld!";
    char *s21_result = s21_strstr(str, chr);
    char *result = strstr(str, chr);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strstr4) {
    const char str[] = "Hello, w0rld!!!";
    const char chr[] = "\0";
    char *s21_result = s21_strstr(str, chr);
    char *result = strstr(str, chr);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strstr5) {
    const char str[] = "Hell\0, w\0rld!!!";
    const char chr[] = "w";
    char *s21_result = s21_strstr(str, chr);
    char *result = strstr(str, chr);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strstr6) {
    const char str[] = "He\nllo, w\n0rld!!!";
    const char chr[] = "!!!";
    char *s21_result = s21_strstr(str, chr);
    char *result = strstr(str, chr);
    ck_assert_ptr_eq(s21_result, result);
}
END_TEST

START_TEST(test_strtok1) {
    char str[] = "Hello, w0rld! Foo-boo!";
    const char delim[] = "      ";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_strtok2) {
    char str[] = "Hello, w0rld! Foo-boo!";
    const char delim[] = "Foo";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_strtok3) {
    char str[] = "Hello, w0rld! Foo-boo!";
    const char delim[] = "&";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_strtok4) {
    char str[] = "Hello, w\trld! Foo-b\too!";
    const char delim[] = "\t";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_strtok5) {
    char str[] = "Hell\0, w\0rld! Foo-b\0o!";
    const char delim[] = "o";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_strtok6) {
    char str[] = "Hello, w0rld! Foo-boo!";
    const char delim[] = "";
    char *s21_result = s21_strtok(str, delim);
    char *result = strtok(str, delim);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(test_to_upper1) {
    const char str[] = "HeLLo, PeoPLe!!!";
    char result[] = "HELLO, PEOPLE!!!";
    char *s21_result = s21_to_upper(str);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_to_upper2) {
    char *s21_result = s21_to_upper(s21_NULL);
    ck_assert_str_eq(s21_result, s21_NULL);
    free(s21_result);
}
END_TEST

START_TEST(test_to_upper3) {
    char *s21_result = s21_to_upper("");
    ck_assert_str_eq(s21_result, "");
    free(s21_result);
}
END_TEST

START_TEST(test_to_upper4) {
    const char str[] = "HeLLo, Pe\0PLe!!!";
    char result[] = "HELLO, PE";
    char *s21_result = s21_to_upper(str);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_to_lower1) {
    const char str[] = "HeLLo, PeoPLe!!!";
    char result[] = "hello, people!!!";
    char *s21_result = s21_to_lower(str);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_to_lower2) {
    char *s21_result = s21_to_lower(s21_NULL);
    ck_assert_str_eq(s21_result, s21_NULL);
    free(s21_result);
}
END_TEST

START_TEST(test_to_lower3) {
    char *s21_result = s21_to_lower("");
    ck_assert_str_eq(s21_result, "");
    free(s21_result);
}
END_TEST

START_TEST(test_to_lower4) {
    const char str[] = "HeLLo, Pe\0PLe!!!";
    char result[] = "hello, pe";
    char *s21_result = s21_to_lower(str);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_insert1) {
    const char src[] = "";
    const char str[] = "";
    char result[] = "";
    char *s21_result = s21_insert(src, str, 0);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_insert2) {
    const char src[] = "Hello";
    const char str[] = "w0rld";
    char *s21_result = s21_insert(src, str, 10);
    ck_assert_str_eq(s21_result, s21_NULL);
    free(s21_result);
}
END_TEST

START_TEST(test_insert3) {
    const char src[] = "Hello,";
    const char str[] = " w0rld";
    char result[] = "Hello, w0rld";
    char *s21_result = s21_insert(src, str, 6);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_insert4) {
    const char src[] = "w0rld!";
    const char str[] = "Hello, ";
    char result[] = "Hello, w0rld!";
    char *s21_result = s21_insert(src, str, 0);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_insert5) {
    const char src[] = "Hellow0rld!";
    const char str[] = ", tratata ";
    char result[] = "Hello, tratata w0rld!";
    char *s21_result = s21_insert(src, str, 5);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_trim1) {
    const char src[] = "<<Hello, w0rld!>>";
    const char trim_chars[] = "><He!d";
    char result[] = "llo, w0rl";
    char *s21_result = s21_trim(src, trim_chars);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_trim2) {
    const char src[] = "w0rld!";
    const char trim_chars[] = "ello";
    char result[] = "w0rld!";
    char *s21_result = s21_trim(src, trim_chars);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_trim3) {
    const char src[] = "Hello, w0rld!";
    const char trim_chars[] = "";
    char result[] = "Hello, w0rld!";
    char *s21_result = s21_trim(src, trim_chars);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
}
END_TEST

START_TEST(test_trim4) {
    const char src[] = "Hello, w0rld!";
    const char trim_chars[] = "Hello, w0rld!";
    char result[] = "";
    char *s21_result = s21_trim(src, trim_chars);
    ck_assert_str_eq(s21_result, result);
    free(s21_result);
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
    tcase_add_test(test_cases, test_memchr5);
    tcase_add_test(test_cases, test_memchr6);
    tcase_add_test(test_cases, test_memcmp1);
    tcase_add_test(test_cases, test_memcmp2);
    tcase_add_test(test_cases, test_memcmp3);
    tcase_add_test(test_cases, test_memcmp4);
    tcase_add_test(test_cases, test_memcmp5);
    tcase_add_test(test_cases, test_memcmp6);
    tcase_add_test(test_cases, test_memcmp7);
    tcase_add_test(test_cases, test_memcpy1);
    tcase_add_test(test_cases, test_memcpy2);
    tcase_add_test(test_cases, test_memcpy3);
    tcase_add_test(test_cases, test_memcpy4);
    tcase_add_test(test_cases, test_memcpy5);
    tcase_add_test(test_cases, test_memcpy6);
    tcase_add_test(test_cases, test_memset1);
    tcase_add_test(test_cases, test_memset2);
    tcase_add_test(test_cases, test_memset3);
    tcase_add_test(test_cases, test_memset4);
    tcase_add_test(test_cases, test_memset5);
    tcase_add_test(test_cases, test_memset6);
    tcase_add_test(test_cases, test_strncat1);
    tcase_add_test(test_cases, test_strncat2);
    tcase_add_test(test_cases, test_strncat3);
    tcase_add_test(test_cases, test_strncat4);
    tcase_add_test(test_cases, test_strncat5);
    tcase_add_test(test_cases, test_strncat6);
    tcase_add_test(test_cases, test_strchr1);
    tcase_add_test(test_cases, test_strchr2);
    tcase_add_test(test_cases, test_strchr3);
    tcase_add_test(test_cases, test_strchr4);
    tcase_add_test(test_cases, test_strchr5);
    tcase_add_test(test_cases, test_strchr6);
    tcase_add_test(test_cases, test_strncmp1);
    tcase_add_test(test_cases, test_strncmp2);
    tcase_add_test(test_cases, test_strncmp3);
    tcase_add_test(test_cases, test_strncmp4);
    tcase_add_test(test_cases, test_strncmp5);
    tcase_add_test(test_cases, test_strncmp6);
    tcase_add_test(test_cases, test_strncpy1);
    tcase_add_test(test_cases, test_strncpy2);
    tcase_add_test(test_cases, test_strncpy3);
    tcase_add_test(test_cases, test_strncpy4);
    tcase_add_test(test_cases, test_strncpy5);
    tcase_add_test(test_cases, test_strncpy6);
    tcase_add_test(test_cases, test_strcspn1);
    tcase_add_test(test_cases, test_strcspn2);
    tcase_add_test(test_cases, test_strcspn3);
    tcase_add_test(test_cases, test_strcspn4);
    tcase_add_test(test_cases, test_strcspn5);
    tcase_add_test(test_cases, test_strcspn6);
    tcase_add_test(test_cases, test_strerror1);
    tcase_add_test(test_cases, test_s21_strlen1);
    tcase_add_test(test_cases, test_s21_strlen2);
    tcase_add_test(test_cases, test_s21_strlen3);
    tcase_add_test(test_cases, test_s21_strlen4);
    tcase_add_test(test_cases, test_s21_strlen5);
    tcase_add_test(test_cases, test_s21_strlen6);
    tcase_add_test(test_cases, test_strpbrk1);
    tcase_add_test(test_cases, test_strpbrk2);
    tcase_add_test(test_cases, test_strpbrk3);
    tcase_add_test(test_cases, test_strpbrk4);
    tcase_add_test(test_cases, test_strpbrk5);
    tcase_add_test(test_cases, test_strpbrk6);
    tcase_add_test(test_cases, test_strrchr1);
    tcase_add_test(test_cases, test_strrchr2);
    tcase_add_test(test_cases, test_strrchr3);
    tcase_add_test(test_cases, test_strrchr4);
    tcase_add_test(test_cases, test_strrchr5);
    tcase_add_test(test_cases, test_strrchr6);
    tcase_add_test(test_cases, test_strstr1);
    tcase_add_test(test_cases, test_strstr2);
    tcase_add_test(test_cases, test_strstr3);
    tcase_add_test(test_cases, test_strstr4);
    tcase_add_test(test_cases, test_strstr5);
    tcase_add_test(test_cases, test_strstr6);
    tcase_add_test(test_cases, test_strtok1);
    tcase_add_test(test_cases, test_strtok2);
    tcase_add_test(test_cases, test_strtok3);
    tcase_add_test(test_cases, test_strtok4);
    tcase_add_test(test_cases, test_strtok5);
    tcase_add_test(test_cases, test_strtok6);
    
    tcase_add_test(test_cases, test_to_upper1);
    tcase_add_test(test_cases, test_to_upper2);
    tcase_add_test(test_cases, test_to_upper3);
    tcase_add_test(test_cases, test_to_upper4);
    tcase_add_test(test_cases, test_to_lower1);
    tcase_add_test(test_cases, test_to_lower2);
    tcase_add_test(test_cases, test_to_lower3);
    tcase_add_test(test_cases, test_to_lower4);
    tcase_add_test(test_cases, test_insert1);
    tcase_add_test(test_cases, test_insert2);
    tcase_add_test(test_cases, test_insert3);
    tcase_add_test(test_cases, test_insert4);
    tcase_add_test(test_cases, test_insert5);
    tcase_add_test(test_cases, test_trim1);
    tcase_add_test(test_cases, test_trim2);
    tcase_add_test(test_cases, test_trim3);
    tcase_add_test(test_cases, test_trim4);

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
    srunner_run_all(sr, CK_NORMAL);
    srunner_set_fork_status(sr, CK_NOFORK); //тесты в текущем процессе
    number_failed = srunner_ntests_failed(sr); // Подсчет неудачных тестов
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
