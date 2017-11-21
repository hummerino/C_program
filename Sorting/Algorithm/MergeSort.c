/*
  Author: Golia Simone
  Program: An example of sorting array using MergeSort Algorithm
*/
#include <stdio.h>
#include <stdlib.h>

#define SCAMBIA(type, a, b) {type tmp = a; a=b; b=tmp;}

int* scanArray(int* dim);
void printArray(int* array, int dim);
void mergeSort(int* array, int start, int end);
void merge((int* array, int start, int center ,int end);

int main(){
  //Read an array of int
  int dimArray;
  int* array = scanArray(&dimArray);

  mergeSort(array, 0, dimArray-1);

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
  Master Function of Mergesort Algorithm.
  Divide the array and merge all the part in one ordered array
*/
void mergeSort(int* array, int start, int end){
  if(end>start){
    int center = (start+end)/2;
    mergeSort(array, start, center);
    mergeSort(array, center+1, end);
    merge(array, start, center, end);
  }
}

/*
  Subfunction of Mergesort Algorithm.
  Merge two part of array in one ordered array.
*/
void merge(int* array, int start, int center, int end);{
  int dimension = (end-star)+1;
  int* orderedArray = (int*) malloc(sizeof(int)*dimension);
  int i=start, j=center+1, position=0;

  while( i<=center && j<=end && position<dimension){
    if(array[i]<array[j])
      orderedArray[position]=array[i++];
    else
      orderedArray[position]=array[j++];
    ++pos;
  }

  while( i<=center && position<dimension){
    orderedArray[position]=array[i++];
    position++;
  }

  while( j<=end && position<dimension){
    orderedArray[position]=array[i++];
    position++;
  }

  j=0;
  for(i=start; i<=end; i++){
    array[i] = orderedArray[j++];
  }

}
