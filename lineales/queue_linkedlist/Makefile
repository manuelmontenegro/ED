all: tests main1
tests: run_tests
	./run_tests

tests_valgrind: run_tests
	valgrind ./run_tests

main1: main1.o
	g++ -o main1 main1.o

main1.o: main1.cpp queue_linkedlist.h
	g++ -o main1.o -c main1.cpp

run_tests.o: run_tests.cpp
	g++ -o run_tests.o -c run_tests.cpp

test_queue.o: test_queue.cpp queue_linkedlist.h
	g++ -o test_queue.o -c test_queue.cpp

run_tests: run_tests.o test_queue.o
	g++ -o run_tests run_tests.o test_queue.o