#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>

#define _PORT 9999
#define _LOCALHOST "127.0.0.1"

int main(){
  char ch;
  char buffer[BUFSIZ];

  int server_sockfd, client_sockfd;
  int server_len, client_len;

  struct sockaddr_in server_address;
  struct sockaddr_in client_address;

  server_sockfd=socket(AF_INET, SOCK_STREAM, 0);

  server_address.sin_family=AF_INET;
  server_address.sin_addr.s_addr=inet_addr(_LOCALHOST);
  server_address.sin_port=_PORT;

  server_len=sizeof(server_address);
  client_len=sizeof(client_address);

  bind(server_sockfd, (struct sockaddr*)&server_address, server_len);
  listen(server_sockfd, 5);

  while(1){
    printf("Wait...");
    client_len=sizeof(client_address);
    client_sockfd=accept(server_sockfd, (struct sockaddr*)&client_address, &client_len);
    recv(client_sockfd, buffer, BUFSIZ, 0);
    printf("%s\n", buffer);
    close(client_sockfd);
  }
}
