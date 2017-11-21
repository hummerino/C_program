/*
  Author: Golia Simone
  Program: Given a function FOO prints its execution time on the terminal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void FOO();

int main()
{
   clock_t start_t, end_t, total_t;
   int i;

   start_t = clock();

   printf("Start function FOO at: %ld\n", start_t);

   FOO();

   end_t = clock();

   printf("End function FOO at : %ld\n", end_t);

   total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
   printf("Total time taken by CPU: %f\n", total_t  );

   return 0;
}

void FOO(){
  //Same code
}
