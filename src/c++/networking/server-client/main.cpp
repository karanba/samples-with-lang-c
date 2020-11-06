#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {

  cout << "Server is UP" << endl;

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    cout << "Failed to create socket. errno: " << errno << endl;

    exit(EXIT_FAILURE);
  }

  sockaddr_in sockaddr;
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = INADDR_ANY;
  sockaddr.sin_port = htons(9999);

  if (bind(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) < 0) {
    cout << "Failed to bind to port 9999. errno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  if (listen(sockfd, 10) < 0) {
    cout << "Failed to listen on socket. errno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  auto addrlen = sizeof(sockaddr);
  int connection =
      accept(sockfd, (struct sockaddr *)&sockaddr, (socklen_t *)&addrlen);
  if (connection < 0) {
    cout << "Failed to grap connection. errno: " << errno << endl;
    exit(EXIT_FAILURE);
  }
  char buffer[1000];
  auto bytesRead = read(connection, buffer, 1000);
  cout << ".the message was: " << buffer;
  
  string response = "Good talking to you\n";
  send(connection, response.c_str(), response.size(), 0); 

  close(connection);
  close(sockfd);

  return 0;
}
