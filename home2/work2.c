#include <stdio.h>

int main(int argc,char **argv)
{
    int num1 = 6;
    int num2 = 5;
    
    int add(int num1, int num2) {
	return num1 + num2;
    }
    int sub(int num1, int num2) {
	return num1 - num2;
    }
    int mul(int num1, int num2) {
	return num1 * num2;
    }
    int div(int num1, int num2) {
	return num1 / num2;
    }
    int quyu(int num1, int num2) {
	return num1 % num2;
    }
    typedef int (*fptrOperation)(int, int);
    int compute(fptrOperation operation, int num1, int num2) {
	return operation(num1, num2);
    }

    printf("+: %d+%d=%d\n", num1, num2, compute(add, num1, num2));
    printf("-: %d-%d=%d\n", num1, num2, compute(sub, num1, num2));
    printf("*: %d*%d=%d\n", num1, num2, compute(mul, num1, num2));
    printf("/: %d/%d=%d\n", num1, num2, compute(div, num1, num2));
    printf("%%: %d%%%d=%d\n", num1, num2, compute(quyu, num1, num2));

    return 0;
}
