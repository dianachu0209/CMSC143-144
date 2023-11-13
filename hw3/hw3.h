/* takes in an array and returns a pseudo-boolean
 * representing if all elements in the array
 * are even or not */
int all_even(int a[], unsigned int alen);
/* takes in an array and returns a pseudo-boolean
 * representing if any elements in the array
 * are even */
int exists_even(int a[], unsigned int alen);
/* takes in an array and returns the index
 * of the first even element in the array;
 * returns -1 otherwise */
int first_even(int a[], unsigned int alen);
/* takes in an array and returns the number of
 * even numbers in the array */
unsigned int number_evens(int a[], unsigned int alen);
/* takes in an array and changes all odd numbers to
 * even numbers closer to zero (decreases for
 * positives and increases for negatives);
 * leaves even numbers unchanged */
void make_evens(int a[], unsigned int alen);
/* takes in an array and continues to count
 * the number of evens, returning a new array
 * of the same length that records the 
 * count in each index */
unsigned int* running_evens(int a[], unsigned int alen);
/* takes in an array and moves each element
 * left one (decreases index by 1), moving the first
 * element to the end */
void rotate_left(int a[], int alen);
/* takes in two arrays and combines them into a 
 * new array, alternating between the elements
 * in both arrays until one or both run out;
 * returns the new array  */
int* stitch(int* a, unsigned int alen, int* b, unsigned int blen);
/* given an upperbound, return an array of fibonacci
 * numbers in order up to and including the bound
 * return the array and write the length into memory */
unsigned int* fib_upto(unsigned int bound, unsigned int* len);
/* given a string (array), change all lowercase
 * letters in capital letters in the out array
 * leaving other characters alone */
void uppercase(char* in, char* out);
