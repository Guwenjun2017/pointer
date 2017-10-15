#include <stdio.h>

int main(int argc, char **argv)
{
    int (*fptr)(int, int);
    int square(int num, int num3) {
	return num * num3;
    }

    typedef int (*fptrOperation)(int, int);

    int compute(fptrOperation operation, int num1, int num2) {
	return operation(num1, num2);
    }

    int add(int num1, int num2) {
	return num1 + num2;
    }

    int n = 5;
    fptr = square;
    printf("%d squared is %d\n", n, fptr(n, n));
    printf("%d squared is %d\n", 5, compute(fptr, n, 5));


    return 0;
}
