#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int size;
    printf("输入内存大小:");
    scanf("%d", &size);
    int *ptr_arr = (int *)malloc(sizeof(int) * size);

    int initvalue;
    int addvalue;
    printf("输入初始值:");
    scanf("%d", &initvalue);
    printf("输入每次的增量:");
    scanf("%d", &addvalue);
    int *Ptr_arr = ptr_arr;
    for(int i = 0; i < size; i++) {
	*(ptr_arr + i) = initvalue + i * addvalue;
    }

    for(int i = 0; i < size; i++) {
	printf("address: %p and value: %d\n", Ptr_arr + i, *(Ptr_arr + i));
    }

    free(Ptr_arr);
    return 0;
}
