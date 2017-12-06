#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *format(char *buffer, size_t size, const char *name, size_t quantify, size_t weight){
    char *formatString = "Item: %s Quantify: %u Weight: %u";
    printf("formatString length: %d\n", strlen(formatString));
    size_t formatStringLength = strlen(formatString) - 6;
    size_t nameLengh = strlen(name);
    size_t length = formatStringLength + nameLengh + 3 + 3 +1;

    if(buffer == NULL){
	buffer = (char *)malloc(length);
	size = length;
    }
    snprintf(buffer, size, formatString, name, quantify, weight);

    return buffer;
}

int main(int argc, char **argv)
{
    char *buffer = NULL;
    unsigned int quan;
    unsigned int weig;

    char name[10];
    printf("please input name:\t");
    scanf("%s", name);
    printf("please input quantify:\t");
    scanf("%u", &quan);
    printf("please input weight:\t");
    scanf("%u", &weig);

    printf("%s\n", format(buffer, sizeof(buffer), name, quan, weig));

    return 0;
}

/*
 * 此题有点方!
 */
