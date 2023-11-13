#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <criterion/criterion.h>
#include "hw4.h"

/* Q1 Tests */
Test(double_to_str, zerozero){
  char* res = double_to_str(0,0);
  cr_assert(!strcmp(res,"0"));
  free(res);
}
Test(double_to_str, twodec){
  char* res = double_to_str(138,2);
  cr_assert(!strcmp(res,"138.00"));
  free(res);
}
Test(double_to_str, point1){
  char* res = double_to_str(0.1,1);
  cr_assert(!strcmp(res,"0.1"));
  free(res);
}
Test(double_to_str, pi_zero){
  char* res = double_to_str(3.14,0);
  cr_assert(!strcmp(res,"3"));
  free(res);
}
Test(double_to_str, pi_six){
  char* res = double_to_str(3.14159265,6);
  cr_assert(!strcmp(res,"3.141592"));
  free(res);
}
Test(double_to_str, toobig){
  char* res = double_to_str(2e19, 2);
  cr_assert(!strcmp(res, "too big"));
  free(res);
}
Test(double_to_str, negative){
  char* res = double_to_str(-2,0);
  cr_assert(!strcmp(res, "negative"));
  free(res);
}

/* Q2 Tests */
Test(locations_of, one_match){
  unsigned int n = 0;
  unsigned int expected[] = {0, 3};
  unsigned int* actual = locations_of("a", "abca", &n);
  int i, result = 1;
  for (i = 0; i < 0; i++){
    if (expected[i] != actual [i]){
      result = 0;
    }
  }
  if (n != 2){
    result = 0;
  }
  cr_assert(result);
}
Test(locations_of, three_match){
  unsigned int n = 0;
  unsigned int expected[] = {1, 2, 3};
  unsigned int* actual = locations_of("aa", "zaaaa", &n);
  int i, result = 1;
  for (i = 0; i < 0; i++){
    if (expected[i] != actual [i]){
      result = 0;
    }
  }
  if (n != 3){
    result = 0;
  }
  cr_assert(result);
}
Test(locations_of, empty_substr){
  unsigned int n = 0;
  unsigned int expected[] = {};
  unsigned int* actual = locations_of(" ", "skdjbf", &n);
  int i, result = 1;
  for (i = 0; i < 0; i++){
    if (expected[i] != actual [i]){
      result = 0;
    }
  }
  if (n != 0){
    result = 0;
  }
  cr_assert(result);
}
Test(locations_of, no_matches){
  unsigned int n = 0;
  unsigned int expected[] = {};
  unsigned int* actual = locations_of("b", "skdjif", &n);
  int i, result = 1;
  for (i = 0; i < 0; i++){
    if (expected[i] != actual [i]){
      result = 0;
    }
  }
  if (n != 0){
    result = 0;
  }
  cr_assert(result);
}

