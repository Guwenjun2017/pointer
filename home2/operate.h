#ifndef operate_h
#define operate_h

typedef int (*fptrOperation)(int, int);

int add(int , int );

int sub(int , int );

int mul(int , int );

int div(int , int );

int quyu(int , int );

//获取运算符
fptrOperation select(char );

int evaluate(char , int , int );

#endif

