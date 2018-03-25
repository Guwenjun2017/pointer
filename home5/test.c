#include<stdio.h>
#include<stdlib.h>
#define DataType int

//定义节点
typedef struct _node{
    DataType data;
    struct _node *next;
}Node;

//定义链表
typedef struct _linkedList{
    Node *head;
    Node *tail;
    Node *current;
}linkedList;

//链表初始化
void initlinkedList(linkedList *list){
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    return;
}

//头插
void addHead(linkedList *list, DataType iData){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = iData;
    node->next = NULL;

    // == 为相等符号!!!
    if(list->head == NULL){
	list->tail = node;
    }else{
	node->next = list->head;
    }

    list->head = node;
    return;
}

//尾插
void addTail(linkedList *list, DataType iData){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = iData;
    node->next = NULL;

    if(list->head == NULL){
	list->head = node;
    }else{
	list->tail->next = node;
    }

    list->tail = node;
    return;
}

//比较节点数据
int compare(DataType iData0, DataType iData1){
    if(iData0 > iData1)
	return 1;
    else if(iData0 == iData1)
	return 0;
    else 
	return -1;
}

//定义函数指针
typedef int (*fptr)(DataType, DataType);

//返回含指定数据的节点的指针
Node *getNode(linkedList *list, DataType iData, fptr compare){
    Node *node = list->head;
    while(node != NULL){
	if(compare(node->data, iData) == 0)
	    return node;
	node = node->next;
    }

    return NULL;
}

//删除指定节点
void deleteNode(linkedList *list, Node *node){
    if(node == list->head){
	if(list->head->next == NULL){
	    list->head = list->tail = NULL;
	}else{
	    list->head = list->head->next;
	}
    }else{
	Node *tmp = list->head;
	while(tmp != NULL && tmp->next != node){
	    tmp = tmp->next;
	}
	if(tmp != NULL){
	    tmp->next = node->next;
	}
    }

    free(node);
}

void displaylinkedList(linkedList *list){
    Node *node = list->head;
    while(node != NULL){
	printf("%d\t", node->data);
	node = node->next;
    }
    printf("\n");

    return;
}

int main(int argc, char ** argv)
{
    linkedList *list = (linkedList *)malloc(sizeof(linkedList));
    initlinkedList(list);
    addHead(list, 1);
    addHead(list, 3);
    addHead(list, 5);
    addHead(list, 7);
    addHead(list, 9);
    displaylinkedList(list);

    addTail(list, 2);
    addTail(list, 4);
    addTail(list, 6);
    addTail(list, 8);
    addTail(list, 10);
    displaylinkedList(list);

    printf("删除数据域为8的结点后打印:\n");
    Node *tmp_node = getNode(list, 8, compare);
    deleteNode(list, tmp_node);
    displaylinkedList(list);
}
