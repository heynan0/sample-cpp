ThisIsMyExecutable: main.o
	g++ main.o -o ThisIsMyExecutable

main.o: main.cpp
	g++ -c main.cpp
