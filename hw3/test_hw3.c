#include <math.h>
#include <string.h>
#include <criterion/criterion.h>
#include "hw3.h"

/* Q1 Tests */
Test(all_even, evens){
  int a[] = {2,4,6,8,10};
  cr_assert(all_even(a,5));
}
Test(all_even, odds){
  int a[] = {1,3};
  cr_assert(!all_even(a,2));
}
Test(all_even, eventoodd){
  int a[] = {2,4,6,0,13};
  cr_assert(!all_even(a,5));
}
Test(all_even, oddtoeven){
  int a[] = {1,3,5,7};
  cr_assert(!all_even(a,4));
}

/* Q2 Tests */
Test(exists_even, noeven){
  int a[] = {-1,-3,-5,3,7};
  cr_assert(!exists_even(a,5));
}
Test(exists_even, middleeeven){
  int a[] = {7,13,6,21,29};
  cr_assert(exists_even(a,5));
}
Test(exists_even, alleven){
  int a[] = {0,-2,-4,6};
  cr_assert(exists_even(a,4));
}

/* Q3 Tests */
Test(first_even, secondpos){
  int a[] = {-1,6,3,7,8};
  cr_assert(first_even(a,5) == 1);
}
Test(first_even, noeven){
  int a[] = {3,7,-11,9};
  cr_assert(first_even(a,4) == -1);
}
Test(first_even, last_pos){
  int a[] = {3,17,-1,1,9,-81,2};
  cr_assert(first_even(a,7) == 6);
}
Test(first_even, firstpos){
  int a[] = {2,7,8,12};
  cr_assert(first_even(a,4) == 0);
}

/* Q4 Tests */
Test(number_evens, two){
  int a[] = {1,7,4,3,6,5};
  cr_assert(number_evens(a,6) == 2);
}
Test(number_evens, none){
  int a[] = {-7,-13,13,7,19};
  cr_assert(number_evens(a,5) == 0);
}
Test(number_evens, all){
  int a[] = {2,6,16,14,4,90};
  cr_assert(number_evens(a,6) == 6);
}

/* Q5 Tests */
Test(make_evens, addone){
  int a[] = {3,4,7,8};
  int res[] = {2,4,6,8};
  make_evens(a, 4);
  int i, result = 1;
  for (i=0;i<4;i++){
    if (a[i] != res[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
Test(make_evens, negative){
  int a[] = {-11,-15,-19};
  int res[] = {-10,-14,-18};
  make_evens(a,3);
  int i, result = 1;
  for (i=0;i<3;i++){
    if (a[i] != res[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
Test(make_evens, somepossomeneg){
  int a[] = {3,-5,7,-19};
  int res [] = {2, -4, 6, 18};
  make_evens(a,4);
  int i, result = 1;
  for (i=0;i<3;i++){
    if (a[i] != res[i]){
      result = 0;
    }
  }
  cr_assert(result);
}

/* Q6 Tests */
Test(running_evens, total2){
  int a[] = {1,2,5,8,13};
  unsigned int expected[] = {0,1,1,2,2};
  unsigned int* actual = running_evens(a, 5);
  int i, result = 1;
  for (i=0;i<5;i++){
    if (expected[i] != actual[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
Test(running_evens, total0){
  int a[] = {-5,-7,13,41,87};
  unsigned int expected[] = {0,0,0,0,0};
  unsigned int* actual = running_evens(a, 5);
  int i, result =1;
  for (i=0;i<5;i++){
    if (expected[i] != actual[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
/* Q7 Tests */
Test(rotate_left, len7){
  int a[] = {2,7,6,18,7,12,5};
  int expected[] = {7,6,18,7,12,5,2};
  rotate_left(a,7);
  int i, result = 1;
  for (i=0;i<7;i++){
    if (expected[i] != a[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
Test(rotate_left, len2){
  int a[] = {4,3};
  int expected[] = {3,4};
  rotate_left(a,2);
  int i, result = 1;
  for (i=0;i<2;i++){
    if (expected[i] != a[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
/* Q8 Tests */
Test(stitch, samelen){
  int a[] = {3,7,8};
  int b[] = {2,2,2};
  int expected[] = {3,2,7,2,8,2};
  int* actual = stitch(a,3,b,3);
  int i, result = 1;
  for (i=0;i<6;i++){
    if (expected[i] != actual[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
Test(stitch, difflen){
  int a[] = {3,2,8,12,56};
  int b[] = {3,-1};
  int expected[] = {3,3,2,-1,8,12,56};
  int* actual = stitch(a,5,b,2);
  int i, result = 1;
  for (i=0;i<7;i++){
    if (expected[i] != actual[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
Test(stitch, oneempt){
  int a[] = {};
  int b[] = {3,8,12,15};
  int expected[] = {3,8,12,15};
  int* actual = stitch(a,0,b,4);
  int i, result = 1;
  for (i=0;i<4;i++){
    if (expected[i] != actual[i]){
      result = 0;
    }
  }
  cr_assert(result);
}
/* Q9 Tests*/
Test(fib_upto, 55){
  unsigned int length = 0, bound = 66;
  unsigned int expected[] = {1,1,2,3,5,8,13,21,34,55};
  unsigned int* actual = fib_upto(bound,&length);
  int i, result = 1;
  for (i=0;i<10;i++){
    if (expected[i] != actual[i]){
      result = 0;
    }
  }
  if (length != 10){
    result = 0;
  }
  cr_assert(result);
}
Test(fib_upto, 21){
  unsigned int length = 0, bound = 24;
  unsigned int expected[] = {1,1,2,3,5,8,13,21};
  unsigned int* actual = fib_upto(bound,&length);
  int i, result = 1;
  for (i=0;i<8;i++){
    if (expected[i] != actual[i]){
      result = 0;
    }
  }
  if (length != 8){
    result = 0;
  }
  cr_assert(result);
}
Test(fib_upto, 0){
  unsigned int length = 0, bound = 0;
  unsigned int expected[] = {};
  unsigned int* actual = fib_upto(bound,&length);
  int i, result = 1;
  for (i=0;i<0;i++){
    if (expected[i] != actual[i]){
      result = 0;
    }
  }
  if (length != 0){
    result = 0;
  }
  cr_assert(result);
}
  
/* Q10 Tests */
Test(uppercase, 2let){
  char* in = "hELLO,wORLD";
  char* out = (char*)malloc(sizeof(char) * (strlen(in)+1));
  if (out == NULL){
    fprintf(stderr,"unable to allocate out \n");
    exit(1);
  }
  uppercase(in,out);
  char* expected = "HELLO,WORLD";
  cr_assert(!strcmp(out, expected));
  free(out);
}
Test(uppercase, alllower){
  char* in = "oh no";
  char* out = (char*)malloc(sizeof(char) * (strlen(in)+1));
  if (out == NULL){
    fprintf(stderr,"unable to allocate out \n");
    exit(1);
  }
  uppercase(in, out);
  char* expected = "OH NO";
  cr_assert(!strcmp(out, expected));
  free(out);
}
Test(uppercase, somelower){
  char* in = "i'M goNNa crY";
  char* out = (char*)malloc(sizeof(char) * (strlen(in)+1));
  if (out == NULL){
    fprintf(stderr,"unable to allocate out \n");
    exit(1);
  }
  uppercase(in,out);
  char* expected = "I'M GONNA CRY";
  cr_assert(!strcmp(out, expected));
  free(out);
}
