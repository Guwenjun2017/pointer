#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(char * , int );
void displayPointer(char *, int );
int main(int argc, char **argv)
{
    char arr0[20] = "Hello,jju!";
    int arrSize = strlen(arr0);
    display(arr0, arrSize);
    printf("\n");

    char *arr1;
    displayPointer(arr1, strlen("Hello,jju!"));
    printf("\n");

    return 0;
}

void display(char iArr[], int size){
    for(int i = 0; i < size; i++){
	printf("%c", iArr[i]);
    }
}
 
void displayPointer(char *iArr, int size){
    iArr = (char *)malloc(strlen("Hello,jju!") + 1);
    iArr = "Hello,jju!";
    for(int i = 0; i < size; i++){
	printf("%c", *(iArr + i));
    }
} 
/*
 * 第一种输出用数组的方式,通过下标逐个输出.
 * 第二种输出用指针的形式,通过解引每个字符的地址,来逐个输出每个字符,最终输出整个字符串.
 */

