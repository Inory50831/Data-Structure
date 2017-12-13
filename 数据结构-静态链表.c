#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 1000


typedef int ElemType;    /*ElemType���͸���ʵ���������*/
typedef int Status;    /*Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK��*/
/*���Ա�ľ�̬����洢�ṹ*/
typedef struct
{
    ElemType data;
    int cur;    /*�α�(Cursor),Ϊ0ʱ��ʾ��ָ��*/
} Component,StaticLinkList[MAXSIZE];


/*��һ��һλ����space�и���������һ��������*/
/*space[0].curΪͷָ��,"0"��ʾ��ָ��*/
Status InitList(StaticLinkList space)
{
    int i;
    for(i=0; i<MAXSIZE-1; i++)
        space[i].cur = i+1;
    space[MAXSIZE-1].cur = 0;    /*Ŀǰ��̬����Ϊ��,���һ��Ԫ�ص�curΪ0*/
    return OK;
}


/*��̬�����Ԫ�ظ�����ȡ����*/
/*��ʼ����:��̬����L�Ѵ���*/
/*�������:����L������Ԫ�ظ���*/
int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE-1].cur;
    while(i)
    {
        i=L[i].cur;
        j++;
    }
    return j;
}

/*��̬����ı�����������*/
/*�����ÿռ�����ǿ�,�򷵻ط���Ľ���±�,���򷵻�0*/
int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;    /*��ǰ�����һ��Ԫ�ص�cur���ֵ*/
                             /*���ص�һ�����ÿ��е��±�*/
    if(space[0].cur)
        space[0].cur = space[i].cur;    /*�ó�һ������ʹ�ú�,��������һ����������������*/
    return i;
}


/*��̬����ı����������*/
/*���±�Ϊk�Ŀ��нڵ���յ���������*/
void Free_SSL(StaticLinkList space, int k)
{
    space[k].cur = space[0].cur;    /*�ѵ�һ��Ԫ��curֵ����Ҫɾ���ķ���cur*/
    space[0].cur = k;    /*��Ҫɾ���ķ����±긳ֵ����һ��Ԫ�ص�cur*/
}

/*��̬����Ĳ������*/
/*��L�е�i��Ԫ��֮ǰ�����µ�����Ԫ��e*/
Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1;    /*k���������һ��Ԫ�ص��±�*/
    if(i<1 || i>ListLength(L)+1)
        return ERROR;
    j = Malloc_SLL(L);    /*��ÿ��з������±�*/
    if(j)
    {
        L[j].data = e;    /*�����ݸ�ֵ���˷�����data*/
        for(l=1; l<=i-1; i++)    /*�ҵ���i��Ԫ��֮ǰ��λ��*/
            k = L[k].cur;
        L[j].cur = L[k].cur;    /*�ѵ�i��Ԫ��֮ǰ��curֵ��ֵ����Ԫ�ص�cur*/
        L[k].cur = j;    /*����Ԫ�ص��±긳ֵ����i��Ԫ��֮ǰԪ�ص�cur*/
        return OK;
    }
    return ERROR;
}


/*��̬�����ɾ������*/
/*ɾ����L�е�i������Ԫ��e*/
Status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    if(i<1 ||i>ListLength(L))
        return ERROR;
    k = MAXSIZE - 1;
    for(j=1; j<=i-1; j++)
        k = L[k].cur;
    j = L[k].cur;
    L[k].cur = L[j].cur;
    Free_SSL(L, j);
    return OK;
}
