#include <stdio.h>

typedef struct _node{
    int data;
    struct _node *next;
}Node;

typedef struct _list{
    Node *head;
    Node *tail;
    Node *current;
}List;

void initList(List *list){
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void addHead(List *list, int iData){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = iData;
    node->next = NULL;

    if(list->head = NULL){
	list-tail = node;
    }else{
	node->next = list->head;
    }
    list->head = node;
}

void addTail(List *list, int iData){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = iData;
    node->next = NULL;

    if(list->head = NULL){
	list->head = node;
    }else{
	list->tail->next = node; 
    }
    list->tail = node;
}

void delete(Link *List, Node *node){
    if(node == list->head){
	if(list->head->next == NULL){
	    list->head = list->tail = NULL;
	}else{
	    list->head = list->head->next;
	}
    }else {
	Node *tmp = list->head;
	while (tmp != NULL && tmp->next != node){
	    tmp
	}
    }
}












