#include "operate.h"

int add(int num1, int num2) {
    return num1 + num2;
}
int sub(int num1, int num2) {
    return num1 - num2;
}
int mul(int num1, int num2) {
    return num1 * num2;
}
int div(int num1, int num2) {
    return num1 / num2;
}
int quyu(int num1, int num2) {
    return num1 % num2;
}

fptrOperation select(char opcode) {
    switch(opcode){
	case '+':
	    return add;
	    break;

	case '-':
	    return sub;
	    break;

	case '*':
	    return mul;
	    break;

	case '/':
	    return div;
	    break;

	case '%':
	    return quyu;
	    break;
    }
}

//返回函数指针
int evaluate(char opcode, int num1, int num2) {
    fptrOperation operation = select(opcode);
    return operation(num1, num2);
}


