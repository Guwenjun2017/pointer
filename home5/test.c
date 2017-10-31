#include <stdio.h>
#include <stdlib.h>
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
void initialLinklist(Linklist *list){
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;

    return;
}

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

int compare(DataType iData0, DataType iData1){
    if(iData0 > iData1)
	return 1;
    else if(iData0 == iData1)
	return 0;
    else
	return -1;
}
typedef int(*COMPARE)(DataType, DataType);

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
    //第一步判断要删除的节点是否是链表头
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

    return;
}

void display(Linklist *list){
    Node *node = list->head;
    while(node != NULL){
	printf("%d\t", node->data);
	node = node->next;
    }
    printf("\n");
}

int main(int argc, char **argv)
{
    Linklist *list = (Linklist *)malloc(sizeof(Linklist));

    initialLinklist(list);
    addHead(list, 1);
    addHead(list, 3);
    addHead(list, 5);
    addHead(list, 7);
    addHead(list, 9);
    Node *node = getNode(list, 3, compare);
    delete(list, node);
    display(list);

    return 0;
}
