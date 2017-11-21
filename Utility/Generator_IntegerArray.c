/*
  Author: Golia Simone
  Program:
    Parameters : <Number Of Integers To Be Printed> <Maximum Integer Number>
    Example
      ./Generator_IntegerArray 10 20
      Output:
        1
        14
        2
        16
        13
        5
        19
        6
        11
        9
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argn, char** argv){
  if(argn != 3){
    printf("Invalid parameters!Try:\n%s <Number Of Integers To Be Printed> <Maximum Integer Number>\n", argv[0]);
    return 1;
  }

  int n   = atoi(argv[1]);
  int max = atoi(argv[2]);
  int i;

  printf("%d\n", n);
  for(i=0; i<n; i++)
    printf("%d\n", rand()%max);

  return 0;
}
