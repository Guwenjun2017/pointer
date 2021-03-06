#include <stdio.h>
#include <stdlib.h>
#define SIZE 35

char *getLine(void);
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
/*
    sizeIncrement = 15
    当输入流进来的数据长度超过已分配内存的SIZE时,增加的内存大小.
    buffer = (char *)malloc(SIZE)
    指向读入字符的指针.
    currentPosition = buffer
    指向缓冲区下一空白位置的指针.
    maximumLength = SIZE
    初始时可读入缓存区的最大字符数.
    length = 0
    读入的字符数.
    character
    读入的字符.
    char *newBuffer = realloc(buffer, maximumLength += sizeIncrement)
    当读入字符数大于初始分配的maximumLength时,调用realloc函数调整数组长度(即为旧内存增加sizeIncrement字节).
    currentPosition = newBuffer + (currentPosition - buffer)
    realloc分配新内存成功时,将currentPosition指向新分配的缓存区.
    printf("%c", *ptr_c++);
    打印出读入的字符
    */
