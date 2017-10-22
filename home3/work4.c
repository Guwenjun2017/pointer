#include <stdio.h>

void display_2D_Arr(int **iArr, int iRow, int i);
int main(int argc, char **argv)
{
    int (*(arr[]))= {
	(int[]) {1, 2, 3, 4, 5},
	(int[]) {6, 7, 8},
	(int[]) {9, 10, 11, 12},
	(int[]) {13, 14}
    };

    int row = 0;
    for(int i = 0; i < 5; i++){
	display_2D_Arr(arr, row, i);
    }
    printf("\n");

    row = 1;
    for(int i = 0; i < 3; i++){
	display_2D_Arr(arr, row, i);
    }
    printf("\n");

    row = 2;
    for(int i = 0; i < 4; i++){
	display_2D_Arr(arr, row, i);
    }
    printf("\n");

    row = 3;
    for(int i = 0; i < 2; i++){
	display_2D_Arr(arr, row, i);
    }
    printf("\n");

    return 0;
}

void display_2D_Arr(int **iArr, int iRow, int i){
    printf("arr[%d][%d] Address: %p Value: %d\n", iRow, i, *((iArr + iRow) + i), iArr[iRow][i]);
}

