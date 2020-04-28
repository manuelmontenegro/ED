CPPFLAGS=-std=c++2a

all: test

test: run_tests
	./run_tests

run_tests: run_tests.o test_academia.o
	g++ -o run_tests run_tests.o test_academia.o

run_tests.o: run_tests.cpp

test_academia.o: test_academia.cpp academia.h

