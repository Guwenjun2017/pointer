#include<stdio.h>


int main(int argc, char **argv)
{
    char *buffer = NULL;

    char *format(char *buffer, size_t size, const char *name, size_t quantity, size_t weight){
	snprintf(buffer, size, "Item: %s Quantity: %u Weight: %u",
		name, quantity, weight);
	
	return buffer;
    }
    
    printf("%s\n", format(buffer, sizeof(buffer), "Axle", 25, 45));
}
