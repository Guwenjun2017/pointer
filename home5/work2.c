#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _person{
    char *firstName;
    char *lastName;
    char *title;
    unsigned int age;
}Person;

void initPerson(Person *person, const char *iFirstname, const char *iLastname, const char *iTitle, unsigned int iAge){
    person->firstName = (char *)malloc(strlen(iFirstname) + 1);
    strcpy(person->firstName, iFirstname);
    person->lastName = (char *)malloc(strlen(iLastname) + 1);
    strcpy(person->lastName, iLastname);
    person->title = (char *)malloc(strlen(iTitle) + 1);
    strcpy(person->title, iTitle);
    person->age = iAge;

    return;
}

void deleteallocPerson(Person *person){
    free(person->firstName);
    free(person->lastName);
    free(person->title);

    return;
}

void dispPerson(Person *person){
    printf("The name %s %s,and title %s, age is %d\n", person->firstName, person->lastName, person->title, person->age);

    return;
}

int main(int argc, char **argv)
{
    Person *person;
    person = (Person *)malloc(sizeof(Person));
    initPerson(person, "zhang", "san", "good", 20);
    dispPerson(person);
    deleteallocPerson(person);
    free(person);

    return 0;
}

/* (1):
 * initPerson()
 * 初始化person:为结构体分配内存,并将数据赋进去.
 *
 * deleteallocPerson()
 * 释放结构体之前,首先要释放结构体内包含的指向动态分配的内存的指针.
 * 否则,会发生内存泄露.
 *
 * dispPerson()
 * 输出数据.
 *
 * (2):
 * 该程序的功能:
 * 声明一个结构体,为其分配合适的内存后,对其进行初始化,然后输入其内容,在释放完它的指向动态分配的内存的指针后,
 * 最后释放它本身的内存.
 *
