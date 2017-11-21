/*
  Author: Golia Simone
  Program: An example of sorting array using Selectionsort Algorithm
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

  //Sorting with Algorithm : SelectionSort
  int i, j;
  int min;

  for(i=0; i<dimArray; i++){
    min=j=i;
    //The smaller int ar searched in the rest of array
    for(j; j<dimArray; j++){
      if(array[min] > array[j]) min=j;
    }
    //If the smaller int it found Swap with i
    if(min!=i)
      SCAMBIA(int, array[min], array[i]);
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
