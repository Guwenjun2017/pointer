#ifndef list_h
#define list_h
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

void initLinklist(Linklist *);

void addHead(Linklist *, DataType);

void addTail(Linklist *, DataType);

int compare(DataType, DataType);

typedef int(*COMPARE)(DataType, DataType);

Node *getNode(Linklist *, DataType, COMPARE);

void deleteNode(Linklist *, Node *);

void dispLinklist(Linklist *);

#endif
