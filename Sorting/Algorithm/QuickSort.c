/*
  Author: Golia Simone
  Program: An example of sorting array using Quicksort Algorithm
*/
#include <stdio.h>
#include <stdlib.h>

#define SWAP(type, a, b) {type tmp = a; a=b; b=tmp;}

int* scanArray(int* dim);
void printArray(int* array, int dim);
void quickSort(int* array, int start, int end);
int partition(int* array, int start, int end);

int main(){
  //Read an array of int
  int dimArray;
  int* array = scanArray(&dimArray);

  //Sorting the array
  quickSort(array, 0, dimArray-1);

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

/*
  Master Function of Quicksort Algorithm.
  Select a pivot and divide array in two parts recursively.
*/
void quickSort(int* array, int start, int end){
  if(end>start){
    int pivot = partition(array, start, end);
    quickSort(array, start, pivot-1);
    quickSort(array, pivot+1, end);
  }
}

/*
  Subfuction of Quicksort Algorithm
  Select a pivo, ad moves the smaller element of pivot to the
  left and the larger to the right
  Example:
  1 9 7 4 6 3 2 (5) ==> pivot:5 ==> 1 4 3 2 (5) 9 7 6
*/
int partition(int* array, int start, int end){
    int i=start-1, j=start, pivot = end;
    for( j; j<end; j++ ){
      if( array[pivot]<array[j] ){
        i++;
        SWAP(int, array[j], array[i]);
      }
    }
    SWAP(int, array[pivot], array[i+1]);
    return i+1;
}
