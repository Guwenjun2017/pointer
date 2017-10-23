/* *========* *** *============================================== 
  * 联络信箱: *** :guwenjun2017@gmail.com
  * 文档用途: *** :CII实验报告
  * 修订时间: *** *2017年第41周 10月10日 星期二 下午03:36 (283天
 * *========* *** *============================================== */
#include <stdio.h>
#include <stdlib.h>

void oneCircle(int *ptr_arr, int size, int add);

int main(int argc, char **argv)
{
    int size;
    int *ptr_arr = (int *)malloc(sizeof(int) * size);
    int *Ptr_arr = ptr_arr;
    int num;
    int add;
    char character;

    while(1){
	printf("请输入内存的大小(类型为int):");
	scanf("%d", &size);
	printf("请输入初始值:");
	scanf("%d", &num);
	printf("请输入每次的增量:");
	scanf("%d", &add);
	*ptr_arr = num;
	printf("ptr_arr fv: %d,*ptr_arr fa: %p", *ptr_arr, ptr_arr);
	printf("\n");
	oneCircle(ptr_arr, size, add);

	printf("Continue ?[输入y继续n退出]");
	getchar();
	scanf("%c", &character);
	if( character != 'y')
	    break;
    }

    free(ptr_arr);
    return 0;
}

void oneCircle(int *ptr_arr, int size, int add) {
    for(int i = 0; i < size; i++)
	*ptr_arr += add;	
    printf("ptr_arr lv: %d,*ptr_arr la: %p\n", *ptr_arr, ptr_arr);
}

//  printf("请输入内存的大小(类型为int):");
//  scanf("%d", &size);
//  printf("请输入初始值:");
//  scanf("%d", &num);
//  printf("请输入每次的增量:");
//  scanf("%d", &add);
//  *ptr_arr = num;
//  printf("ptr_arr fv: %d,*ptr_arr fa: %p\n", *ptr_arr, ptr_arr);
//  oneCircle(ptr_arr, size, add);
//  while(j == 1) {
//      printf("\n");
//      printf("Continue ?[输入y继续n退出]");
//      getchar();
//      scanf("%c", &character);
//      if (character != 'y')
//          break;
//      else {
//          printf("请输入内存的大小(类型为int):");
//          scanf("%d", &size);
//          printf("请输入初始值:");
//          scanf("%d", &num);
//          printf("请输入每次的增量:");
//          scanf("%d", &add);
//          *ptr_arr = num;
//          printf("ptr_arr fv: %d,*ptr_arr fa: %p", *ptr_arr, ptr_arr);
//          printf("\n");
//          oneCircle(ptr_arr, size, add);
//      }
//  }
