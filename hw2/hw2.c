#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "hw2.h"

unsigned int num_ways_coins(unsigned short cents){
  unsigned int quarters, dimes, nickels, res=0;  
  for (quarters = 0; quarters <= cents / 25; quarters++){
    for (dimes = 0; dimes <= cents / 10; dimes++){
      for (nickels = 0; nickels <= cents / 5; nickels++){
        int remaining = cents - (quarters * 25 + dimes * 10 + nickels * 5);
        if (remaining >= 0){
          res++;
        }
      }
    }
  }
  return res;
}

int is_leap_year(unsigned short y){
  /* function from class that returns wheether or not year is a leap year */
  if (y % 400 == 0){
    return 1;
  }else if (y % 100 == 0){
    return 0;
  }else if (y % 4 == 0){
    return 1;
  }else{
    return 0;
  }
}

unsigned char days_in_month(unsigned char m, unsigned short y){
  /* function from class that retuns how many days are in a given month */
  switch (m){
    case 9:
    case 4:
    case 6:
    case 11:
      return 30;
    case 2:
      if (is_leap_year(y)){
        return 29;
      }else{
        return 28;
      }
    default:
      return 31;
  }
}

void days_later(unsigned char* month, unsigned char* day, unsigned short* year, unsigned short days){
  while (days > 0){
    int current_month_days = days_in_month(*month, *year);
    if (*day + days > current_month_days){
      days -= (current_month_days - *day +1);
      *day = 1;
      if (*month == 12){
        *month = 1;
        *year += 1;
      }else{
        *month += 1;
      }
    }else{
      *day += days;
      days = 0;
    }
  }
}

/* looked up how to determine if a number is prime: 
 * trial division between 2 and sqrtn */
int is_prime(int n){
  if (n <= 1){
    return 0;
  }int i;
  for (i = 2; i < n; i++){
    if (n % i == 0){
      return 0;
    }
  }
  return 1;
}

unsigned int nth_prime(unsigned short n){
  int count = 0, num = 2;
  while (count < n){
    if (is_prime(num)){
      count ++;
    }if (count != n){
      num ++;
    }
  }
  return num;
}

double ln_approx(double x, unsigned int slices){
  if (x < 1){
    return 0.0;
  }double range = (x - 1.0), width = range / slices, sum = 0.0;
  int i;
  for (i = 0; i < slices; i ++){
    double left = 1.0 + i * width;
    double height = 1.0 / left;
    double area = height * width;
    sum += area;
  }
  return sum;
}


