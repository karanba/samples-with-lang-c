TARGET=http_client
normal: $(TARGET)


http_client: http_client.o
	g++ bin/http_client.o -o bin/http_client

http_client.o: http_client.cpp
	g++ -c http_client.cpp -o bin/http_client.o



