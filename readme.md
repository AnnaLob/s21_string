## Running suite(s): s21_string
### 93%: Checks: 99, Failures: 6, Errors: 0
* tests/test_string.c:668:F:s21_string_cases:test_strrchr6:0: Assertion 's21_result == result' failed: s21_result == 0, result == 0xffffcb931580
* tests/test_string.c:784:F:s21_string_cases:test_to_upper1:0: Assertion 's21_result == result' failed: s21_result == "HELLO, PEOPLE!!!g.c", result == "HELLO, PEOPLE!!!"
* tests/test_string.c:791:F:s21_string_cases:test_to_upper3:0: Assertion 's21_result == ""' failed: s21_result == "���S
                                                                                                                     ", "" == ""
* tests/test_string.c:809:F:s21_string_cases:test_to_lower1:0: Assertion 's21_result == result' failed: s21_result == "hello, people!!!g.c", result == "hello, people!!!"
* tests/test_string.c:816:F:s21_string_cases:test_to_lower3:0: Assertion 's21_result == ""' failed: s21_result == "���S
                                                                                                                     ", "" == ""
* tests/test_string.c:875:F:s21_string_cases:test_trim1:0: Assertion 's21_result == result' failed: s21_result == "Hello, w0rld!", result == "H, w0rld!"

#### make: *** [Makefile:25: gcov_report] Error 1

