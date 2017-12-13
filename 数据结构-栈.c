#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100


typedef int Status;
/*ջ��˳��ṹ����*/
typedef int SElemType;    /*SElemType���͸���ʵ���������,�������Ϊint*/
typedef struct
{
    SElemType data[MAXSIZE];
    int top;    /*����ջ��ָ��*/
}SqStack;


/*ջ��˳��洢�ṹ-��ջ����*/
/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status Push(SqStack *S, SElemType e)
{
    if(S->top==MAXSIZE-1)    /*ջ��*/
        return ERROR;
    S->top++;    /*ջ��ָ������һ*/
    S->data[S->top]=e;    /*���²���Ԫ�ظ�ֵ��ջ���ռ�*/
    return OK;
}


/*ջ��˳��洢�ṹ-��ջ����*/
/*��ջ����,��ɾ��S��ջ��Ԫ��,��e������ֵ,������OK,���򷵻�ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top==-1)
        return ERROR;
    *e=S->data[S->top];    /*��Ҫɾ����ջ��Ԫ�ظ�ֵ��e*/
    S->top--;    /*ջ��ָ���һ*/
    return OK;
}


/*��ջ����ռ�ṹ*/
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;    /*ջ1ջ��ָ��*/
    int top2;    /*ջ2ջ��ָ��*/
}SqDoubleStack;


/*��ջ����ռ��push����*/
/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status Push2(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if(S->top1+1==S->top2)    /*ջ����,������push��Ԫ��*/
        return ERROR;
    if(stackNumber==1)    /*ջ1��Ԫ�ؽ�ջ*/
        S->data[++S->top1]=e;    /*��ջ1����top1+1�������Ԫ�ظ�ֵ*/
    else if(stackNumber==2)    /*ջ2��Ԫ�ؽ�ջ*/
        S->data[--S->top2]=e;    /*��ջ2����top2-1�������Ԫ�ظ�ֵ*/
    return OK;
}


/*��ջ����ռ��pop����*/
/*��ջ����,��ɾ��S��ջ��Ԫ��,��e������ֵ,������OK,���򷵻�ERROR*/
Status Pop2(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if(stackNumber==1)
    {
        if(S->top1==-1)
            return ERROR;    /*ջ1���ǿ�ջ,���*/
        *e=S->data[S->top1--];    /*��ջ1��ջ��Ԫ�س�ջ*/
    }
    else if(stackNumber==2)
    {
        if(S->top2==-1)
            return ERROR;    /*ջ2���ǿ�ջ,���*/
        *e=S->data[S->top2++];    /*��ջ2��ջ��Ԫ�س�ջ*/
    }
    return OK;
}



/*ջ����ʽ�ṹ����*/
typedef struct StackNode
{
    SElemType data;
    struct StackNode *next;
}StackNode,*LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
}LinkStack;


/*ջ����ʽ�洢�ṹ-��ջ����*/
/*����Ԫ��eΪ�µ�ջ��Ԫ��*/
Status Push3(LinkStack *S, SElemType e)
{
    LinkStackPtr s =(LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    s->next=S->top;    /*�ѵ�ǰ��ջ��Ԫ�ظ�ֵ���½���ֱ�Ӻ��*/
    S->top=s;    /*���½��s��ֵ��ջ��ָ��*/
    S->count++;
    return OK;
}


/*ջ����ʽ�洢�ṹ-��ջ����*/
/*��ջ����,��ɾ��S��ջ��Ԫ��,��e������ֵ,������OK,���򷵻�ERROR*/
Status Pop3(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if(S->top==NULL)
        return ERROR;
    *e=S->top->data;
    p=S->top;    /*��ջ����㸳ֵ��p*/
    S->top=S->top->next;    /*ʹ��ջ��ָ������һλ,ָ���һ���*/
    free(p);    /*�ͷŽ��p*/
    S->count--;
    return OK;
}
