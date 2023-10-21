CC = gcc
CFLAGS = -g -Wall -Werror -Wextra -std=c11
LFLAGS = -Wall -Werror -Wextra -g -fsanitize=leak -fsanitize=address -fsanitize=undefined -fsanitize=unreachable -fno-sanitize-recover -fstack-protector -fanalyzer
COVFLAGS = -fprofile-arcs -ftest-coverage
TESTFALGS = -lcheck
ifeq ($(shell uname), Linux)
	TESTFALGS += -lpthread -lrt -lsubunit -lm
endif
FILES = s21_string.c

all: s21_string.a

s21_string.a: s21_string.o
	ar rc s21_string.a  s21_string.o
	ranlib s21_string.a
	rm *.o

s21_string.o: s21_string.c s21_string.h
	$(CC) $(CFLAGS) -c s21_string.c -o s21_string.o

test: s21_string.a
	$(CC) $(CFLAGS) s21_test.c s21_string.a $(TESTFALGS) -o test_rez
	./test_rez

gcov_report:
	$(CC) $(CFLAGS) s21_test.c $(TESTFALGS) $(COVFLAGS) $(FILES) -o test_rez
	./test_rez
	lcov -t "String_tests" -o test_rez.info -c -d .
	genhtml -o report test_rez.info
	rm *.gcda *.gcno *.info
	open report/index.html

style:
	clang-format -i --style=Google *.c *.h

clean:
	rm -r report 
	rm test_rez 
	rm *.a

leaks: s21_string.a
	clear
	$(CC) $(CFLAGS) s21_test.c s21_string.a
	valgrind --tool=memcheck --leak-check=yes  ./a.out
	leaks -atExit -- ./a.out
	$(CC) $(LFLAGS) s21_test.c s21_string.a -o 1
	./1

.PHONY: all, test, gcov_report, style, clean, s21_string.a
