/*
  Author: Golia Simone
  Program: Implements Heap-Max Data Structure
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct _heap{
  int* array;
  int length;
  int size;
}Heap;

#define SCAMBIA(type, a, b) {type tmp = a; a=b; b=tmp;}

Heap* scanHeap();
void printHeap(Heap* heap);
int parent(int i);
int sx(int i);
int dx(int i);

//Operazioni su heap
void build_Max_Heap(Heap* heap);
void max_Heapfy(Heap* heap, int i);
void insert_Max_Heapfy(Heap* heap, int key);

int main(){
  //Create an Heap
  Heap* heap = scanHeap();

  //Print Heap
  printHeap(heap);
  return 0;
}

Heap* scanHeap(){
  int dimHeap, tmp;
  Heap* heap = (Heap*)malloc(sizeof(struct _heap));
  scanf("%d", &dimHeap);

  //Inizzializzo l'heap
  heap->array=(int*)malloc(sizeof(int)*dimHeap);
  heap->length = dimHeap;
  heap->size = 0;
  while(heap->size<heap->length){
    scanf("%d", &tmp);
    if(tmp<0) break;
    insert_Max_Heapfy(heap, tmp);
  }
  return heap;
}

void printHeap(Heap* heap){
  int i=0;
  for(int i=0; i<heap->size; i++)
    printf("%d\n", heap->array[i]);
}

int parent(int i){ return   i/2; }
int left(int i)  { return   i*2; }
int right(int i) { return i*2+1; }

void build_Max_Heap(Heap* heap){
  int i = heap->length/2;
  for(i; i>=0; i++){
    max_Heapfy(heap, i);
  }
}
void max_Heapfy(Heap* heap, int i){
    int l = left(i);
    int r = right(i);
    int max;
    max = (l<=heap->size && heap->array[l] > heap->array[i]) ? l : i ;
    max = (r<=heap->size && heap->array[l] > heap->array[i]) ? r : i ;
    if(max!=i){
      SCAMBIA(int, heap->array[i], heap->array[max]);
      max_Heapfy(heap, max);
    }
}

void insert_Max_Heapfy(Heap* heap, int key){
  heap->size=heap->size+1;   //Incremento il numero di elementi presenti nell'heap
  int i=heap->size-1;
  heap->array[i]=key;        //Viene inserito l'elemento nell'ultima posizione dell'heap
  while( i>0 && heap->array[parent(i)]<heap->array[i]){     //Scorro l'heap Bottom-Up fino a che h[parent(i)] < h[i]
    SCAMBIA(int, heap->array[i], heap->array[parent(i)]);
    i=parent(i);
  }
}
