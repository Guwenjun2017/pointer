/* *========* *** *============================================== 
  * 联络信箱: *** :guwenjun2017@gmail.com
  * 文档用途: *** :CII实验报告
  * 修订时间: *** *2017年第41周 10月15日 星期日 下午05:22 (288天)
 * *========* *** *============================================== */

#include <stdio.h>
#include <stdlib.h>
#define ADD 1
#define ADDTIME 5

int main(int argc, char **argv)
{
    int var1;
    const int cvar1;
    int *ptr_var1;
    int *ptr_cvar1;
    int *const cptr_var1 = (int *)malloc(sizeof(int));
    int *const cptr_var2 = (int *)malloc(sizeof(int));
    const int *const cptr_cvar1;

    printf("请输入变量var1:");
    scanf("%d", &var1);
    printf("请输入常量cvar1:");
    scanf("%d", &cvar1);

    void test1(int var1, int *ptr_var1) {
        ptr_var1 = &var1;
        for(int i = 0; i < ADDTIME; i++) {
            var1 += ADD;
        }
        printf("var1:%d\n", var1);
        for(int j = 0; j < ADDTIME; j++) {
            (*ptr_var1) += ADD;
        }
        printf("*ptr_var1:%d\n", *ptr_var1);
        return;
    }
    test1(var1, ptr_var1);

    void test2(int var2, const int cvar2, const int *ptr_cvar2) {
	ptr_cvar2 = &var2;
	printf("ptr_cvar2:%p\n", ptr_cvar2);
	ptr_cvar2 = &cvar2;	
	printf("ptr_cvar2 c:%p\n", ptr_cvar2);

	return;
    }
    test2(var1, cvar1, ptr_cvar1);

    void test3(int var3, const int cvar4, int *const cptr_var1, int *const cptr_var2) {
        *cptr_var1 = var3;
        *cptr_var2 = cvar4;
        for(int i = 0; i < ADDTIME; i++) {
           (*cptr_var1) += ADD;
        }
        for(int j = 0; j < ADDTIME; j++) {
            (*cptr_var2) += ADD;
        }
        printf("*cptr_var3:%d\n", *cptr_var1);
        printf("*cptr_var4:%d\n", *cptr_var2);

        return;
    }
    test3(var1, cvar1, cptr_var1, cptr_var2);

    void test4(const int cvar1, const int *const cptr_cvar1) {
	/*
	 *
	 *
	 *
	 */

	return;
    }

    free(cptr_var1);
    free(cptr_var2);
    return 0;
}
