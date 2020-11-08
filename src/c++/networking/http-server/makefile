TARGET=http_server
normal: $(TARGET)


http_server: http_server.o
	g++ bin/http_server.o -o bin/http_server

http_server.o: http_server.cpp
	g++ -c http_server.cpp -o bin/http_server.o


