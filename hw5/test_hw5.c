#include <stdlib.h>
#include <stdio.h>
#include <criterion/criterion.h>
#include "hw5.h"

/* Q1 Tests: unnecessary but I did them already */
Test(time, time1){
  struct time ts = {12,13,20,58};
  cr_assert(ts.days == 12);
  cr_assert(ts.hours == 13);
  cr_assert(ts.minutes == 20);
  cr_assert(ts.seconds == 58);
}
Test(time, time2){
  struct time t2 = {100,100,100,100};
  cr_assert(t2.days == 100);
  cr_assert(t2.hours == 100);
  cr_assert(t2.minutes == 100);
  cr_assert(t2.seconds == 100);
}

/* Q2 Tests */
Test(add_times, add_times1){
  struct time t1 = {1,2,3,4};
  struct time t2 = {5,6,7,8};
  struct time expected = {6,8,10,12};
  struct time sum = add_times(t1, t2);
  cr_assert(time_cmp(sum, expected) == 0);
}
Test(add_times, add_times2){
  struct time t1 = {12,30,50,90};
  struct time t2 = {1,2,3,4};
  struct time expected = {14,8,54,34};
  struct time sum = add_times(t1, t2);
  cr_assert(time_cmp(sum, expected) == 0);
}
Test(add_times, add_times3){
  struct time t1 = {0,0,0,0};
  struct time t2 = {0,0,0,70};
  struct time expected = {0,0,1,10};
  struct time sum = add_times(t1, t2);
  cr_assert(time_cmp(sum, expected) == 0);
}

/* Q3 Tests */
Test(noramlize_time, noramlize_time1){
  struct time t1 = {12,30,50,90};
  normalize_time(&t1);
  cr_assert(t1.seconds == 30);
  cr_assert(t1.minutes == 51);
  cr_assert(t1.hours == 6);
  cr_assert(t1.days == 13);
}
Test(noramlize_time, noramlize_time2){
  struct time t1 = {48,70,80,120};
  normalize_time(&t1);
  cr_assert(t1.seconds == 0);
  cr_assert(t1.minutes == 22);
  cr_assert(t1.hours == 23);
  cr_assert(t1.days == 50);
}

/* Q4 Tests */
Test(time_cmp, time_cmp1){
  struct time t1 = {12,30,50,90};
  struct time t2 = {12,30,50,90};
  cr_assert(time_cmp(t1,t2)==0);
}
Test(time_cmp, time_cmp2){
  struct time t1 = {13,30,50,90};
  struct time t2 = {12,30,50,90};
  cr_assert(time_cmp(t1,t2)==1);
}
Test(time_cmp, time_cmp3){
  struct time t1 = {12,30,50,90};
  struct time t2 = {12,30,50,91};
  cr_assert(time_cmp(t1,t2)==-1);
}
Test(time_cmp, time_cmp4){
  struct time t1 = {12,20,50,40};
  struct time t2 = {11,23,55,45};
  cr_assert(time_cmp(t1,t2)==1);
}

/* Q5 Tests */
Test(min_time, min_time1){
  struct time a[4] = {{0,0,10,0},{1,12,30,21},{0,0,0,20},{0,0,0,2}};
  cr_assert(min_time(a,4) == &a[3]);
}
Test(min_time, min_time2){
  struct time a[0] = {};
  cr_assert(min_time(a,0) == NULL);
}
Test(min_time, min_time3){
  struct time a[2] = {{0,1,0,0},{0,1,0,0}};
  cr_assert(min_time(a, 2) == &a[0] || min_time(a, 2) == &a[1]);
}
Test(min_time, min_time4){
  struct time a[3] = {{12,13,14,15},{12,13,15,14},{12,14,18,12}};
  cr_assert(min_time(a,3) == &a[0]);
}

/* Q6 Tests */
Test(times_longer_than, times_longer_than1){
  struct time a[4] = {{0,0,10,0},{1,12,30,21},{0,0,0,20},{0,0,0,2}};
  struct time threshold = {0,0,0,0};
  unsigned int reslen;
  struct time* res = times_longer_than(a,4,threshold,&reslen);
  int result = 1;
  if (reslen != 4){
    result = 0;
  }
  unsigned int i;
  for (i = 0; i < 4; i++){
    if (time_cmp(a[i],res[i]) != 0){
      result = 0;
    }
  }
  cr_assert(result);
  free(res);
}
Test(times_longer_than, times_longer_than2){
  struct time a[3] = {{12,11,14,15},{12,13,15,14},{12,14,18,12}};
  struct time threshold = {12,12,15,15};
  unsigned int reslen;
  struct time* res = times_longer_than(a,3,threshold,&reslen);
  int result = 1;
  if (reslen != 2){
    result = 0;
  }
  unsigned int i;
  for (i = 0; i < 2; i++){
    if (time_cmp(res[i],threshold) <= 0){
      result = 0;
    }
  }
  cr_assert(result);
  free(res);
}
Test(times_longer_than, times_longer_than3){
  struct time a[2] = {{0,1,0,0},{0,1,0,0}};
  struct time threshold = {12,12,15,15};
  unsigned int reslen;
  struct time* res = times_longer_than(a,2,threshold,&reslen);
  int result = 1;
  if (reslen != 0){
    result = 0;
  }
  cr_assert(result);
  free(res);
}

/* Q7 Tests */
Test(insert_after, insert_after1){
  intlist* l = (intlist*)malloc(sizeof(intlist));
  l -> val = 10;
  l -> next = (intlist*)malloc(sizeof(intlist));
  l -> next -> val = 20;
  l -> next -> next = (intlist*)malloc(sizeof(intlist));
  l -> next -> next -> val = 30;
  l -> next -> next -> next = NULL;
  int val = 42;
  unsigned int n = 1;
  insert_after(l, val, n);
  cr_assert(l != NULL);
  cr_assert(l -> val == 10);
  cr_assert(l -> next != NULL);
  cr_assert(l -> next -> val == 20);
  cr_assert(l -> next -> next != NULL);
  cr_assert(l -> next -> next -> val == val);
  cr_assert(l -> next -> next -> next != NULL);
  cr_assert(l -> next -> next -> next -> val == 30);
  cr_assert(l -> next -> next -> next -> next == NULL);
  free(l -> next -> next -> next -> next);
  free(l -> next -> next -> next);
  free(l -> next -> next);
  free(l -> next);
  free(l);
}
Test(insert_after, inster_after2){
  intlist* l = (intlist*)malloc(sizeof(intlist));
  l -> val = 10;
  l -> next = NULL;
  int val = 42;
  unsigned int n = 0;
  insert_after(l, val, n);
  cr_assert(l != NULL);
  cr_assert(l -> val == 10);
  cr_assert(l -> next != NULL);
  cr_assert(l -> next-> val == val);
  cr_assert(l -> next -> next == NULL);
  free(l);
}
Test(insert_after, insert_after3){
  intlist* l = (intlist*)malloc(sizeof(intlist));
  l -> val = 10;
  l -> next = NULL;
  int val = 42;
  unsigned int n = 0;
  insert_after(l, val, n);
  cr_assert(l != NULL);
  cr_assert(l -> val == 10);
  cr_assert(l -> next != NULL);
  cr_assert(l -> next -> val == val);
  cr_assert(l -> next -> next == NULL);
  free(l -> next);
  free(l);
}


/* Q8 Tests */
Test(remove_at, remove_at1) {
  intlist* l = (intlist*)malloc(sizeof(intlist));
  l -> val = 10;
  l -> next = (intlist*)malloc(sizeof(intlist));
  l -> next -> val = 20;
  l -> next -> next = NULL;
  unsigned int n = 0;
  l = remove_at(l, n);
  cr_assert(l -> val == 20);
  cr_assert(l -> next == NULL);
  free(l);
}
Test(remove_at, remove_at2) {
  intlist* l = (intlist*)malloc(sizeof(intlist));
  l -> val = 30;
  l -> next = (intlist*)malloc(sizeof(intlist));
  l -> next -> val = 40;
  l -> next -> next = (intlist*)malloc(sizeof(intlist));
  l -> next -> next -> val = 50;
  l -> next -> next -> next = NULL;
  unsigned int n = 1;
  l = remove_at(l, n);
  cr_assert(l -> val == 30);
  cr_assert(l -> next != NULL);
  cr_assert(l -> next -> val == 50);
  cr_assert(l -> next -> next == NULL);
  free(l -> next);
  free(l);
}
/* Q9 Tests */
Test(alternate, alternate1) {
    intlist* l1 = NULL;
    intlist* l2 = NULL;
    intlist* result = alternate(l1, l2);

    cr_assert(result == NULL);
}

Test(alternate, alternate2) {
  intlist* l1 = (intlist*)malloc(sizeof(intlist));
  l1 -> val = 10;
  l1 -> next = NULL;
  intlist* l2 = NULL;
  intlist* result = alternate(l1, l2);
  cr_assert(result != NULL);
  cr_assert(result -> val == 10);
  cr_assert(result -> next == NULL);
  free(result);
}

Test(alternate, alternate3) {
  intlist* l1 = (intlist*)malloc(sizeof(intlist));
  l1 -> val = 10;
  l1 -> next = (intlist*)malloc(sizeof(intlist));
  l1 -> next -> val = 20;
  l1 -> next -> next = NULL;
  intlist* l2 = (intlist*)malloc(sizeof(intlist));
  l2 -> val = 30;
  l2 -> next = (intlist*)malloc(sizeof(intlist));
  l2 -> next -> val = 40;
  l2 -> next -> next = NULL;
  intlist* result = alternate(l1, l2);
  cr_assert(result != NULL);
  cr_assert(result -> val == 10);
  cr_assert(result -> next -> val == 30);
  cr_assert(result -> next -> next -> val == 20);
  cr_assert(result -> next -> next -> next -> val == 40);
  cr_assert(result -> next -> next -> next -> next == NULL);
  free(result -> next -> next);
  free(result -> next);
  free(result);
}

Test(alternate, alternate4) {
  intlist* l1 = (intlist*)malloc(sizeof(intlist));
  l1 -> val = 10;
  l1 -> next = (intlist*)malloc(sizeof(intlist));
  l1 -> next -> val = 20;
  l1 -> next -> next = NULL;
  intlist* l2 = (intlist*)malloc(sizeof(intlist));
  l2 -> val = 30;
  l2 -> next = NULL;
  intlist* result = alternate(l1, l2);
  cr_assert(result != NULL);
  cr_assert(result -> val == 10);
  cr_assert(result -> next -> val == 30);
  cr_assert(result -> next -> next -> val == 20);
  cr_assert(result -> next -> next -> next == NULL);
  free(result -> next);
  free(result);
}

/* Q10 Tests */
Test(deposit, deposit1){
  struct tagged_account acct;
  acct.tag = SAVINGS;
  acct.u.s.balance = 100;
  acct.u.s.withdrawals = 1;
  deposit(&acct, 200);
  cr_assert(acct.u.s.balance == 300);
}
Test(deposit, deposit2){
  struct tagged_account acct;
  acct.tag = CHECKING;
  acct.u.c.balance = 10;
  acct.u.c.rewards = 12;
  deposit(&acct, 500);
  cr_assert(acct.u.c.balance == 510);
  cr_assert(acct.u.c.rewards == 17);
}

/* Q11 Tests */
Test(withdraw, withdraw1){
  struct tagged_account acct;
  acct.tag = SAVINGS;
  acct.u.s.balance = 100;
  acct.u.s.withdrawals = 1;
  int res = withdraw(&acct, 50);
  cr_assert(acct.u.s.balance == 50);
  cr_assert(acct.u.s.withdrawals == 2);
  cr_assert(res == 1);
}
Test(withdraw, withdraw2){
  struct tagged_account acct;
  acct.tag = CHECKING;
  acct.u.c.balance = 10;
  acct.u.c.rewards = 12;
  int res = withdraw(&acct, 50);
  cr_assert(acct.u.c.balance == 10);
  cr_assert(acct.u.c.rewards == 12);
  cr_assert(res == 0);
}
Test(withdraw, withdraw3){
  struct tagged_account acct;
  acct.tag = SAVINGS;
  acct.u.s.balance = 100;
  acct.u.s.withdrawals = 6;
  int res = withdraw(&acct, 50);
  cr_assert(acct.u.s.balance == 100);
  cr_assert(acct.u.s.withdrawals == 6);
  cr_assert(res == 0);
}
