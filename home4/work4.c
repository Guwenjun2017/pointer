#include <stdio.h>
#include <string.h>

void lower(char **, int ,char **);
void display(char **, int );
int main(int argc, char **argv)
{
    char *arr0;
    char *arr1[] = {
	"Bob", "Ted", "Carol", "Alice", "alice",
    };
    char **arr2;

    int size = sizeof(arr1)/sizeof(char *);
    printf("%d\n", size);

    void sort(char *iArr0[], int size){
	int j = 1;
	while(j){
	    j = 0;
	    for(int i = 0; i < size - 1; i++){
		if((strcmp(iArr0[i], iArr0[i + 1])) > 0){
		    j = 1;
		    char *tmp = iArr0[i];
		    iArr0[i] = iArr0[i + 1];
		    iArr0[i + 1] = tmp;
		}
	    }
	}

	return;
    }

    void sortIgnore(char *iArr0[], int size, char **iArr1){
	int j = 1;
        while(j){
            j = 0;
            for(int i = 0; i < size - 1; i++){
		lower(iArr0, 5, iArr1);
        	if((strcmp(iArr0[i], iArr0[i + 1])) > 0){
        	    j = 1;
        	    char *tmp = iArr0[i];
        	    iArr0[i] = iArr0[i + 1];
        	    iArr0[i + 1] = tmp;
        	}
            }
	} 
	return;
    }

    //printf("请输入字符串:");
    //scanf("%s", arr0);
    //lower(arr0);
    //display(arr0);
    sort(arr1, size);
    display(arr1, size);
    //sortIgnore(arr1, size);
    lower(arr1, 5, arr2);
    display(arr2, size);
    printf("\n");

    return 0;
}

void lower(char **iArr0, int size, char **iArr1){
    for(int k = 0; k < size; k++){
	for(int j = 0; j <strlen(iArr0[k]); j++){
	    //iArr1[k][j] = tolower(iArr0[k][j]);
	    strcpy(iArr1[k], iArr0[k]);
	    printf("%c", tolower(iArr0[k][j]));
	//for(int i = 0; i < size; i++){
	    //if(iArr0[k][j] >= 65 && iArr0[k][j] < 97){
	    //    iArr0[k][j] += 32;	
	    //    printf("%c", iArr0[k][j]);
	    }
	}

    return;
}




void display(char *iArr0[], int size){
    for(int i = 0; i < size; i++){
	printf("%s\t", iArr0[i]);
    }
    printf("\n");

    return;
}
