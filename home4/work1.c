#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void display(char * , int );
void displayPointer(char *iArr, int size);
int main(int argc, char **argv)
{
    char arr0[20] = "Hello,jju!";
    int arrSize = strlen(arr0);
    display(arr0, arrSize);
    printf("\n");

    char *arr1 =(char *)malloc(strlen("Hello,jju!") + 1);
    arr1 = "Hello,jju!";
    displayPointer(arr1, strlen("Hello,jju!"));
    printf("\n");

}

void display(char iArr[], int size){
    for(int i = 0; i < size; i++){
	printf("%c", iArr[i]);
    }
}
 
void displayPointer(char *iArr, int size){
    for(int i = 0; i < size; i++){
	printf("%c", *(iArr + i));
    }
} 
