#include <stdio.h>

void sort(int *arr, int size);
void display(int arr[], int size);
int compare(int , int);
int main(int argc, char **argv)
{
    int size = 10;
    int arr[] = {
	3,0,4,1,6,7,8,9,2,5
    };

    sort(arr, size);
    display(arr, size);

    return 0;
}

void sort(int *arr, int size) {
    for(int i = 0; i <size - 1; i++){
	for(int j = 0; j < size - 1; j++){
	    if((compare(arr[j], arr[j + 1])) > 0){
		int tmp = arr[j] ;
		arr[j] = arr[j + 1];
		arr[j + 1] = tmp;
	    }
	}

    }

    return;
} 

void display(int *arr, int size) {
    for(int j = 0; j < size; j++){
	printf("%d\n", *(arr + j));
    }

    return;
} 

int compare(int num1, int num2) {
    int result;
    if(num1 > num2)
	result = 1;
    else if(num1 < num2)
	result = -1;
    else
	result = 0;

    return result;
}
