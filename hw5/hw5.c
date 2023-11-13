#include <stdlib.h>
#include <stdio.h>
#include "hw5.h"

struct time add_times(struct time t1, struct time t2){
  unsigned char nday, nhour, nmin, nsec;
  nday = t1.days + t2.days;
  nhour = t1.hours + t2.hours;
  nmin = t1.minutes + t2.minutes;
  nsec = t1.seconds + t2.seconds;
  struct time timesum = {nday, nhour, nmin, nsec};
  normalize_time(&timesum);
  return timesum;
}
void normalize_time(struct time* t){
  if (t -> seconds > 59){
    t -> minutes += (t -> seconds / 60);
    t -> seconds = t -> seconds % 60;
  }if (t -> minutes > 59){
    t -> hours += (t -> minutes / 60);
    t -> minutes = t -> minutes % 60;
  }if (t -> hours > 23){
    t -> days += (t -> hours / 24);
    t -> hours = t -> hours % 24;
  }
}
int time_cmp(struct time t1, struct time t2){
  if (t1.days != t2.days){
    return t1.days - t2.days;
  }else if (t1.hours != t2.hours){
    return t1.hours - t2.hours;
  }else if (t1.minutes != t2.minutes){
    return t1.minutes - t2.minutes;
  }else{
    return t1.seconds - t2.seconds;
  }
}
struct time* min_time(struct time* times, unsigned int tslen){
  if (tslen == 0){
    return NULL;
  }
  int i, smallestidx = 0;
  for (i = 0; i < tslen; i ++){
    if (time_cmp(times[i], times[smallestidx]) < 0){
      smallestidx = i;
    }
  }
  return &times[smallestidx];
}
struct time* times_longer_than(struct time* times, unsigned int tslen,
                               struct time threshold, unsigned int* reslen){
  int i, length = 0;
  for (i = 0; i < tslen; i ++){
    if (time_cmp(times[i], threshold) > 0){
      length++;
    }
  }
  *reslen = length;
  struct time* res = (struct time*)malloc(sizeof(struct time) * length);
  if (res == NULL){
    fprintf(stderr, "times_longer_than: not enough memory\n");
    exit(1);
  }
  int j, residx = 0;
  for (j = 0; j < tslen; j ++){
    if (time_cmp(times[j], threshold) > 0){
      res[residx] = times[j];
      residx ++;
    }
  }
  return res;
}
void insert_after(intlist* l, int val, unsigned int n){
  if (l == NULL){
    fprintf(stderr, "list does not exist\n");
    exit(1);
  }
  intlist* current = l;
  unsigned int currentIndex = 0;
  while (current != NULL && currentIndex < n){
    current = current -> next;
    currentIndex++;
  }
  if (current == NULL){
    fprintf(stderr,"out of bounds\n");
    exit(1);
  }
  intlist* newNode = (intlist*)malloc(sizeof(intlist));
  if (newNode == NULL){
    fprintf(stderr,"insert_after: not enough memory\n");
    exit(1);
  }
  newNode -> val = val;
  newNode -> next = current -> next;
  current -> next = newNode;
}
intlist* remove_at(intlist* l, unsigned int n){
  if (l == NULL){
    fprintf(stderr, "list does not exist\n");
    exit(1);
  }
  if (n == 0){
    intlist* nhead = l -> next;
    free(l);
    return nhead;
  }
  intlist* current = l;
  unsigned int i;
  for (i = 0; i < n - 1; i++){
    if (current -> next == NULL){
      fprintf(stderr,"index is out of bounds\n");
      exit(1);
    }
    current = current -> next;
  }
  intlist* temp = current -> next;
  if (temp == NULL){
    fprintf(stderr,"index is out of bounds\n");
    exit(1);
  }
  current -> next = temp -> next;
  free(temp);
  return l;
}
intlist* alternate(intlist* l1, intlist* l2) {
  if (l1 == NULL){
    return l2;
  }if (l2 == NULL){
    return l1;
  }
  intlist *head = l1, *tail = l1;
  l1 = l1 -> next;
  while (l1 != NULL || l2 != NULL){
    if (l2 != NULL){
      tail -> next = l2;
      tail = l2;
      l2 = l2 -> next;
    }
    if (l1 != NULL){
      tail -> next = l1;
      tail = l1;
      l1 = l1 -> next;
    }
  }
  tail -> next = NULL;
  return head;
}
void deposit(struct tagged_account* acct, unsigned int amt){
  switch (acct -> tag){
    case SAVINGS:
      acct -> u.s.balance += amt;
      break;
    case CHECKING:
      acct -> u.c.balance += amt;
      acct -> u.c.rewards += (amt / 100);
      break;
    default:
      fprintf(stderr,"deposit: invalid tag\n");
      exit(1);
  }
}
int withdraw(struct tagged_account* acct, unsigned int amt){
  switch (acct -> tag){
    case SAVINGS:
      if (acct -> u.s.balance >= amt && acct -> u.s.withdrawals < 6){
        acct -> u.s.balance -= amt;
        acct -> u.s.withdrawals ++;
        return 1;
      }else{
        return 0;
      }
    case CHECKING:
      if (acct -> u.c.balance >= amt){
        acct -> u.c.balance -= amt;
        return 1;
      }else{
        return 0;
      }
    default:
      return 0;
  }
}
