ThisIsMyExecutable: main.o FakeClass.o
	g++ main.o FakeClass.o -o ThisIsMyExecutable

main.o: main.cpp
	g++ -c main.cpp

FakeClass.o: FakeClass.cpp FakeClass.h
	g++ -c FakeClass.cpp