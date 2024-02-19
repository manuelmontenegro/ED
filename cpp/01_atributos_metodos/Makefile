all: Test1

Fecha.o: Fecha.h Fecha.cpp
	g++ -c -o Fecha.o Fecha.cpp

Test1.o: Fecha.h Test1.cpp
	g++ -c -o Test1.o Test1.cpp

Test1: Test1.o Fecha.o
	g++ -o Test1 Test1.o Fecha.o