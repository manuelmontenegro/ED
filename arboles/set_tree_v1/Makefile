all: tests main

tests: run_tests
	./run_tests

tests_valgrind: run_tests
	valgrind ./run_tests

run_tests.o: run_tests.cpp

test_set_tree.o: test_set_tree.cpp set_tree.h

run_tests: run_tests.o test_set_tree.o
	g++ -o run_tests run_tests.o test_set_tree.o

main: main.cpp set_tree.h