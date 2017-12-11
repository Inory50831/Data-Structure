#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20


/*���Ա�ĵ�����洢�ṹ*/
typedef int ElemType;    /*ElemType���͸���ʵ���������*/
typedef int Status;    /*Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK��*/
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;
typedef struct Node *LinkList;    /*����LinkList*/


/*GetElem  ������Ķ�ȡ*/
/*��ʼ����:˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)*/
/*�������:��e����L�е�i������Ԫ�ص�ֵ*/
Status GetElem(LinkList L,int i,ElemType *e)
{
    int j;
    LinkList p;    /*����һָ��p*/
    p = L->next;    /*��pָ������L�ĵ�һ�����*/
    j = 1;    /*jΪ������*/
    while(p && j<i)    /*p��Ϊ���Ҽ�����j��û�е���iʱ,ѭ������*/
    {
        p = p->next;    /*��pָ����һ�����*/
        ++j;
    }
    if(!p || j>i)    /*��i����㲻����*/
        return ERROR;
    *e = p->data;    /*ȡ��i����������*/
    return OK;
}


/*ListInsert  ���������*/
/*��ʼ����:˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)*/
/*�������:��L�е�i�����λ��֮ǰ�����µ�����Ԫ��e,L�ĳ�������1*/
Status ListInsert(LinkList L,int i,ElemType e)
{
    int j;
    LinkList p,s;
    p = *L;
    j = 1;
    while(p && j<i)    /*Ѱ�ҵ�i-1�����*/
    {
        p = p->next;
        ++j;
    }
    if(!p || j>i)
        return ERROR;    /*��i����㲻����*/
    s = (LinkList)malloc(sizeof(Node));    /*�����½��*/
    s->data = e;
    s->next = p->next;    /*��p�ĺ�̽�㸳ֵ��s�ĺ��*/
    p->next = s;    /*��s��ֵ��p�ĺ��*/
    return OK;
}


/*LinkDelete  ������ɾ��*/
/*��ʼ����:˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)*/
/*�������:ɾ��L�ĵ�i�����,����e������ֵ,L�ĳ��ȼ�1*/
Status ListDelete(LinkList *L,int i,ElemType *e)
{
    int j;
    LinkList p,q;
    p = *L;
    j = 1;
    while(p && j<i)    /*Ѱ�ҵ�i-1�����*/
    {
        p = p->next;
        ++j;
    }
    if(!(p->next) || j > i)
        return ERROR;    /*��i����㲻����*/
    q = p->next;
    p->next = q->next;    /*��q�ĺ�̸�ֵ��p�ĺ��*/
    *e = q->data;    /*��q�ڵ������ݸ�e*/
    free(q);    /*��ϵͳ���մ˽��,�ͷ��ڴ�*/
    return OK;
}


/*����������Ĵ���*/
/*�������n��Ԫ�ص�ֵ,������ͷ���ĵ������Ա�L(ͷ�巨)*/
void CreateListHead(LinkList *L, int n)
{
    LinkList p;
    int i;
    srand(time(0));    /*��ʼ�����������*/
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;    /*�Ƚ���һ����ͷ���ĵ�����*/
    for(i=0; i<n; i++)
    {
        p = (LinkList)malloc(sizeof(Node));    /*�����½��*/
        p->data = rand()%100+1;    /*�������100���ڵ�����*/
        p->next = (*L)->next;
        (*L)->next = p;    /*���뵽��ͷ*/
    }
}

/*�������n��Ԫ�ص�ֵ,������ͷ���ĵ������Ա�L(β�巨)*/
void CreateListTail(LinkList *L, int n)
{
    LinkList p,r;
    int i;
    srand(time(0));    /*��ʼ�����������*/
    *L = (LinkList)malloc(sizeof(Node));    /*Ϊ�������Ա�*/
    r = *L;    /*rΪָ��β���Ľ��*/
    for(i=0; i<n; i++)
    {
        p = (Node *)malloc(sizeof(Node));    /*�����½��*/
        p->data = rand()%100+1;    /*�������100���ڵ�����*/
        r->next = p;    /*����β�ն˽���ָ��ָ���½��*/
        r = p;    /*����ǰ���½�㶨��Ϊ��β�ն˽��*/
    }
    r->next = NULL;    /*��ʾ��ǰ�������*/
}


/*�����������ɾ��*/
/*��ʼ����:˳�����Ա�L�Ѵ���*/
/*�������:��L����Ϊ�ձ�*/
Status ClearList(LinkList *L)
{
    LinkList p,q;
    p = (*L)->next;    /*pָ���һ�����*/
    while(p)    /*û����β*/
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;    /*ͷ���ָ��Ϊ��*/
    return OK;
}
