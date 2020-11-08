#include <cstdlib>
#include <iostream>
#include <netinet/in.h>
#include <stdlib.h>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {

  cout << "Client UP" << endl;

  int network_socket;
  network_socket = socket(AF_INET, SOCK_STREAM, 0);

  if (network_socket == -1) {
    cout << "Failed to open socket" << errno << endl;
    exit(EXIT_FAILURE);
  }

  cout << "Socket is ready." << endl;

  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(9999);
  server_address.sin_addr.s_addr = INADDR_ANY;

  int connection_status =
      connect(network_socket, (struct sockaddr *)&server_address,
              sizeof(server_address));

  if (connection_status == -1) {
    cout << "Faled to connect" << errno << endl;
    exit(EXIT_FAILURE);
  }
  cout << "Connected to client." << endl;
  
  char response[256];
  recv(network_socket, &response, sizeof(response), 0);
  cout << "Response: " << response << endl;
  
  string request = "Hi, from client.\n";
  send(connection_status, request.c_str(), request.size(), 0);

  
  close(connection_status);
  close(network_socket);

  return 0;
}
