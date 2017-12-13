#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 100


typedef int Status;
/*栈的顺序结构定义*/
typedef int SElemType;    /*SElemType类型根据实际情况而定,这里假设为int*/
typedef struct
{
    SElemType data[MAXSIZE];
    int top;    /*用于栈顶指针*/
}SqStack;


/*栈的顺序存储结构-进栈操作*/
/*插入元素e为新的栈顶元素*/
Status Push(SqStack *S, SElemType e)
{
    if(S->top==MAXSIZE-1)    /*栈满*/
        return ERROR;
    S->top++;    /*栈顶指针增加一*/
    S->data[S->top]=e;    /*将新插入元素赋值给栈顶空间*/
    return OK;
}


/*栈的顺序存储结构-出栈操作*/
/*若栈不空,则删除S的栈顶元素,用e返回其值,并返回OK,否则返回ERROR*/
Status Pop(SqStack *S, SElemType *e)
{
    if(S->top==-1)
        return ERROR;
    *e=S->data[S->top];    /*将要删除的栈顶元素赋值给e*/
    S->top--;    /*栈顶指针减一*/
    return OK;
}


/*两栈共享空间结构*/
typedef struct
{
    SElemType data[MAXSIZE];
    int top1;    /*栈1栈顶指针*/
    int top2;    /*栈2栈顶指针*/
}SqDoubleStack;


/*两栈共享空间的push方法*/
/*插入元素e为新的栈顶元素*/
Status Push2(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if(S->top1+1==S->top2)    /*栈已满,不能再push新元素*/
        return ERROR;
    if(stackNumber==1)    /*栈1有元素进栈*/
        S->data[++S->top1]=e;    /*若栈1则先top1+1后给数组元素赋值*/
    else if(stackNumber==2)    /*栈2有元素进栈*/
        S->data[--S->top2]=e;    /*若栈2则先top2-1后给数组元素赋值*/
    return OK;
}


/*两栈共享空间的pop方法*/
/*若栈不空,则删除S的栈顶元素,用e返回其值,并返回OK,否则返回ERROR*/
Status Pop2(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if(stackNumber==1)
    {
        if(S->top1==-1)
            return ERROR;    /*栈1已是空栈,溢出*/
        *e=S->data[S->top1--];    /*将栈1的栈顶元素出栈*/
    }
    else if(stackNumber==2)
    {
        if(S->top2==-1)
            return ERROR;    /*栈2已是空栈,溢出*/
        *e=S->data[S->top2++];    /*将栈2的栈顶元素出栈*/
    }
    return OK;
}



/*栈的链式结构定义*/
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


/*栈的链式存储结构-进栈操作*/
/*插入元素e为新的栈顶元素*/
Status Push3(LinkStack *S, SElemType e)
{
    LinkStackPtr s =(LinkStackPtr)malloc(sizeof(StackNode));
    s->data=e;
    s->next=S->top;    /*把当前的栈顶元素赋值给新结点的直接后继*/
    S->top=s;    /*将新结点s赋值给栈顶指针*/
    S->count++;
    return OK;
}


/*栈的链式存储结构-出栈操作*/
/*若栈不空,则删除S的栈顶元素,用e返回其值,并返回OK,否则返回ERROR*/
Status Pop3(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if(S->top==NULL)
        return ERROR;
    *e=S->top->data;
    p=S->top;    /*将栈顶结点赋值给p*/
    S->top=S->top->next;    /*使得栈顶指针下移一位,指向后一结点*/
    free(p);    /*释放结点p*/
    S->count--;
    return OK;
}
