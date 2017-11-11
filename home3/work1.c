#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int *sort(int *, int);
void display(int arr[], int);

int main(int argc, char **argv)
{
    int arr[] = {
        3,0,4,1,6,7,8,9,2,5,
    };
    int size = sizeof(arr) / sizeof(int);
    int *sortedArr = sort(arr, size);

    display(sortedArr, size);

    free(sortedArr);
    return 0;
}

int *sort(int *arr, int size) {
    int *r = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i < size; i++){
	//注意指针不要越界
	for(int j = 0; j < size - i - 1; j++){
	    if(arr[j] > arr[j + 1]){
		int tmp = arr[j] ;
		arr[j] = arr[j + 1];
		arr[j + 1] = tmp;
	    }
	}
    }
    for(int j = 0; j < size; j++){
	r[j] = arr[j];
    }

    return r;
} 

void display(int *arr, int size) {
    for(int j = 0; j < size; j++){
	printf("%d\n", *(arr + j));
    }

    return;
} 
/*
 * 在c语言中,无法直接返回一个数组,但是可以通过返回对应类型指针的方式,来返回数组.
 * 在大多数情况下,一维数组和一维指针是可以通用的.
 * 本题核心函数sort,返回类型为int *型,参数为数组和数组长度,在函数内部为int *r临分
 * 配一个内存(该内存大小和传进来的数组的大小一致),将排好序的实参数组赋给r, 最后将
 * r 返回.
 * 冒泡排序算法,主要是两个for循环的嵌套,外层for循环决定了走几趟,内层for循环从前到
 * 后依次将值移至其相应位置.
 */
