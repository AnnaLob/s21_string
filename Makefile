CC = gcc
CFLAGS = -Wall -Wextra -Werror -std=c11
CHECKIN = -I/opt/homebrew/include
CHECKFLAGS = -L/opt/homebrew/Cellar/check/0.15.2/lib -lcheck -lpthread -lm

all: blablabla

blablabla: test_s21_func.o s21_string.o
	$(CC) $(CFLAGS) $(CHECKIN) $(CHECKFLAGS) -o $@ $^

test_s21_func.o: test_s21_func/test_s21_func.c
	$(CC) $(CFLAGS) $(CHECKIN) -c $<

s21_string.o: s21_string/s21_string.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o blablabla