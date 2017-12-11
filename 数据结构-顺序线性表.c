#include <stdio.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20    /*存储空间初始分配量*/


/*线性表顺序存储结构*/
typedef int ElemType;    /*ElemType类型根据实际情况而定*/
typedef int Status;    /*Status是函数的类型,其值是函数结果状态代码,如OK等*/
typedef struct
{
    ElemType data[MAXSIZE];    /*数组存储数据元素,最大值为MAXSIZE*/
    int length;
}SqList;


/*GetElem  获得元素操作*/
/*初始条件:顺序线性表L已存在,1<=i<=ListLength(L)*/
/*操作结果:用e返回L中第i个数据元素的值*/
Status GetElem(SqList L,int i,ElemType *e)
{
    if(L.length==0 || i<1 || i>L.length)
        return ERROR;
    *e=L.data[i-1];
    return OK;
}


/*ListInsert  插入操作*/
/*初始条件:顺序线性表L已存在,1<=i<=ListLength(L)*/
/*操作结果:在L中第i个位置之前插入新的数据元素e,L的长度加1*/
Status ListInsert(SqList *L,int i,ElemType e)
{
    int k;
    if(L->length==MAXSIZE)    /*顺序线性表已满*/
        return ERROR;
    if(i<1 || i>L->length+1)    /*当i不再范围内时*/
        return ERROR;
    if(i<=L->length)    /*若插入数据位置不在表尾*/
    {
        for(k=L->length-1;k>=i-1;k--)    /*将要插入位置后数据元素向后移动一位*/
            L->data[k+1]=L-data[k];
    }
    L->data[i-1]=e;    /*将新元素插入*/
    return OK;
}


/*ListDelete  删除操作*/
/*初始条件:顺序线性表L已存在,1<=i<=ListLength(L)*/
/*操作结果:删除L的第i个数据元素,并用e返回其值,L的长度减1*/
Status ListDelete(SqList *L,int i,ElemType *e)
{
    int k;
    if(L->length==0)    /*线性表为空*/
        return ERROR;
    if(i<1 || i>L->length)    /*删除位置不正确*/
        return ERROR;
    *e=L->data[i-1];
    if(i<L->length)
    {
        for(k=i;k<L->length;k++)    /*将删除位置后继元素前移*/
            L->data[k-1]=L->data[k];
    }
    L->length--;
    return OK;
}


/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void UnionL(SqList *La,SqList Lb)
{
    int La_len,Lb_len,i;
    ElemType e;    /*声明与La和Lb相同的数据元素e*/
    La_len = ListLength(*La);    /*求线性表的长度*/
    Lb_len = ListLength(Lb);
    for(i=1; i<=Lb_len; i++)
    {
        GetElem(Lb, i, &e);    /*取Lb中第i个数据元素赋给e*/
        if(!LocateElem(*La,e))    /*La中不存在和e相同数据元素*/
            ListInsert(La, ++La_len, e);    /*插入*/
    }
}

