#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hw3.h"

int all_even(int a[], unsigned int alen){
  unsigned int i;
  for (i=0;i<alen;i++){
    if (a[i] % 2 != 0){
      return 0;
    }
  }
  return 1;
}
int exists_even(int a[], unsigned int alen){
  unsigned int i;
  for (i=0;i<alen;i++){
    if (a[i] % 2 == 0){
      return 1;
    }
  }
  return 0;
}
int first_even(int a[], unsigned int alen){
  unsigned int i;
  for (i=0;i<alen;i++){
    if (a[i] % 2 == 0){
      return i;
    }
  }
  return -1;
}
unsigned int number_evens(int a[], unsigned int alen){
  unsigned int i, count = 0;
  for (i=0;i<alen;i++){
    if (a[i] % 2 == 0){
      count ++;
    }
  }
  return count;
}
void make_evens(int a[], unsigned int alen){
  unsigned int i;
  for (i=0;i<alen;i++){
    if ((a[i] % 2 != 0) && (a[i] > 0)){
      a[i] --;
    }else if ((a[i] % 2 != 0) && (a[i] < 0)){
      a[i] ++;
    }
  }
}
unsigned int* running_evens(int a[], unsigned int alen){
  unsigned int* res = (unsigned int*)malloc(sizeof(unsigned int) * alen);
  if (res == NULL){
    fprintf(stderr,"unable to allocate result");
    exit(1);
  }
  unsigned int i, count = 0;
  for (i=0;i<alen;i++){
    if (a[i] % 2 == 0){
      count ++;
    }
    res[i] = count;
  }
  return res;
}
void rotate_left(int a[], int alen){
  int temp = a[0];
  unsigned int i;
  for (i=0;i<(alen - 1);i++){
    a[i] = a[i+1];
  }
  a[i] = temp;
}
int* stitch(int* a, unsigned int alen, int* b, unsigned int blen){
  unsigned int i = 0, ind = 0;
  int* res = (int*)malloc(sizeof(int) * (alen + blen));
  if (res == NULL){
    fprintf(stderr,"unable to allocate result \n");
    exit(1);
  }
  while (i < (alen + blen)){
    if ((ind < alen) && (ind < blen)){
      res[i] = a[ind];
      i ++;
      res[i] = b[ind];
    }else if (ind < alen){
      res[i] = a[ind];
    }else if (ind < blen){
      res[i] = b[ind];
    }
    i++;
    ind++;
  }
  return res;
}

/* taken from lab4, computers the nth Fibonacci
 * number and returns it (given an n representing
 * the fibonacci number we're finding */
unsigned int fib(unsigned int n){
  if (n == 0){
    return 0;
  }else if (n == 1){
    return 1;
  }else{
    return fib(n-2) + fib(n-1);
  } 
}
unsigned int* fib_upto(unsigned int bound, unsigned int* len){
  unsigned int n = 1, length = 0;
  while (fib(n) <= bound){
    length++;
    n++;
  }
  *len = length;
  unsigned int* res = (unsigned int*)malloc(sizeof(unsigned int) * length);
  if (res == NULL){
    fprintf(stderr,"unable to allocate res\n");
    exit(1);
  }
  unsigned int i, fn = 1;
  for (i=0;i<length;i++){
    res[i] = fib(fn);
    fn++;
  }
  return res;
}

void uppercase(char* in, char* out){
  unsigned int i = 0;
  while (in[i]){
    if (in[i] > 96 && in[i] < 123){
      out[i] = (in[i] - 32);
      i++;
    }else{
      out[i] = in[i];
      i++;
    }
  }
  out[i] = '\0';
}
