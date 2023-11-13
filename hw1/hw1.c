#include <math.h>
#include "hw1.h"

unsigned short num_coins(unsigned short cents){
  /*
  Takes in a number of cents and returns the least number of coins to make
  the total

  Inputs:
    cents [unsigned short]: cents wanted

  Returns [unsigned short]: number of coins needed
  */
  int quarters = cents / 25;
  cents -= quarters * 25;
  int dimes = cents / 10;
  cents -= dimes * 10;
  int nickles = cents / 5;
  cents -= nickles * 5;
  int pennies = cents;
  return (quarters + dimes + nickles + pennies);
}
unsigned short water_cartons(unsigned short people, unsigned short thirst,
unsigned short volume, unsigned short count){
  /*
  Takes in multiple factors to find the number of water cartons needed

  Inputs:
    people [unsigned short]: number of people
    thirst [unsigned short]: water per person
    volume [unsigned short]: water in each bottle
    count [unsigned short]: bottles per carton

  Returns [unsigned short]: number of cartons needed
  */
  int volume_needed = people * thirst;
  int bottles;
  if (volume_needed % volume != 0){
    bottles = volume_needed / volume + 1;
  }else{
    bottles = volume_needed / volume;
  }int cartons;
  if (bottles % count != 0){
    cartons = bottles / count + 1;
  }else{
    cartons = bottles / count;
  }return cartons;
}

char month_2nd_letter(unsigned char month){
  /*
  Given a month, returns the second character of the name

  Inputs:
    month [unsigned char]: month number

  Returns [char]: second letter of the month's name
  */
  switch(month){
    case 1:
    case 3:
    case 5:
      return 'a';
    case 2:
    case 9:
    case 12:
      return 'e';
    case 4:
      return 'p';
    case 6:
    case 7:
    case 8:
      return 'u';
    case 10:
      return 'c';
    case 11:
      return 'o';
    default:
      return ' ';
  }
}

unsigned char digits_sum(unsigned int n){
  /*
  Takes in a number and returns the sum of individual digits

  Inputs:
    n [unsigned int]: number being taken in

  Returns [unsigned char]: sum of decimal digits
  */
  if (n < 10){
    return n;
  }else if (n % 10 == 0){
    n = n / 10;
    return digits_sum(n);
  }else{
    int num = n % 10;
    n -= num;
    return num + digits_sum(n);
  }
}
