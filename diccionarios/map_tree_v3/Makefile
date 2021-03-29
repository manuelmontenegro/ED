CXXFLAGS="-std=c++17"
all: tests main

tests: run_tests
	./run_tests

tests_valgrind: run_tests
	valgrind ./run_tests

run_tests.o: run_tests.cpp

test_map_tree.o: test_map_tree.cpp map_tree.h

run_tests: run_tests.o test_map_tree.o
	g++ -o run_tests run_tests.o test_map_tree.o

main: main.cpp map_tree.h
