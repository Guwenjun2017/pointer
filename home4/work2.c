#include <stdio.h>
#include <string.h>

int compare(char *, char *);
void copy(char *, char *);
void cat(char *, char *);
void display(char *);
int main(int argc, char argv)
{
    char arr0[50] = "JiuJiang ";
    char arr1[50] = "University";
    char arr2[50] = "JiuJiang University";
    char arr3[50];

    printf("%d\t%d\n", arr0[0], arr1[0]);
    printf("比较:");
    printf("[1表示前者大于后者,-1相反,0相等]\n");
    printf("%d\n", compare(arr0, arr1));
    printf("复制:");
    copy(arr3, arr2);
    display(arr3);
    printf("拼接:\n");
    cat(arr0, arr1);
    display(arr0);

    return 0;
}

int compare(char *iArr0, char *iArr1){
    int i = 1;
    int k = 0;
    int size;
    int result;

    if(strlen(iArr0) > strlen(iArr1))
	size = strlen(iArr1);
    else 
	size = strlen(iArr0);

    while(i == 1){
	i = 0;
	for(int j = size - 1; j >= 0; j--){
	    //切记类型转换
	    if((int)iArr0[j] == (int)iArr1[j]){
		i =1;
		result = 0;   
		k++;
		if(k == size){
		    if(strlen(iArr0) > strlen(iArr1))
			result = 1;
		    else 
			result = -1;
		}
	    }
	    else if((int)iArr0[j] > (int)iArr1[j])
		result = 1;
	    else
		result = -1;
	}
    }

    return result;
}

void copy(char *iArr0, char *iArr1){
    int size = strlen(iArr1);
    
    for(int j = 0; j < size; j++){
	*(iArr0 + j) = *(iArr1 + j);
    }

    return;
}

void cat(char *iArr0, char *iArr1){
    int size1 = strlen(iArr0);
    int size2 = strlen(iArr1);

    for(int j = 0; j < size2; j++){
	*(iArr0 + size1 + j) = *(iArr1 + j);
    }

    return;
}

void display(char *iArr0){
    int size = strlen(iArr0);

    for(int j = 0; j <size; j++){
	printf("%c", *(iArr0 + j));
    }
    printf("\n");

    return;
}
