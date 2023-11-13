/* converts a number into a string to a certain
 * decimal place passed into the function; returns
 * the string with the appropriate number of
 * decimal places if a positive number is given,
 * returns 'negative' for a negative number
 * and 'too big' for a number too big */
char* double_to_str(double d, unsigned char after_decimal);
/* takes in a desired substring and a string and
 * finds the indices of each occurance in the
 * string; returns a list of indices */
unsigned int* locations_of(char* substr, char* string, unsigned int* n);
