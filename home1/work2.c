#include <stdio.h>

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
   int *ptr1 = &a;
   int *ptr2 = &b;

   printf("Please input two int value:");
   scanf("%d,%d", &a, &b);
   if(a<b) {
	swap(ptr1, ptr2);
	printf("%d,%d\n", *ptr1, *ptr2);
   }
   else
	printf("%d,%d\n", *ptr1, *ptr2);

   return 0;
}
