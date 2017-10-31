/* *========* *** *============================================== 
  * 联络信箱: *** :guwenjun2017@gmail.com
  * 文档用途: *** :CII实验报告
  * 文档笔记: *** :审慎的重复!!!
  * 修订时间: *** *2017年第44周 11月01日 星期三 上午12:31 (305天)
 * *========* *** *============================================== */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(int argc, char **argv)
{
    Linklist *list1 = (Linklist *)malloc(sizeof(Linklist));
    initLinklist(list1);
    addHead(list1, 1);
    addHead(list1, 3);
    addHead(list1, 5);
    addHead(list1, 7);
    addHead(list1, 9);
    Node *node = getNode(list1, 3, compare);
    deleteNode(list1, node);
    dispLinklist(list1);

    addTail(list1, 0);
    addTail(list1, 2);
    addTail(list1, 4);
    addTail(list1, 6);
    addTail(list1, 8);
    dispLinklist(list1);
    Node *node1 = getNode(list1, 4, compare);
    deleteNode(list1, node1);
    dispLinklist(list1);

    free(list1);
    return 0;
}
