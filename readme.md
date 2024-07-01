## Running suite(s): s21_string
### 93%: Checks: 103, Failures: 7, Errors: 0
tests/test_string.c:784:F:s21_string_cases:test_to_upper1:0: Assertion 's21_result == result' failed: s21_result == "HELLO, PEOPLE!!!g.c", result == "HELLO, PEOPLE!!!"
tests/test_string.c:791:F:s21_string_cases:test_to_upper2:0: Assertion 's21_result == (void *)0' failed: s21_result == (null), (void *)0 == (null)
tests/test_string.c:798:F:s21_string_cases:test_to_upper3:0: Assertion 's21_result == ""' failed: s21_result == "姒�
                                                                                                                    ", "" == ""
tests/test_string.c:816:F:s21_string_cases:test_to_lower1:0: Assertion 's21_result == result' failed: s21_result == "hello, people!!!g.c", result == "hello, people!!!"
tests/test_string.c:823:F:s21_string_cases:test_to_lower2:0: Assertion 's21_result == (void *)0' failed: s21_result == (null), (void *)0 == (null)
tests/test_string.c:830:F:s21_string_cases:test_to_lower3:0: Assertion 's21_result == ""' failed: s21_result == "姒�
                                                                                                                    ", "" == ""
tests/test_string.c:858:F:s21_string_cases:test_insert2:0: Assertion 's21_result == (void *)0' failed: s21_result == (null), (void *)0 == (null)
make: *** [Makefile:25: gcov_report] Error 1

#### make: *** [Makefile:25: gcov_report] Error 1

