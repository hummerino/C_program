#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPZ_CRIPTA 'c'
#define OPZ_CRIPTA_NUMBER 0
#define OPZ_DECRIPTA 'd'
#define OPZ_DECRIPTA_NUMBER 1
#define OPZ_HELP "help"
#define PROGRAM_NAME "criptosimo"
#define PROGRAM_FILE ".simo"
#define ERRORE_ARGV_VOID "ERRORE: Non sono stati inseriti argomenti."
#define ERRORE_ARGV_OPZ "ERRORE: Non e' stata selezionata nessuna opzione."
#define ERRORE_ARGV_FILENAME "ERRORE: Non e' stato inserito nessun nome di file."
#define ERRORE_ARGV_OPZ_NONVALIDO "ERRORE: opzione non valida."
#define ERRORE_FILE_NULL "ERRORE: Impossibile aprire file. Le cause possono essere:\n\t-Il file non esiste;\n\t-Non ci sono i permessi necessari."
#define ERRORE_FILE_NONVALIDO "ERRORE: Tipo di file non valido. I file utilizzati per la decriptazione sono con estensione '.simo'."
#define MSG_TRY "Prova con 'cryptosimo help' per maggiori informazioni.\n"

//Funzioni
void criptaFile(char* nomefile);
void decriptaFile(char* nomefile);

//Controlli
char* controllaArgomenti(int argn, char ** argv, int *cosaFare);

//Stampe
void stampaUtilizzo();

int main(int argn, char ** argv){
  char* nomefile;
  int cosafare, result;
  nomefile=controllaArgomenti(argn, argv, &cosafare);
  //AproIlFile:
  printf("\t -> Apro il file '%s'...\n", nomefile);
    switch(cosafare){
      case OPZ_CRIPTA_NUMBER: criptaFile(nomefile);
              break;
      case OPZ_DECRIPTA_NUMBER: decriptaFile(nomefile);
              break;
    }
}

//Funzioni
void criptaFile(char* nomefile){
  FILE *fileinput=fopen(nomefile, "r");
  if(fileinput==NULL){  printf("%s: %s\n%s", PROGRAM_NAME, ERRORE_FILE_NULL, MSG_TRY); exit(-1);  }
  else{
    //Creo un valore per k
    int k=1, scan=0, i, c;
    char cc;
    char letto[1000];
    //Creo il file criptato
    strcat(nomefile, PROGRAM_FILE);
    printf("\t -> Nuovo Nome: %s\n", nomefile);
    FILE *criptato=fopen(nomefile, "w");
    do{
      //leggo fa file input
      scan=fgets(letto, 1000, fileinput);
      printf("-> %d\n", letto);

      //modifico quello che ho letto
      for(i=0; i<strlen(letto); i++){
        c=(int)letto[i]+k;
        fprintf(criptato, "%c", c);
      }
      //fprintf(criptato, "\n", c);
      //svuoto il buffer
      strcpy(letto, "");
    }while(scan!=NULL);
    //fclose(fileinput);
    //fclose(criptato);
    fclose(fileinput);
  }
}

void decriptaFile(char* nomefile){
  printf("--> NOMEFILE: %s\n", nomefile);
  if(nomefile[strlen(nomefile)-5]=='.' && nomefile[strlen(nomefile)-4]=='s' && nomefile[strlen(nomefile)-3]=='i' && nomefile[strlen(nomefile)-2]=='m' && nomefile[strlen(nomefile)-1]=='o'){
    printf("%s: %s\n%s", PROGRAM_NAME, ERRORE_FILE_NONVALIDO, MSG_TRY);
  }else{
    char *newName=(char*)malloc(sizeof(char)*(strlen(nomefile)-5));
    strncpy(newName, nomefile, strlen(nomefile)-5);
    FILE *fileinput=fopen(newName, "r");
    if(fileinput==NULL){  printf("%s: %s\n%s", PROGRAM_NAME, ERRORE_FILE_NULL, MSG_TRY); exit(-1);  }
    else{
      //Creo un valore per k
      int k=1, scan=0, i, c;
      char cc;
      char letto[1000];
      //Creo il file criptato
      strncpy(nomefile, nomefile, strlen(nomefile)-strlen(PROGRAM_FILE));
      printf("\t -> Nuovo Nome: %s\n", nomefile);
      FILE *criptato=fopen(nomefile, "w");
      do{
        //leggo fa file input
        scan=fgets(letto, 1000, fileinput);
        printf("-> %d\n", letto);

        //modifico quello che ho letto
        for(i=0; i<strlen(letto); i++){
          c=(int)letto[i]-k;
          fprintf(criptato, "%c", c);
        }
        //fprintf(criptato, "\n", c);
        //svuoto il buffer
        strcpy(letto, "");
      }while(scan!=NULL);
      //fclose(fileinput);
      //fclose(criptato);
      fclose(fileinput);
    }
  }
}

char* controllaArgomenti(int argn, char **argv, int *cosaFare){
  int i;
  char *nomefile=NULL;
  if(argn==1){  printf("%s: %s\n%s", PROGRAM_NAME, ERRORE_ARGV_VOID, MSG_TRY); exit(-1);  }
  else{
    for(i=1; i<argn; i++){
      if(argv[i][0]=='-'){
        switch(argv[i][1]){
          case OPZ_CRIPTA:   *cosaFare=OPZ_CRIPTA_NUMBER;
                             break;
          case OPZ_DECRIPTA: *cosaFare=OPZ_DECRIPTA_NUMBER;
                             break;
          default:           printf("%s: %s\n%s", PROGRAM_NAME, ERRORE_ARGV_OPZ_NONVALIDO, MSG_TRY);
                             exit(-1);
        }
      }else{
        if(strcmp(argv[i], OPZ_HELP)==0){ stampaUtilizzo(); exit(0);}
        else{
          nomefile=(char*)malloc(sizeof(char)*strlen(argv[i]));
          strcpy(nomefile,argv[i]);
        }
      }
    }
    if(*cosaFare==-1){   printf("%s: %s\n%s", PROGRAM_NAME, ERRORE_ARGV_OPZ, MSG_TRY);      exit(-1); }
    if(nomefile==NULL){  printf("%s: %s\n%s", PROGRAM_NAME, ERRORE_ARGV_FILENAME, MSG_TRY); exit(-1); }
    return nomefile;
  }
}

void stampaUtilizzo(){
  system("clear");
  printf("NOME\n\t\t%s - Cripta/Decripta file di tipo '%s' .\n", PROGRAM_NAME, PROGRAM_FILE);
  printf("SINTASSI\n\t\t%s [OPZIONE] [FILE]\n\n", PROGRAM_NAME);
  printf("DESCRIZIONE\n\t\t Il programma prende in input un file e in base all'opzione che viene inserita, il file viene criptato o decriptato secondo lo standard SIMONEGOLIA.\n");
  printf("OPZIONI\n");
  printf("\t\t-%c,\t Cripta file\n\n", OPZ_CRIPTA);
  printf("\t\t-%c,\t Decripta file\n\n", OPZ_DECRIPTA);
  printf("VALORE RESTITUITO\n\t\t0 se il programma viene terminato con successo.\n\t\t1 se il programma viene terminato con errori.\n");
}
