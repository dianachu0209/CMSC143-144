#include <criterion/criterion.h>
#include "hw1.h"

Test(num_coins, cents97){
  cr_assert(num_coins(97)==7);
}
Test(num_coins, cents4){
  cr_assert(num_coins(4)==4);
}
Test(num_coins, cents59){
  cr_assert(num_coins(59)==7);
}
Test(water_cartons, 1p1t1v1c){
  cr_assert(water_cartons(1,1,1,1)==1);
}
Test(water_cartons, 3p8t11v2c){
  cr_assert(water_cartons(3,8,11,2)==2);
}
Test(water_cartons, 12p10t6v4c){
  cr_assert(water_cartons(12,10,6,4)==5);
}
Test(month_2nd_letter, february){
  cr_assert(month_2nd_letter(2)=='e');
}
Test(month_2nd_letter, may){
  cr_assert(month_2nd_letter(5)=='a');
}
Test(month_2nd_letter, november){
  cr_assert(month_2nd_letter(11)=='o');
}
Test(month_2nd_letter, notmonth){
  cr_assert(month_2nd_letter(37)==' ');
}
Test(digits_sum, num2938){
  cr_assert(digits_sum(2938)==22);
}
Test(digits_sum, num120){
  cr_assert(digits_sum(120)==3);
}
Test(digits_sum, num935128){
  cr_assert(digits_sum(935128)==28);
}
