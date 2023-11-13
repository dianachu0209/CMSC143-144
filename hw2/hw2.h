/* takes in a number of cents and returns
 * the number of ways to make a certain
 * number of cents using any combinations of
 * quarters, dimes, nickels, and pennies
 * disregarding permutations */
unsigned int num_ways_coins(unsigned short cents);
/* given three numbers corresponding to
 * the month day and year of a date and a fourth
 * number that will be added to said date,
 * determine the month day and year of the new
 * date, accounting for leap years;
 * returns nothing but updates the three
 * pointer numbers in the function */
void days_later(unsigned char* month, unsigned char* day, unsigned short* year,
unsigned short days);
/* given a number n, find the prime number that is
 * in the nth position as we count up the prime numbers;
 * returns the prime number at the position n */
unsigned int nth_prime(unsigned short n);
/* given a number of slices, we
 * approximate the natural log of some number x
 * through using Riemann sums knowing the number
 * of sums that we will do (from the slice num);
 * returns the approximate log of some x */
double ln_approx(double x, unsigned int slices);
