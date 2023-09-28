#!/bin/bash
FLAGS=-Wall -Wextra -Werror

CC=gcc
# FUNC_FILES_C=*.c|*_test.c
FUNC_FILES_O=*.o
CHECKFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage
LIBNAME=s21_string.a
GLFLAGS=--coverage
SAN=-fsanitize=address
GCOVFLAGS=-fprofile-arcs -ftest-coverage
sourceFilesArray=$(ls sourceFiles)
arr = s21_memchr s21_memcpy s21_strerror s21_strcpy s21_strstr s21_strtok\
s21_memset s21_strrchr s21_strspn s21_memcmp s21_memmove s21_strcat s21_strncat\
s21_strchr s21_strcmp s21_strncmp s21_strncpy s21_strcspn s21_strlen s21_strpbrk \
s21_strspn s21_strstr s21_to_upper s21_to_lower s21_strchr s21_sprintf s21_trim s21_insert
test="_test"
c=".c"
dir="tests/"

all: s21_string.a

s21_string.a: build_object_files_verter build_library clean

test: build_object_files build_library build_test start_tests gcov_report

style: 
	clang-format -style=google -n *.c

build_object_files:
	for i in $(arr);do\
		$(CC) $(FLAGS) $(GCOVFLAGS) $(GLFLAGS) -c $$i$(c);\
	done

build_object_files_verter:
	for i in $(arr);do\
		$(CC) $(FLAGS) -c $$i$(c);\
	done

build_library:
	ar rcs $(LIBNAME) $(FUNC_FILES_O)

build_test: 
	for i in $(arr);do \
		$(CC) $(CHECKFLAGS) $(GLFLAGS) $(GCOVFLAGS) $$i$(test)$(c) -L. s21_string.a  -o $$i$(test); \
	done

start_tests:
	for i in $(arr);do \
		./$$i$(test); \
	done

start_leaks_tests: build_object_files build_library build_test 
	for i in $(arr);do \
		leaks -atExit -- ./$$i$(test); \
	done

gcov_report: build_object_files build_library build_test start_tests
	lcov -o tests.info -c -d .  
	genhtml -o report tests.info
	open report/index.html
	make clean


cleanAll:
	rm -rf *.o *.gcno *.gcov *.gcda *.a *.info *_test report

clean:
	rm -rf *.o *.gcno *.gcov *.gcda *.info *_test

rebuild:
	make clean
	make