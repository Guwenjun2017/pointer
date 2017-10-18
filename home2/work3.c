/* *========* *** *============================================== 
  * 联络信箱: *** :guwenjun2017@gmail.com
  * 文档用途: *** :CII实验报告
  * 修订时间: *** *2017年第41周 10月15日 星期日 下午11:06 (288天)
 * *========* *** *============================================== */
#include <stdio.h>

int main(int argc, char **argv)
{
    int num1;
    int num2;
    typedef int (*fptrOperation)(int, int);

    printf("请输入两个整型数[逗号隔开]:");
    scanf("%d,%d", &num1, &num2);
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

    printf("+: %d\n",evaluate('+', num1, num2));
    printf("-: %d\n",evaluate('-', num1, num2));
    printf("*: %d\n",evaluate('*', num1, num2));
    printf("/: %d\n",evaluate('/', num1, num2));
    printf("%%: %d\n",evaluate('%', num1, num2));

    return 0;
}
