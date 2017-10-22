#include <stdio.h>
#include <stdlib.h>
#define SIZE 35

char *getLine(void){
    const size_t sizeIncrement = 15;
    char *buffer = (char *)malloc(SIZE);
    char *currentPosition = buffer;
    size_t maximumLength = SIZE;
    size_t length = 0;
    int character;

    if (currentPosition == NULL){
	return NULL;
    }
    while(1){
	character = getc(stdin);
	if(character == '\n'){
	    break;
	}
	if(++length >= maximumLength){
	    char *newBuffer = realloc(buffer, maximumLength += sizeIncrement);
	    if(newBuffer == NULL){
		free(buffer);
		return NULL;
	    }
	    currentPosition = newBuffer + (currentPosition - buffer);
	    buffer = newBuffer;
	}
	*currentPosition++ = character;
    }
    *currentPosition = '\0';

    return buffer; 
}

int main(int argc, char **argv)
{
    printf("Please input string:\n");
    char *ptr_c = getLine();
    while(*ptr_c != '\0'){
	printf("%c", *ptr_c++);
    }

    printf("\n");

    return 0;
}
