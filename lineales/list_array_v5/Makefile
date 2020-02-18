all: tests main1 main2 main3

tests: run_tests
	./run_tests

tests_valgrind: run_tests
	valgrind ./run_tests

main1: main1.o
	g++ -o main1 main1.o

main1.o: main1.cpp list_array.h
	g++ -o main1.o -c main1.cpp

main2: main2.o
	g++ -o main2 main2.o

main2.o: main2.cpp list_array.h
	g++ -o main2.o -c main2.cpp

main3: main3.o
	g++ -o main3 main3.o

main3.o: main3.cpp list_array.h
	g++ -o main3.o -c main3.cpp

run_tests.o: run_tests.cpp
	g++ -o run_tests.o -c run_tests.cpp

test_list_array.o: test_list_array.cpp list_array.h
	g++ -o test_list_array.o -c test_list_array.cpp

run_tests: run_tests.o test_list_array.o
	g++ -o run_tests run_tests.o test_list_array.o