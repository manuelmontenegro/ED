all: tests main

tests: run_tests
	./run_tests

tests_valgrind: run_tests
	valgrind ./run_tests

run_tests.o: run_tests.cpp

test_map_hash_open.o: test_map_hash_open.cpp map_hash_open.h

run_tests: run_tests.o test_map_hash_open.o
	g++ -o run_tests run_tests.o test_map_hash_open.o

main: main.cpp map_hash_open.h