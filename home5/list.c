#include <stdio.h>
#include "list.h"

//初始化链表
void initLinklist(Linklist *list){
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

//头插法
void addHead(Linklist *list, DataType iData){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = iData;
    node->next = NULL;

    if(list->head == NULL){
	list->tail = node;
    }else{
	node->next = list->head;
    }
    list->head = node;

    return;
}

//尾插法
void addTail(Linklist *list, DataType iData){
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
typedef int(*COMPARE)(DataType, DataType);

//返回含指定数据的节点的指针
Node *getNode(Linklist *list, DataType iData, COMPARE compare){
    Node *node = list->head;
    while(node != NULL){
	if(compare(node->data, iData) == 0){
	    return node;
	}
	node = node->next;
    }

    return NULL;
}

//删除指定节点
void deleteNode(Linklist *list, Node *node){
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

//打印链表
void dispLinklist(Linklist *list){
    Node *node = list->head;
    while(node != NULL){
	printf("%d\t", node->data);
	node = node->next;
    }
    printf("\n");

    return;
}
