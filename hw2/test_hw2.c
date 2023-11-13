#include <math.h>
#include <criterion/criterion.h>
#include "hw2.h"

/* function that was written in lab to approximate */
int is_almost(double x, double y, double epsilon){
  if (fabs(x - y) < fabs(epsilon)){
    return 1;
  }else{
    return 0;
  }
}

Test(num_ways_coins,25cents){
  cr_assert(num_ways_coins(25)==13);
}
Test(num_ways_coins,5cents){
  cr_assert(num_ways_coins(5)==2);
}
Test(num_ways_coins,10cents){
  cr_assert(num_ways_coins(10)==4);
}
Test(num_ways_coins,21cents){
  cr_assert(num_ways_coins(21)==9);
}
Test(days_later,leap365){
  unsigned char month = 1;
  unsigned char day = 1;
  unsigned short year = 2024;
  days_later(&month, &day, &year, 365);
  cr_assert(month == 12);
  cr_assert(day == 31);
  cr_assert(year == 2024);
}
Test(days_later,31month){
  unsigned char month = 10;
  unsigned char day = 1;
  unsigned short year = 2023;
  days_later(&month, &day, &year, 31);
  cr_assert(month == 11);
  cr_assert(day == 1);
  cr_assert(year == 2023);
}
Test(days_later,55days){
  unsigned char month = 10;
  unsigned char day = 11;
  unsigned short year = 2020;
  days_later(&month, &day, &year, 55);
  cr_assert(month == 12);
  cr_assert(day == 5);
  cr_assert(year == 2020);
}
Test(nth_prime, second){
  cr_assert(nth_prime(2)==3);
}
Test(nth_prime, fifth){
  cr_assert(nth_prime(5)==11);
}
Test(nth_prime, tenth){
  cr_assert(nth_prime(10)==29);
}
Test(ln_approx, log2){
  cr_assert(is_almost(ln_approx(2.0,100000), log(2.0), 0.01));
}
Test(ln_approx, twoslices){
  cr_assert(is_almost(ln_approx(2.0, 2),5.0/6,0.01));
}

