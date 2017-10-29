#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DataType int

//定义节点
typedef struct _node{
    DataType data;
    struct _node *next;
}Node;

//定义链表
typedef struct _linklist{
    Node *head;
    Node *tail;
    Node *current;
}Linklist;

//初始化链表
void initLinklist(Linklist *list){
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    return;
}

//头插法
void addHead(Linklist *list, DataType iData){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = iData;

    if(list->head == NULL){
	list->tail = node;
	node->next = NULL;
    }else
	node->next = list->head;
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
    }else
	list->tail->next = node;
    list->tail = node;

    return;
}

//输出链表
void dispLinklist(Linklist *list){
    Node *node = list->head; 
    while(node != NULL){
	printf("%d\t", node->data);
	node = node->next;
    }
    printf("\n");

    return;
}

//比较节点数据
int compare(DataType iData1, DataType iData2){
    if(iData1 > iData2){
	return 1;
    }else if(iData1 = iData2){
	return 0;
    }else
	return -1;
}
typedef int(*COMPARE)(DataType, DataType);

//返回带指定数据的节点地址
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

void delete(Linklist *list, Node *node){
    if(node == list->head){
	if(list->head->next == NULL) {
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

    return;
}

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
    delete(list1, node);
    dispLinklist(list1);

    return 0;
}


