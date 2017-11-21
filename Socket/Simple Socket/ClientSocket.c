#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <string.h>

#define PAR_PORT "-port"
#define PAR_IP "-ip"
#define MAX_MSG 1000

enum typeMessage {ERROR, WARNING, MSG, MSG_IP};

struct sockaddr_in controllaDati(int argn, char** argv);
void message(int type, char* msg);

int main(int argn, char** argv){
  int sockfd;
  char buffer[BUFSIZ];
  int len, result, quit=1;
  char msg[MAX_MSG];

  sockfd=socket(AF_INET, SOCK_STREAM, 0);

  struct sockaddr_in address=controllaDati(argn, argv);

  while(quit){
    printf("\t>");
    scanf("%s", msg);
    len=sizeof(address);
    result=connect(sockfd, (struct sockaddr*)&address, len);
    if(result<0){
      perror("Connection Failed");
      exit(1);
    }
    if(strcmp(msg, "#quit")==0) goto end;
    if(send(sockfd, msg, strlen(msg), 0)<0 ){
        perror("Send Failed");
        goto end;
    }
    close(sockfd);
  }
  end:
  exit(0);
}

  /*
    controllaDati()
    1 -> verifica avvenuta con successo
    0 -> verifica avvenuta con insuccesso
  */
  struct sockaddr_in controllaDati(int argn, char** argv){
    struct sockaddr_in address;
    int port=-1, i;
    char ip[15]="";
    if(argn<2) goto def;
    for(i=0; i<argn; i++){
      if(strcmp(PAR_IP, argv[i])==0 && i<argn){
        strcpy(ip, argv[++i]);
      }else if(strcmp(PAR_PORT, argv[i])==0 && i<argn){
        port=atoi(argv[++i]);
      }
    }

    int flag=0;
    if(strcmp("", ip)==0){
      message(ERROR, "Non e' stato inserito alcun IP.");
      flag=1;
    }else if(strlen(ip)>15){
        message(ERROR, "Indirizzo IP non valido.");
        flag=1;
    }else{
      int p, c;
      for(p; p<strlen(ip); p++) if(ip[p]=='.') c++;
      if(c!=3){
        message(ERROR, "Indirizzo IP non valido.");
        flag=1;
      }
    }
    def:
    if(flag){
        strcpy(ip, "127.0.0.1");
        message(MSG, "IP utilizzato: 127.0.0.1");
    }else{
      printf("$ IP utilizzato: %s\n", ip);
    }
    if(port==-1){
      message(WARNING, "Non e' stata inserita alcuna porta.");
      message(MSG, "Porta utilizzata: 9999");
      port=9999;
    }else{
      printf("$ Porta utilizzata: %d\n", port);
    }
    //Indirizzo da utilizzare
    address.sin_family=AF_INET;
    address.sin_addr.s_addr = inet_addr(ip);
    address.sin_port=port;
    return address;
  }


  void message(int type, char* msg){
    switch(type){
      case ERROR:   printf("\t@@@ ERROR : %s\n", msg);
                  break;
      case WARNING: printf("\t# WARNING : %s\n", msg);
                  break;
      case MSG:     printf("$ %s\n", msg);
                  break;

   }
  }

