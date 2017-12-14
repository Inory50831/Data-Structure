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
/*ѭ�����еĴ洢�ṹ*/
typedef struct
{
    QElemType data[MAXSIZE];
    int front;    /*ͷָ��*/
    int rear;    /*βָ��,�����в���,ָ�����βԪ�ص���һ��λ��*/
}SqQueue;


/*ѭ�����г�ʼ������*/
/*��ʼ��һ���ն���Q*/
Status InitQueue(SqQueue *Q)
{
    Q->front=0;
    Q->rear=0;
    return OK;
}


/*ѭ����������г���*/
/*����Q��Ԫ�ظ���,Ҳ���Ƕ��еĵ�ǰ����*/
int QueueLength(SqQueue Q)
{
    return (Q.rear-Q.front+MAXSIZE)%MAXSIZE;
}


/*ѭ�����е���Ӳ���*/
/*������δ��,�����Ԫ��eΪQ�µĶ�βԪ��*/
Status EnQueue(SqQueue *Q, QElemType e)
{
    if((Q->rear+1)%MAXSIZE==Q->front)    /*���������ж�*/
        return ERROR;
    Q->data[Q->rear]=e;    /*��Ԫ��e��ֵ����β*/
    Q->rear=(Q->rear+1)%MAXSIZE;    /*rearָ�������һλ��,���������ת������ͷ��*/
    return OK;
}


/*ѭ�����еĳ��Ӳ���*/
/*�����в���,��ɾ��Q�ж�ͷԪ��,��e������ֵ*/
Status DeQueue(SqQueue *Q, QElemType *e)
{
    if(Q->front==Q->rear)    /*���пյ��ж�*/
        return ERROR;
    *e=Q->data[Q->front];    /*����ͷԪ�ظ�ֵ��e*/
    Q->front=(Q->front+1)%MAXSIZE;     /*frontָ�������һλ��,���������ת������ͷ��*/
    return OK;
}


/*���е���ʽ�洢�ṹ*/
typedef struct QNode    /*���ṹ*/
{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct    /*���е�����ṹ*/
{
    QueuePtr front,rear;    /*��ͷ,��βָ��*/
}LinkQueue;


/*���е���ʽ�洢�ṹ-��Ӳ���*/
/*����Ԫ��eΪQ���µĶ�βԪ��*/
Status EnQueue1(LinkQueue *Q, QElemType e)
{
    QueuePtr s=(QueuePtr)malloc(sizeof(QNode));
    if(!s)    /*�洢����ʧ��*/
        exit(OVERFLOW);
    s->data=e;
    s->next=NULL;
    Q->rear->next=s;    /*��ӵ��Ԫ��e�½��s��ֵ��ԭ��β���ĺ��*/
    Q->rear=s;    /*�ѵ�ǰ��s����Ϊ��β���,rearָ��s*/
    return OK;
}


/*���е���ʽ�洢�ṹ-���Ӳ���*/
/*�����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������OK,���򷵻�ERROR*/
Status DeQueue1(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if(Q->front==Q->rear)
        return ERROR;
    p=Q->front->next;    /*����ɾ���Ķ�ͷ����ݴ��p*/
    *e=p->data;    /*����ɾ���Ķ�ͷ����ֵ��ֵ��e*/
    Q->front->next=p->next;    /*��ԭ��ͷ�����p->next��ֵ��ͷ�����*/
    if(Q->rear==p)     /*����ͷ�Ƕ�β,��ɾ����rearָ��ͷ���*/
        Q->rear=Q->front;
    free(p);
    return OK;
}
