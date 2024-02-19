all: tests main

tests: run_tests
	./run_tests

tests_valgrind: run_tests
	valgrind ./run_tests

run_tests.o: run_tests.cpp

test_set_list.o: test_set_list.cpp set_list.h

run_tests: run_tests.o test_set_list.o
	g++ -o run_tests run_tests.o test_set_list.o

main: main.cpp set_list.h