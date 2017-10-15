#include <stdio.h>

int main(int argc, char **argv)
{
    int add(int num, int num1) {
	return num + num1;
    }
    int sub(int num, int num1) {
	return num - num1;
    }

    typedef int (*fptrOperation)(int, int);

    fptrOperation select(char opcode) {
	switch(opcode){
	    case '+':
		return add;
		break;

	    case '-':
		return sub;
		break;
	    default:
		;
	}
    }

    int evaluate(char opcode, int num1, int num2){
	fptrOperation operation = select(opcode);
	return operation(num1, num2);
    }

    printf("%d\n", evaluate('+', 6, 5));
    printf("%d\n", evaluate('-', 6, 5));

    return 0;
}
