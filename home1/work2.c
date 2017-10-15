#include <stdio.h>
#include <stdlib.h>

void swap(int *p1, int *p2) {
    int p;

    p = *p1; 
    *p1 = *p2;
    *p2 = p;

    return; 
}

int main(int argc, char **argv)
{
   int a,b;
   int *ptr1 = (int *)malloc(sizeof(int));
   int *ptr2 = (int *)malloc(sizeof(int));

   printf("Please input two int value:");
   scanf("%d,%d", &a, &b);
   ptr1 = &a;
   ptr2 = &b;
   if(a<b) {
	swap(ptr1, ptr2);
	printf("%d,%d\n", *ptr1, *ptr2);
   }
   else
	printf("%d,%d\n", *ptr1, *ptr2);

   //free(ptr1);
   //free(ptr2);
   return 0;
}
