/* a struct that has days, hours, minutes
 * and seconds stored as numbers, these values
 * are expected to be within range of the
 * unit of time */
struct time {
  unsigned char days, hours, minutes, seconds;
};
/* takes in two times and adds the values
 * in each slot, making a new time; 
 * returns the new time normalized */
struct time add_times(struct time t1, struct time t2);
/* takes in a pointer to a time and
 * fixes values so that the values dont
 * exceed customary maximums, keeping
 * the same amount of time overall */
void normalize_time(struct time* t);
/* compares two times; returns a positive
 * integer if time1 is larger, 0 if
 * they are equal, and a negative integer
 * if time2 is larger */
int time_cmp(struct time t1, struct time t2);
/* taking in an array of times and the
 * length of the array, returns a pointer
 * to the smallest time in the array; if
 * empty, return NULL*/
struct time* min_time(struct time* times, unsigned int tslen);
/* taking in an array of times and a threshold,
 * return a new array consisting of only times
 * greater than the threshold and update reslen 
 * to reflect the length of the new array */
struct time* times_longer_than(struct time* times, unsigned int tslen,
                               struct time threshold, unsigned int* reslen);
typedef struct intlist intlist;
/* a linked list of integers
 * that has a value and a pointer
 * to the next elememt */
struct intlist {
    int val;
    intlist* next;
};
/* prepend function from class, adds
 * a value to the beginning of an intlist
 * and returns the new pointer to the
 * start of the linked list */
intlist* prepend(int val, intlist* next);
/* taking in a linked list, a value to be added
 * and an index, add the value after the
 * given index; if index is outside the length
 * of the linked list, raise an error */
void insert_after(intlist* l, int val, unsigned int n);
/* taking in a linked list and an index,
 * remove the element at the index, raising an
 * error if the element is outside the length */
intlist* remove_at(intlist* l, unsigned int n);
/* taking in two intlists, combine them into
 * a new intlist, alternatig between the
 * elements in both intlists until one or both
 * run out; return a new intlist */
intlist* alternate(intlist* l1, intlist* l2);
/* a savings account that has its balance
 * represented as a number of cents; has
 * up to 6 widthdrawels a month and tracks
 * the amount remaining */
struct savings {
    unsigned int balance;
    unsigned char withdrawals;
};
/* tracks balance in cents and tracks
 * rewards for every 100 cents deposited
 * rounding down */
struct checking {
    unsigned int balance;
    unsigned int rewards;
};
/* an account that has both savings
 * and checking  */
union account {
    struct savings s;
    struct checking c;
};
/* tag for account */
enum account_tag {
    SAVINGS, CHECKING
};
/* generalized account at a bank */
struct tagged_account {
    union account u;
    enum account_tag tag;
};
/* takes in a pointer to an account and update
 * the balance and the rewards (if checking)  */
void deposit(struct tagged_account* acct, unsigned int amt);
/* takes in a pointer to an account and updates
 * the balance by subtracting the withdrawal amount,
 * returns a pseudo boolean if insufficient balance
 * or withdrawal limit exceeded for a savings acc,
 * alsoe updates the withdrawal value for a savings
 * account, no limit on withdrawal amount */
int withdraw(struct tagged_account* acct, unsigned int amt);
