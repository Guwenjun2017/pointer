#include <stdio.h>
#include "operate.h"

int main(int argc, char **argv)
{
    int num1;
    int num2;
    
    printf("请输入两个整型[逗号隔开]:");
    scanf("%d,%d", &num1, &num2);

    printf("+: %d\n",evaluate('+', num1, num2));
    printf("-: %d\n",evaluate('-', num1, num2));
    printf("*: %d\n",evaluate('*', num1, num2));
    printf("/: %d\n",evaluate('/', num1, num2));
    printf("%%: %d\n",evaluate('%', num1, num2));

    return 0;
}
