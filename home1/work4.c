/* *========* *** *============================================== 
  * 联络信箱: *** :guwenjun2017@gmail.com
  * 文档用途: *** :CII实验报告
  * 文档信息: *** :~/.vimrc
  * 修订时间: *** *2017年第41周 10月10日 星期二 下午03:36 (283天
 * *========* *** *============================================== */
#include <stdio.h>
#include <stdlib.h>
#define add 1
#define addtime 5

int main(int argc, char **argv)
{
    int var1;
    const int cvar1;
    int *ptr_var1 = (int *)malloc(sizeof(int));
    int *ptr_cvar1 = (int *)malloc(sizeof(int));
    int *const cptr_var1 = (int *)malloc(sizeof(int));
    int *const cptr_var2 = (int *)malloc(sizeof(int));

    printf("请输入变量var1:");
    scanf("%d", &var1);
    printf("请输入常量cvar1:");
    scanf("%d", &cvar1);
    void test1(int var1, int *ptr_var1) {
	ptr_var1 = &var1;
	for(int i = 0; i < addtime; i++) {
	    var1 += add;
	}
	printf("var1:%d\n", var1);
	for(int j = 0; j < addtime; j++) {
	    (*ptr_var1) += add;
	}
	printf("*ptr_var1:%d\n", *ptr_var1);
    }
    test1(var1, ptr_var1);

    void test2(int var2, const int cvar2, const int *ptr_cvar2) {
	ptr_cvar2 = &var2;
	//for(int i = 0; i < addtime; i++) {
	    //(*ptr_cvar2) += add;
	//}
	printf("ptr_cvar2:%p\n", ptr_cvar2);
	ptr_cvar2 = &cvar2;	
	printf("ptr_cvar2 c:%p\n", ptr_cvar2);
    }
    test2(var1, cvar1, ptr_cvar1);

    void test3(int var3, const int cvar4, int *const cptr_var1, int *const cptr_var2) {
	*cptr_var1 = var3;
	*cptr_var2 = cvar4;
	for(int i = 0; i < addtime; i++) {
	    (*cptr_var1) += add;
	}
	for(int j = 0; j < addtime; j++) {
	    (*cptr_var2) += add;
	}
	printf("*cptr_var3:%d\n", *cptr_var1);
	printf("*cptr_var4:%d\n", *cptr_var2);
    }
    test3(var1, cvar1, cptr_var1, cptr_var2);

    void test4(const int cvar1, const int *const cptr_cvar1) {
	/*
	 *
	 *
	 *
	 */
    }

    free(ptr_var1);
    free(ptr_cvar1);
    free(cptr_var1);
    free(cptr_var2);
    return 0;
}
