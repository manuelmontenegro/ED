all: tests main1

tests: run_tests
	./run_tests

tests_valgrind: run_tests
	valgrind ./run_tests

main1: main1.o
	g++ -o main1 main1.o

main1.o: main1.cpp
	g++ -o main1.o -c main1.cpp

run_tests.o: run_tests.cpp
	g++ -o run_tests.o -c run_tests.cpp

test_list_array.o: test_list_array.cpp list_array.h
	g++ -o test_list_array.o -c test_list_array.cpp

run_tests: run_tests.o test_list_array.o
	g++ -o run_tests run_tests.o test_list_array.o