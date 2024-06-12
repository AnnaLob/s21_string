CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
CHECKIN = -I/opt/homebrew/include
CHECKFLAGS = -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck -lpthread -lm
# Флаги для llvm (gcov нет вроде не мак)
# LDFLAGS= -L/opt/homebrew/opt/llvm/lib
# CPPFLAGS= -I/opt/homebrew/opt/llvm/include


all: s21_string.a
	# собрать статическую библиотеку

s21_string.a: s21_string.o
	ar rcs $@ $^
	# ar сокращение от "archiver"
	# r - добавлять/ обновлять файлы obj
	# c - перезапись архива
	# s - флаг для создания статических библиотек

s21_string.o: s21_string/s21_string.c
	$(CC) $(CFLAGS) -c $<
	# $< указывает на файл в цели (первый или единственный)

test: test_string.o s21_string.o
	$(CC) $(CFLAGS) $(CHECKIN) $(CHECKFLAGS) -o $@ $^
	# $^ указывает на все перечисленные файлы в цели

test_string.o: tests/test_string.c
	$(CC) $(CFLAGS) $(CHECKIN) -c $<

clean:
	rm -f *.o *.a *.gcno *.gcda test
# https://gcc.gnu.org/onlinedocs/gcc/Freestanding-Environments.html
gcov_report:
	./test -s -coverage s21_*.c
    gcovr --exclude=tests/ -r. --html --html-details -s -o report.txt -b
	# генерирует отчет о покрытии кода тестами с использованием gcov
	# https://gcc.gnu.org/onlinedocs/gcc/Gcov-Intro.html
	# brew install llvm// затык - это аналог gcov только для вертера? и только на линукс!; на маке не формируется отчет report.txt

.PHONY: all test clean gcov_report
	# https://www.gnu.org/software/make/manual/html_node/Phony-Targets.html
