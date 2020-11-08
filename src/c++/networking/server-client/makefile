TARGET=client main
normal: $(TARGET)


client: client.o
	g++ bin/client.o -o bin/client

main: main.o 
	g++ bin/main.o -o bin/main

client.o: client.cpp
	g++ -c client.cpp -o bin/client.o

main.o: main.cpp
	g++ -c main.cpp -o bin/main.o


