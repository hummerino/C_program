/*
  Author: Golia Simone
  Program: Implements Heap-Min Data Structure
*/

#include <stdio.h>
#include <stdlib.h>

#define SWAP(type, a, b) { type tmp=a; a=b; b=tmp; }

typedef struct _heap{
  int* a;
  int length;
  int size;
}Heap;

void inserisciInHeapDiMin(Heap* heap, int tmp);
int parent(int i){ return i/2; };
int left(int i){ return i*2; };
int right(int i){ return i*2+1; };

int main(){
  int n, i, tmp;
  Heap* heap = (Heap*)malloc(sizeof(struct _heap));
  heap->size=0;
  scanf("%d", &heap->length);
  heap->a=(int*)malloc(sizeof(int)*heap->length);

  while(heap->size<heap->length){
    scanf("%d", &tmp);
    if(tmp<0) break;
    inserisciInHeapDiMin(heap, tmp);
    printf("\nsize%d\n", heap->size);
  }

  printf("\n\n\n");
  for(int i=0; i<heap->size; i++){
    printf("%d\n", heap->a[i]);
  }
}

void inserisciInHeapDiMin(Heap* heap, int tmp){
  if(heap->size>=heap->length) return;
  int pos=heap->size;
  heap->a[pos]=tmp;

  //ora faccio scorrere
  while(heap->a[parent(pos)]>heap->a[pos] && parent(pos)>=0){
    SWAP(int, heap->a[parent(pos)], heap->a[pos]);
    pos=parent(pos);
  }
  heap->size=heap->size+1;
}
