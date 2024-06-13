CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
CHECKIN = -I/opt/homebrew/include
CHECKFLAGS = -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck -lpthread -lm

all: s21_string.a

s21_string.a: s21_string.o
	ar rcs $@ $^

s21_string.o: s21_string/s21_string.c
	$(CC) $(CFLAGS) -c $<

test: test_string.o s21_string.o
	$(CC) $(CFLAGS) $(CHECKIN) $(CHECKFLAGS) -o $@ $^

test_string.o: tests/test_string.c
	$(CC) $(CFLAGS) $(CHECKIN) -c $<

clean:
	rm -f *.o *.a *.gcno *.gcda test

gcov_report:
	./test -s -coverage s21_*.c
    gcovr --exclude=tests/ -r. --html --html-details -s -o report.txt -b

.PHONY: all test clean gcov_report