#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -1
#define MAXSIZE 100


typedef int Status;
typedef int QElemType;
/*循环队列的存储结构*/
typedef struct
{
    QElemType data[MAXSIZE];
    int front;    /*头指针*/
    int rear;    /*尾指针,若队列不空,指向队列尾元素的下一个位置*/
}SqQueue;


/*循环队列初始化操作*/
/*初始化一个空队列Q*/
Status InitQueue(SqQueue *Q)
{
    Q->front=0;
    Q->rear=0;
    return OK;
}


/*循环队列求队列长度*/
/*返回Q的元素个数,也就是队列的当前长度*/
int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}


/*循环队列的入队操作*/
/*若队列未满,则插入元素e为Q新的队尾元素*/
Status EnQueue(SqQueue *Q, QElemType e)
{
    if((Q->rear+1)%MAXSIZE==Q->front)    /*队列满的判断*/
        return ERROR;
    Q->data[Q->rear]=e;    /*将元素e赋值给队尾*/
    Q->rear=(Q->rear+1)%MAXSIZE;    /*rear指针向后移一位置,若到最后则转到数组头部*/
    return OK;
}


/*循环队列的出队操作*/
/*若队列不空,则删除Q中队头元素,用e返回其值*/
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if(Q->front==Q->rear)    /*队列空的判断*/
        return ERROR;
    *e=Q->data[Q->front];    /*将队头元素赋值给e*/
    Q->front=(Q->front+1)%MAXSIZE;     /*front指针向后移一位置,若到最后则转到数组头部*/
    return OK;
}


/*队列的链式存储结构*/
typedef struct QNode    /*结点结构*/
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct    /*队列的链表结构*/
{
    QueuePtr front,rear;    /*队头,队尾指针*/
}LinkQueue;


/*队列的链式存储结构-入队操作*/
/*插入元素e为Q的新的队尾元素*/
Status EnQueue1(LinkQueue *Q, QElemType e)
{
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if(!s)    /*存储分配失败*/
        exit(OVERFLOW);
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;    /*把拥有元素e新结点s赋值给原队尾结点的后继*/
    Q->rear=s;    /*把当前的s设置为队尾结点,rear指向s*/
    return OK;
}


/*队列的链式存储结构-出队操作*/
/*若队列不空,删除Q的队头元素,用e返回其值,并返回OK,否则返回ERROR*/
Status DeQueue1(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;    /*将欲删除的队头结点暂存给p*/
    *e=p->data;    /*将欲删除的队头结点的值赋值给e*/
    Q->front->next=p->next;    /*将原队头结点后继p->next赋值给头结点后继*/
    if(Q->rear==p)     /*若队头是队尾,则删除后将rear指向头结点*/
        Q->rear=Q->front;
    free(p);
    return OK;
}
