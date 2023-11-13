#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>
#include "hw4.h"

/* given an integer, return its length */
unsigned int int_length(unsigned long long int n){
  unsigned int length = 0;
  if (n == 0){
    return 1;
  }
  while (n > 0){
    n = n / 10;
    length++;
  }
  return length;
}

char* double_to_str(double d, unsigned char after_decimal){
  if (d < 0){
    return strdup("negative");
  }
  if (d > ULLONG_MAX){
    return strdup("too big");
  }
  unsigned long long int int_portion = d;
  double decimal_part = d - int_portion;
  unsigned int int_l = int_length(int_portion);
  unsigned int total_length = int_l;
  if (after_decimal > 0){
    total_length += after_decimal + 1;
  }
  char* res = (char*)malloc(sizeof(char) * (total_length + 1));
  if (res == NULL){
    fprintf(stderr,"double_to_str: unable to allocate space\n");
    exit(1);
  }
  int index = int_l - 1;
  if (int_portion == 0){
    res[0] = '0';
  }
  while (int_portion > 0){
    res[index--] = (int_portion % 10) + '0';
    int_portion = int_portion / 10;
  }
  index = int_l;
  unsigned int i;
  if (after_decimal > 0){
    res[index++] = '.';
    for (i = 0; i < after_decimal; i++){
      decimal_part = decimal_part * 10;
      res[index++] = ((int) decimal_part % 10) + '0';
      decimal_part -= ((int) decimal_part);
    }
  }
  res[index] = '\0';
  return res;
}

unsigned int* locations_of(char* substr, char* string, unsigned int* n){
  unsigned int sub_len = 0, str_len = 0;
  unsigned int match_count = 0;
  while (substr[sub_len] != '\0'){
    sub_len++;
  }
  while (string[str_len] != '\0'){
    str_len++;
  }
  unsigned int i, j;
  for (i = 0; i <= str_len - sub_len; i++){
    for (j = 0; j < sub_len; j++){
      if (string[i + j] != substr[j]){
        break;
      }
    }
    if (j == sub_len){
      match_count++;
    }
  }
  *n = match_count;
  unsigned int* matches = (unsigned int*)malloc(sizeof(unsigned int) * (*n));
  if (!matches){
    fprintf(stderr, "locations_of: failed to allocate memory\n");
    exit(1);
  }
  unsigned int x, y, index = 0;
  for (x = 0; x <= str_len - sub_len; x++){
    for (y = 0; y < sub_len; y++){
      if (string[x + y] != substr[y]){
        break;
      }
    }
    if (y == sub_len){
      matches[index++] = x;
    }
  }
  return matches;
}

