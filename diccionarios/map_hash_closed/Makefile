CXXFLAGS="-std=c++17"

all: tests main

tests: run_tests
	./run_tests

tests_valgrind: run_tests
	valgrind ./run_tests

run_tests.o: run_tests.cpp

test_map_hash_closed.o: test_map_hash_closed.cpp map_hash_closed.h

run_tests: run_tests.o test_map_hash_closed.o
	g++ -o run_tests run_tests.o test_map_hash_closed.o

main: main.cpp map_hash_closed.h
