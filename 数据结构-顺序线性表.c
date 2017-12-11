#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20    /*�洢�ռ��ʼ������*/


/*���Ա�˳��洢�ṹ*/
typedef int ElemType;    /*ElemType���͸���ʵ���������*/
typedef int Status;    /*Status�Ǻ���������,��ֵ�Ǻ������״̬����,��OK��*/
typedef struct
{
    ElemType data[MAXSIZE];    /*����洢����Ԫ��,���ֵΪMAXSIZE*/
    int length;
}SqList;


/*GetElem  ���Ԫ�ز���*/
/*��ʼ����:˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)*/
/*�������:��e����L�е�i������Ԫ�ص�ֵ*/
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
        return ERROR;
    *e=L.data[i-1];
    return OK;
}


/*ListInsert  �������*/
/*��ʼ����:˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)*/
/*�������:��L�е�i��λ��֮ǰ�����µ�����Ԫ��e,L�ĳ��ȼ�1*/
Status ListInsert(SqList *L,int i,ElemType e)
{
    int k;
    if(L->length==MAXSIZE)    /*˳�����Ա�����*/
        return ERROR;
    if(i<1 || i>L->length+1)    /*��i���ٷ�Χ��ʱ*/
        return ERROR;
    if(i<=L->length)    /*����������λ�ò��ڱ�β*/
    {
        for(k=L->length-1;k>=i-1;k--)    /*��Ҫ����λ�ú�����Ԫ������ƶ�һλ*/
            L->data[k+1]=L-data[k];
    }
    L->data[i-1]=e;    /*����Ԫ�ز���*/
    return OK;
}


/*ListDelete  ɾ������*/
/*��ʼ����:˳�����Ա�L�Ѵ���,1<=i<=ListLength(L)*/
/*�������:ɾ��L�ĵ�i������Ԫ��,����e������ֵ,L�ĳ��ȼ�1*/
Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if(L->length==0)    /*���Ա�Ϊ��*/
        return ERROR;
    if(i<1 || i>L->length)    /*ɾ��λ�ò���ȷ*/
        return ERROR;
    *e=L->data[i-1];
    if(i<L->length)
    {
        for(k=i;k<L->length;k++)    /*��ɾ��λ�ú��Ԫ��ǰ��*/
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}


/*�����е������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��*/
void UnionL(SqList *La,SqList Lb)
{
    int La_len,Lb_len,i;
    ElemType e;    /*������La��Lb��ͬ������Ԫ��e*/
    La_len = ListLength(*La);    /*�����Ա�ĳ���*/
    Lb_len = ListLength(Lb);
    for(i=1; i<=Lb_len; i++)
    {
        GetElem(Lb, i, &e);    /*ȡLb�е�i������Ԫ�ظ���e*/
        if(!LocateElem(*La,e))    /*La�в����ں�e��ͬ����Ԫ��*/
            ListInsert(La, ++La_len, e);    /*����*/
    }
}

