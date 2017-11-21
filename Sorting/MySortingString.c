/*
	Autore: Golia Simone
  Programma:
  Il programma prende in input una lista di stringhe (fino all'inserimento del carattere '#').
  Ordina la lista di elementi e chiede se si vuole creare un file, con nome scelto dall'utente
  dove vengono inseriti uno per riga gli elementi ordinati inseriti.
  L'ordinamento viene effettuato tramite algoritmo QuickSort in modo decrescente.

  Se si vuole creare un file da dare come input al programma tramite riga di comando
  il file dovra essere costruito in questo modo:

  [1-esima stringa]
  ...
  [n-esima stringa]
  #
  ['s' o 'n' se si vuole creare il file]
  [nomefile] (se si e' scelto 's')
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTR 1000
#define FINELISTA "#"
#define SWAP(a,b,tmp){strcpy(tmp, a);strcpy(a, b);strcpy(b, tmp);}

int partition(char** s, int sx, int dx){
    if(sx<dx){
      int i=sx-1, j=sx;
      char *tmp=(char*)malloc(sizeof(char*)*MAXSTR);
      for(j; j<dx; j++){
        if(strcmp(s[j], s[dx])<=0){
          i++;
          SWAP(s[j], s[i], tmp);
        }
      }
      SWAP(s[i+1], s[dx], tmp);
      return i+1;
    }
}

void qs(char** s, int sx, int dx){
    if(sx<dx){
      int cx=partition(s, sx, dx);
      qs(s, sx, cx-1);
      qs(s, cx+1, sx);
    }
}

void creafile(char** s, int dim, char* nomefile){
    FILE *file=fopen(nomefile, "w");
    if(file==NULL){ printf("[ERRORE] Impossibile creare file."); exit(-1);}
    else{
      int i;
      for(i=0; i<dim; i++){
        fprintf(file, "%s\n", s[i]);
      }
      fclose(file);
    }
}

int main(){
  int dim=0, i;
  char** string=(char**)malloc(sizeof(char*));
  char* input=(char*)malloc(sizeof(char)*MAXSTR);
  char* riposta=(char*)malloc(sizeof(char)*2);
  scanf("%s", input);
  while(strcmp(input,FINELISTA)!=0){
    ++dim;
    string=(char**)realloc(string, sizeof(char*)*dim);
    string[dim-1]=(char*)malloc(sizeof(char)*strlen(input));
    strcpy(string[dim-1], input);
    scanf("%s", input);
  }
  printf("[OK] Lettura dati.\n");
  qs(string, 0, dim-1);
  printf("[OK] Elementi Ordinati Correttamente\nStampo gli elementi:\n");
  for(i=0; i<dim; i++)  printf("%s\n", string[i]);
  int risp, x=0;
  do{
    x++;
    printf("Vuoi creare un file? (s/n): ");
    scanf("%s", riposta);
    if(strcmp(riposta, "s")==0 || strcmp(riposta, "si")==0){
        char *nomefile=(char*)malloc(sizeof(char)*MAXSTR);
        printf("Nome File: ");
        scanf("%s", nomefile);
        creafile(string, dim, nomefile);
        printf("[OK] File creato.\n");
        return 0;
    }else if(strcmp(input, "n")==0 || strcmp(input, "no")==0){
        return 0;
    }
  }while(x<=5);
}
