#include <stdio.h>

void swapwithPointers(int *ptr_num1, int *ptr_num2);
void swap(int num1, int num2);

int main(int argc, char **argv)
{
    int num1;
    int num2;
    
    printf("Input 2 int value[逗号隔开]:");
    scanf("%d,%d", &num1, &num2);
    //
    printf("用指针传递数据时:");
    swapwithPointers(&num1, &num2);
    printf("%d,%d\n", num1, num2);
    //
    printf("用值传递数据时:");
    swap(num1, num2);
    printf("%d,%d\n", num1, num2);

    return 0;
}

void swapwithPointers(int *ptr_num1, int *ptr_num2) {
    int tmp;
    tmp = *ptr_num2;
    *ptr_num2 = *ptr_num1;
    *ptr_num1 = tmp;
}

void swap(int num1, int num2) {
    int tmp;
    tmp = num2;
    num2 = num1;
    num1 = tmp;
}
