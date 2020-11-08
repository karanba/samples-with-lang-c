#include <cstdlib>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
  char *address;
  address = argv[1];

  cout << "HTTP Client is UP" << endl;

  int sockfd;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    cout << "Failed to create socket. errno: " << errno << endl;
    exit(EXIT_FAILURE);
  }

  struct sockaddr_in remote_address;
  remote_address.sin_family = AF_INET;
  remote_address.sin_port = htons(80);
  inet_aton(address, &(remote_address.sin_addr.s_addr));

  connect(sockfd, (struct sockaddr *) &remote_address, sizeof(remote_address));
  char request[] = "GET / HTTP/1.1\r\n\r\n";
  char response[4096];
  

  send(sockfd, request, sizeof(request), 0);
  recv(sockfd, &response, sizeof(response), 0);

  cout << response << endl;

  close(sockfd);

  return 0;
}
