#include <stdio.h>
#include <stdlib.h>

typedef struct _node{
    void *data;
    struct _node *next;
}Node;

typedef struct _linklist{
    Node *head;
    Node *tail;
    Node *current;
}Linklist;

void initLinklist(Linklist *list){
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
}

void addHead(Linklist *list, void *iData){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = iData;

    if(list->head == NULL){
	list->tail = node;
	node->next = NULL;
    }else{
	node->next = list->head;
    }
    list->head = node;

    return;
}

void addTail(Linklist *list, void *iData){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = iData;
    node->next = NULL;

    if(list->head == NULL){
	list->head = node;
    }else{
	list->tail->next = node;
    }
    list->tail = node;

    return 0;
}

void dispLinklist(Linklist *list){
    Node *node = list->head;
    while(node != NUll){
	printf("%d", node->data);
	node = node->next;
    }

    return;
}

int main(int argc, char **argv)
{
    Linklist *list1 = (Linklist *)malloc(Linklist);
}
