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
    int *sortedArr = (int *)malloc(sizeof(int) * size);

    sortedArr = sort(arr, size);
    display(sortedArr, size);

    free(sortedArr);
    return 0;
}

int *sort(int *arr, int size) {
    int *r = (int *)malloc(sizeof(int) * size);
    for(int i = 0; i <size - 1; i++){
	//注意指针不要越界
	for(int j = 0; j < size - 1; j++){
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
