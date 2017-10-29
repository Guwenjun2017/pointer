/* *========* *** *============================================== 
  * 联络信箱: *** :guwenjun2017@gmail.com
  * 文档用途: *** :CII实验报告
  * 文档笔记: *** :审慎的重复!!!
  * 修订时间: *** *2017年第43周 10月29日 星期日 下午04:04 (302天)
 * *========* *** *============================================== */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv)
{
    Linklist *list1 = (Linklist *)malloc(sizeof(Linklist));
    Linklist *list2 = (Linklist *)malloc(sizeof(Linklist));
    addHead(list1, 1);
    addHead(list1, 3);
    addHead(list1, 5);
    addHead(list1, 7);
    addHead(list1, 9);
    Node *node = getNode(list1, 3, compare);
    deleteNode(list1, node);
    dispLinklist(list1);

    addTail(list2, 1);
    addTail(list2, 3);
    addTail(list2, 5);
    addTail(list2, 7);
    addTail(list2, 9);
    dispLinklist(list2);

    free(list1);
    free(list2);
    return 0;
}
