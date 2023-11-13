#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
int w = atoi(argv[1]);
int h = atoi(argv[2]);
int r = atoi(argv[3]);
int g = atoi(argv[4]);
int b = atoi(argv[5]);
printf("P3\n");
printf("%d %d\n",w,h);
printf("255\n");
int count = w*h;
while (count > 0){
  printf("%d %d %d\n",r,g,b);
  count --;
}
}
