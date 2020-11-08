#include <cstdlib>
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {

  cout << "HTTP Server is UP" << endl;

  FILE *html;
  html = fopen("wwwroot/index.html", "r");

  char response[1024];
  fgets(response, 1024, html);

  char http_header[2048] = "HTTP/1.1 200 OK\r\n\n";
  strcat(http_header, response);

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    cout << "Failed to create socket. errno: " << errno << endl;

    exit(EXIT_FAILURE);
  }

  struct sockaddr_in sockaddr;
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

  while (1) {
    auto addrlen = sizeof(sockaddr);
    int connection = accept(sockfd, NULL, NULL);
    if (connection < 0) {
      cout << "Failed to grap connection. errno: " << errno << endl;
      exit(EXIT_FAILURE);
    }

    send(connection, http_header, sizeof(http_header), 0);
    close(connection);
  }

  close(sockfd);

  return 0;
}
