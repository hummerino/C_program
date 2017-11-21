/*
  Author: Golia Simone
  Program: An example of sorting array using InsertionSort Algorithm
*/
#include <stdio.h>
#include <stdlib.h>

#define SCAMBIA(type, a, b) {type tmp = a; a=b; b=tmp;}

int* scanArray(int* dim);
void printArray(int* array, int dim);

int main(){
  //Read an array
  int dimArray;
  int* array = scanArray(&dimArray);

  //Sorting with Algorithm : InsertionSort
  int i, j;

  for(i=1; i<numeroElementi; i++){
    j=i;
    //Scroll the array until it find a bigger element of j
    while(array[j]<array[j-1] && j>0){
      SCAMBIA(int, array[j], array[j-1]);
      --j;
    }
  }

  //Print Array
  printArray(array, dimArray);
  return 0;
}

/*
  Read from terminal, dimension of array and all elements of array.
*/
int* scanArray(int* dim){
  int i;
  //Leggo il numero di elementi
  scanf("%d", dim);
  //Creo l'array di dimensione dim e lo popolo
  int* array = (int*) malloc(sizeof(int)*(*dim));
  for(i=0; i<(*dim); i++){
    scanf("%d", &array[i]);
  }
  return array;
}

/*
  Print to terminal, all element of array, one for line.
*/
void printArray(int* array, int dim){
  int i=0;
  for(int i=0; i<dim; i++)
    printf("%d\n", array[i]);
}
