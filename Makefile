CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
CHECKIN = -I/usr/local/include
CHECKFLAGS = -L/usr/local/lib
GCOVFLAGS = -fprofile-arcs -ftest-coverage

s21_string.a: s21_string.o
	ar rcs $@ $^

s21_string.o: s21_string/s21_string.c
	$(CC) $(CFLAGS) $(CHECKIN) $(CHECKFLAGS) $(GCOVFLAGS) -c $<

test: test_string.o s21_string.o
	$(CC) $(CFLAGS) $(CHECKIN) $(CHECKFLAGS) $(GCOVFLAGS) -o $@ $^ -lcheck

test_string.o: tests/test_string.c tests/test.h
	$(CC) $(CFLAGS) $(CHECKIN) $(CHECKFLAGS) $(GCOVFLAGS) -c $<

clean:
	rm -f *.o *.a *.gcno *.gcda test 

gcov_report: s21_string.a test
	rm -f *.gcda *.gcno *.info
	$(CC) $(CFLAGS) s21_string/s21_string.c tests/test_string.c $(CHECKFLAGS) $(GCOVFLAGS) -o report -lm -lcheck
	./report
	lcov -t "gcov_report" -o Coverage_Report.info -c -d.
	genhtml -o report Coverage_Report.info
	open./report/index.html
	rm -f *.gcda *.gcno *.info report

.PHONY: all test clean gcov_report
