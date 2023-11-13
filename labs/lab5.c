#include <stdio.h>
#include <stdlib.h>
#include "lab5.h"

// in this file, write implementations of the functions whose headers appear in lab5.h

// important: don't write a main function
// this is a module meant to be imported

unsigned int len(char* string){
  unsigned int i = 0, count = 0;
  while (string[i]){
    count++;
    i++;
  }
  return count;
}

char* repeat_char(char c, unsigned int n){
  char* res = (char*)malloc(sizeof(char) * n);
  if (res == NULL){
    fprintf(stderr,"repeat_char: cannot allocate space\n");
    exit(1);
  }
  unsigned int i;
  for (i = 0;i < n;i++){
    res[i] = c;
  }
  res[i] = '\0';
  return res;
}

unsigned int count_char(char c, char* string){
  unsigned int i = 0, res = 0;
  while (string[i]){
    if (string[i] == c){
      res++;
    }
    i++;
  }
  return res;
}

unsigned int* locations_of(char c, char* string, unsigned int* n){
  *n = count_char(c,string);
  unsigned int* res = (unsigned int*)malloc(sizeof(unsigned int) * (*n));
  if (res == NULL){
    fprintf(stderr,"locations_of: cannot allocate space\n");
    exit(1);
  }
  unsigned int i, ri = 0;
  for (i = 0; i < (*n); i++){
    if (string[i] == c){
      res[ri] = i;
      ri++;
    }
  }
  return res;
}
