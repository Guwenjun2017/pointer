#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int (fptrOperation)(char *, char *);
char *stringTolower(char *);
int compareIgnore(char *, char *);
void sort(char **, int, fptrOperation);
int lower(int c);
void display(char **, int );
int main(int argc, char **argv)
{
    char *arr1[] = {
	"Bob", "Ted", "Carol", "Alice", "alice",
    };

    sort(arr1, 5, compareIgnore);
    display(arr1, 5);


    return 0;
}

char *stringTolower(char *string){
    char *tmp = (char *)malloc(strlen(string) + 1);
    while(*string != 0){
	*tmp++ = lower(*string++);
    }

    return tmp;
}

int lower(int c){
    if(c >= 'A' && (c < 'a')){
	c += 'a' - 'A';	
    }

    return 0;
} 

int compareIgnore(char *a, char *b){
    char *a1 = stringTolower(a);
    char *b1 = stringTolower(b);
    return strcmp(a1, b1);
}


void sort(char **arr, int iSize, fptrOperation operation){
    int j = 1;
    while(j){
	j = 0;
	for(int i = 0; i < iSize -1; i++){
	    if(operation(arr[i], arr[i + 1]) > 0){
		j = 1;
		char *tmp = arr[i];
		arr[i] = arr[i + 1];
		arr[i + 1] = tmp;
	    }
	}
    }
}

void display(char *iArr0[], int size){
    for(int i = 0; i < size; i++){
	printf("%s\t", iArr0[i]);
    }
    printf("\n");

    return;
}
