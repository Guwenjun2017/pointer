/* *========* *** *============================================== 
  * 联络信箱: *** :guwenjun2017@gmail.com
  * 文档用途: *** :CII实验报告
  * 文档信息: *** :~/.vimrc
  * 修订时间: *** *2017年第41周 10月10日 星期二 下午03:36 (283天
 * *========* *** *============================================== */
#include <stdio.h>
#include <stdlib.h>

void changeAndOutputChanged(int *num1, int *num2, int *num3);
void displayUnchange(int *num1, int *num2, int *num3);
void change(int *num1, int *num2, int *num3);

int main(int argc, char **argv)
{
    int *ptr_var1 = (int *)malloc(sizeof(int));
    int *ptr_var2 = (int *)malloc(sizeof(int));
    int *ptr_var3 = (int *)malloc(sizeof(int));

    printf("Please input three int value(以逗号隔开):");
    scanf("%d,%d,%d", ptr_var1, ptr_var2, ptr_var3);
    displayUnchange(ptr_var1, ptr_var2, ptr_var3);
    printf("\n");
    change(ptr_var1, ptr_var2, ptr_var3);
    printf("prt_var1 cv:%d\n", *ptr_var1);
    printf("prt_var2 cv:%d\n", *ptr_var2);
    printf("prt_var3 cv:%d\n", *ptr_var3);

    free(ptr_var1);
    free(ptr_var2);
    free(ptr_var3);

    return 0;
}

//实行交换并输出改变后的值
void change(int *num1, int *num2, int *num3) {
    int tmp;

    tmp = *num3;
    *num3 = *num2;
    *num2 = *num1;
    *num1 = tmp;
    printf("Changedvalue:\n");

    return;
}

//输出变量原来的值和地址的函数
void displayUnchange(int *num1, int *num2, int *num3) {
    printf("Unchange:\n");
    printf("ptr_var1,fv:%d\t fa:%p\n",*num1, num1);
    printf("ptr_var2,fv:%d\t fa:%p\n",*num2, num2);
    printf("ptr_var3,fv:%d\t fa:%p\n",*num3, num3);

    return;
}

