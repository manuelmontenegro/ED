CPPFLAGS=-std=c++2a

all: test

test: run_tests
	./run_tests

run_tests: run_tests.o test_metro.o test_horas.o hora.o
	g++ -o run_tests run_tests.o test_metro.o test_horas.o hora.o

run_tests.o: run_tests.cpp

test_horas.o: test_horas.cpp hora.h
test_metro.o: test_metro.cpp hora.h metro.h
hora.o: hora.cpp hora.h
