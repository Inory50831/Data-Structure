/*˳����ҵ��㷨ʵ��*/
/*˳�����,aΪ����,nΪҪ���ҵ����鳤��,keyΪҪ���ҵĹؼ���*/
int Sequential_Search(int *a,int n,int key)
{
    int i;
    for(i=1;i<=n;i++)
    {
        if(a[i]==key)
            return i;
    }
    return 0;
}

/*���ڱ�˳�����*/
int Sequential_Search2(int *a,int n,int key)
{
    int i;
    a[0]=key;    /*����a[0]Ϊ�ؼ���ֵ,��֮Ϊ"�ڱ�"*/
    i=n;    /*ѭ��������β����ʼ*/
    while(a[i]!=key)
    {
        i--;
    }
    return i;    /*����0��˵������ʧ��*/
}


/*�۰����*/
int Binary_Search(int *a,int n,int key)
{
    int low,high,mid;
    low=1;    /*��������±�Ϊ��¼��λ*/
    high=n;    /*��������±�Ϊ��¼ĩλ*/
    while(low<=high)
    {
        mid=(low+high)/2;    /*�۰�*/
        if(key<a[mid])    /*������ֵ����ֵС*/
            high=mid-1;    /*����±��������λ�±�Сһλ*/
        else if(key>a[mid])    /*������ֵ����ֵ��*/
            low=mid+1;    /*����±����������λ�±��һλ*/
        else
            return mid;    /*�������˵��mid��Ϊ���ҵ���λ��*/
    }
    return 0;
}

/*��ֵ����*/
int Interpolation_Search(int *a,int n,int key)
{
    int low,high,mid;
    low=1;    /*��������±�Ϊ��¼��λ*/
    high=n;    /*��������±�Ϊ��¼ĩλ*/
    while(low<=high)
    {
        mid=low+(high-low)*(key-a[low])/(a[high]-a[low]);    /*��ֵ*/
        if(key<a[mid])    /*������ֵ�Ȳ�ֵС*/
            high=mid-1;    /*����±��������ֵ�±�Сһλ*/
        else if(key>a[mid])    /*������ֵ�Ȳ�ֵ��*/
            low=mid+1;    /*����±�������Ȳ�ֵ�±��һλ*/
        else
            return mid;    /*�������˵��mid��Ϊ���ҵ���λ��*/
    }
    return 0;
}


/*쳲���������*/
int Fibonacci_Search(int *a,int n,int key)
{
    int low,high,mid,i,k;
    low=1;    /*��������±�Ϊ��¼��λ*/
    high=n;    /*��������±�Ϊ��¼ĩλ*/
    k=0;
    while(n>F[k]-1)    /*����nλ��쳲��������е�λ��*/
        k++;
    for(i=n;i<F[k]-1;i++)    /*����������ֵ��ȫ*/
        a[i]=a[n];

    while(low<=high)
    {
        mid=low+F[k-1]-1;    /*���㵱ǰ�ָ����±�*/
        if(key<a[mid])    /*�����Ҽ�¼С�ڵ�ǰ�ָ���¼*/
        {
            high=mid-1;    /*����±�������ָ��±�mid-1��*/
            k=k-1;    /*쳲����������±��һλ*/
        }
        else if(key>a[mid])    /*�����Ҽ�¼���ڵ�ǰ�ָ���¼*/
        {
            low=mid+1;    /*����±�������ָ��±�mid+1��*/
            k=k-2;    /*쳲����������±����λ*/
        }
        else
        {
            if(mid<=n)
                return mid;    /*�������˵��mid��Ϊ���ҵ���λ��*/
            else
                return n;    /*��mid>n˵���ǲ�ȫ��ֵ,����n*/
        }
    }
    return 0;
}


/*�������Ķ���������ṹ����*/
typedef struct BiTNode    /*���ṹ*/
{
    int data;    /*�������*/
    struct BiTNode *lchild,*lchild;    /*���Һ���ָ��*/
} BiTNode, *BiTree;

/*�ݹ���Ҷ���������T���Ƿ����key*/
/*ָ��fָ��T��˫��,���ʼ����ֵΪNULL*/
/*�����ҳɹ�,��ָ��pָ�������Ԫ�ؽ��,������TRUE*/
/*����ָ��pָ�����·���Ϸ��ʵ����һ����㲢����FALSE*/
Status SearchBST(BiTree T,int key,BiTree f,BiTree *p)
{
    if(!T)    /*���Ҳ��ɹ�*/
    {
        *p=f;
        return FALSE;
    }
    else if(key==T->data)    /*���ҳɹ�*/
    {
        *p=T;
        return TRUE;
    }
    else if(key<T->data)
        return SearchBTS(T->lchild,key,T,p);    /*����������������*/
    else
        return SearchBTS(T->rchild,key,T,p);    /*����������������*/
}

/*������������T�в����ڹؼ��ֵ���key������Ԫ��ʱ*/
/*����key������TRUE,���򷵻�FALSE*/
Status InsertBST(BiTree *T,int key)
{
    BiTree p,s;
    if(!SearchBTS(*T,key,NULL,&p))    /*���Ҳ��ɹ�*/
    {
        s=(BiTree)malloc(sizeof(BiTNode));
        s->data=key;
        s->lchild=s->rchild=NULL;
        if(!p)
            *T=s;    /*����sΪ�µĸ����*/
        else if(key<p->data)
            p->lchild=s;    /*����sΪ����*/
        else
            p->rchild=s;    /*����sΪ�Һ���*/
        return TRUE;
    }
    else
        return FALSE;    /*�������йؼ�����ͬ�Ľ��,���ٲ���*/
}

/*������������T�д��ڹؼ��ֵ���key������Ԫ��ʱ,��ɾ��������Ԫ�ؽ�㲢����TRUE,���򷵻�FALSE*/
Status DeleteBST(BiTree *T,int key)
{
    if(!*T)    /*�����ڹؼ��ֵ���key������Ԫ��*/
        return FALSE;
    else
    {
        if(key==(*T)->data)    /*�ҵ��ؼ��ֵ���key������Ԫ��*/
            return Delete(T);
        else if(key<(*T)->data)
            return DeleteBST(&(*T)->lchild,key);
        else
            return DeleteBST(&(*T)->rchild,key);
    }
}

/*�Ӷ�����������ɾ�����p,���ؽ��������������*/
Status Delete(BiTree *p)
{
    BiTree q,s;
    if((*p)->rchild==NULL)    /*����������ֻ��Ҫ�ؽ�����������*/
    {
        q=*p;
        *p=(*p)->lchild;
        free(q);
    }
    else if((*p)->lchild==NULL)    /*ֻ��Ҫ�ؽ�����������*/
    {
        q=*p;
        *p=(*p)->rchild;
        free(q);
    }
    else    /*��������������*/
    {
        q=*p;
        s=(*p)->lchild;
        while(s->rchild)    /*ת��,Ȼ�����ҵ���ͷ(�Ҵ�ɾ�ڵ��ǰ��)*/
        {
            q=s;
            s=s->rchild;
        }
        (*p)->data=s->data;    /*sָ��ɾ����ֱ��ǰ��*/
        if(q!=*p)
            q->rchild=s->lchild;    /*�ؽ�q��������*/
        else
            q->lchild=s->rchild;    /*�ؽ�q��������*/
        free(s);
    }
}


/*�������Ķ���������ṹ����*/
typedef struct BiTNode    /*���ṹ*/
{
    int data;    /*�������*/
    int bf;    /*����ƽ������*/
    struct BiTNode *lchild,rchild;    /*���Һ���ָ��*/
} BiTNode, *BiTree;

/*����PΪ���Ķ�������������������,����֮��Pָ���µ��������,����ת����֮ǰ�������������*/
void R_Rotata(BiTree *P)
{
    BiTree L;
    L=(*P)->lchild;    /*Lָ��P�������������*/
    (*P)->lchild=L->rchild;    /*L���������ҽ�ΪP��������*/
    L->rchild=(*P);
    *P=L;    /*Pָ���µĸ����*/
}

/*����PΪ���Ķ�������������������,����֮��Pָ���µ��������,����ת����֮ǰ�������������O*/
void L_Rotate(BiTree *P)
{
    BiTree R;
    R=(*P)->rchild;    /*Rָ��P�������������*/
    (*P)->rchild=R->lchild;    /*R���������ҽ�ΪP��������*/
    R->lchild=(*P);
    *P=R;    /*Pָ���µĸ����*/
}

#define LH +1    /*���*/
#define EH 0    /*�ȸ�*/
#define RH -1    /*�Ҹ�*/
/*����ָ��T��ָ���Ϊ���Ķ���������ƽ����ת����*/
/*���㷨����ʱ,ָ��Tָ���µĸ����*/
void LeftBalance(BiTree *T)
{
    BiTree L,Lr;
    L=(*T)->lchild;    /*Lָ��T�������������*/
    switch(L->bf)
    {
        /*���T����������ƽ���,������Ӧ��ƽ�⴦��*/
        case LH:    /*�½�������T�����ӵ���������,Ҫ����������*/
            (*T)->bf=L->bf=EH;
            R_Rotate(T);
            break;
        case RH:    /*�½�������T�����ӵ���������,Ҫ��˫������*/
            Lr=L->rchild;    /*Lrָ��T�����ӵ���������*/
            switch(Lr->bf)    /*�޸�T�������ӵ�ƽ������*/
            {
                case LH:  (*T)->bf=RH;
                        L->bf=EH;
                        break;
                case EH:  (*T)->bf=L->bf=EH;
                        break;
                case RH:  (*T)->bf=EH;
                        L->bf=LH;
                        break;
            }
            Lr->bf=EH;
            L_Rotate(&(*T)->lchild);    /*��T��������������ƽ�⴦��*/
            R_Rotate(T);    /*��T������ƽ�⴦��*/
    }
}


/*����ƽ��Ķ���������T�в����ں�e����ͬ�ؼ��ֵĽ��,�����һ������Ԫ��Ϊe���½�㲢����1,���򷵻�0*/
/*������ʹ����������ʧȥƽ��,����ƽ����ת����,��������taller��ӳT�������*/
Status InsertAVL(BiTree *T,int e,Status *taller)
{
    if(!T)
    {
        /*�����½��,��"����",��tallerΪTRUE*/
        *T=��BiTree��malloc(sizeof(BiTNode));
        (*T)->data=e;
        (*T)->lchild=(*T)->rchild=NULL;
        (*T)->bff=EH;
        *taller=TRUE;
    }
    else
    {
        if(e==(*T)->data)
        {
            /*�����Ѵ��ں�e����ͬ�ؼ��ֵĽ�����ٲ���*/
            *taller=FALSE;
            return FALSE;
        }
        if(e<(*T)->data)
        {
            /*Ӧ������T���������н�������*/
            if(!InsertAVL(&(*T)->lchild,e,taller))    /*δ����*/
                return FALSE;
            if(*taller)    /*�Ѳ��뵽T������������������"����"*/
            {
                switch((*T)->bf)    /*���T��ƽ���*/
                {
                    case LH:    /*ԭ������������������,��Ҫ����ƽ�⴦��*/
                            LeftBalance(T);
                            *taller=FALSE;
                            break;
                    case EH:    /*ԭ�����������ȸ�,�������������߶�������*/
                            (*T)->bf=LH;
                            *taller=TRUE;
                            break;
                    case RH:    /*ԭ������������������,�����������ȸ�*/
                            (*T)->bf=EH;
                            *taller=FALSE;
                            break;
                }
            }
        }
        else
        {
            /*Ӧ������T���������н�������*/
            if(!InsertAVL(&(*T)->rchild,e,taller))    /*δ����*/
                return FALSE;
            if(*taller)    /*�Ѳ��뵽T������������������"����"*/
            {
                switch((*T)->bf)    /*���T��ƽ���*/
                {
                    case LH:    /*ԭ������������������,�����������ȸ�*/
                            (*T)->bf=EH;
                            *taller=FALSE;
                            break;
                    case EH:    /*ԭ�����������ȸ�,�������������߶�������*/
                            (*T)->bf=RH;
                            *taller=TRUE;
                            break;
                    case RH:    /*ԭ������������������,��Ҫ����ƽ�⴦��*/
                            RightBalance(T);
                            *taller=FALSE;
                            break;
                }
            }
        }
    }
    return TRUE;
}


#define SUCCESS 1
#define UNSUCCESS 0
#define HASHSIZE 12    /*����ɢ�б�Ϊ����ĳ���*/
#define NULLKEY -32768
typedef struct
{
    int *elem;    /*����Ԫ�ش洢��ַ,��̬��������*/
    int count;    /*��ǰ����Ԫ�ظ���*/
}HashTable;
int m=0;    /*ɢ�б��,ȫ�ֱ���*/

/*��ʼ��ɢ�б�*/
Status InitHashTable(HashTable *H)
{
    int i;
    m=HASHSIZE;
    H->count=m;
    H->elem=(int *)malloc(m*sizeof(int));
    for(i=0;i<m;i++)
        H->elem[i]=NULLKEY;
    return OK;
}

/*ɢ�к���*/
int Hash(int key)
{
    return key % m;    /*����������*/
}

/*����ؼ��ֽ�ɢ�б�*/
void InsertHash(HashTable *H,int key)
{
    int addr=Hash(key);    /*��ɢ�е�ַ*/
    while(H->elem[addr]!=NULLKEY)    /*�����Ϊ��,���ͻ*/
        addr=(addr+1) % m;    /*���Ŷ�ַ��������̽��*/
    H->elem[addr]=key;    /*ֱ���п�λ�����ؼ���*/
}

/*ɢ�б���ҹؼ���*/
Status SearchHash(HashTable H,int key,int *addr)
{
    *addr=Hash(key);    /*��ɢ�е�ַ*/
    while(H.elem[*addr]!=key)    /*�����Ϊ��,���ͻ*/
    {
        *addr=(*addr+1) % m;    /*���Ŷ�ַ������̽��*/
        if(H.elem[*addr]==NULLKEY || *addr==Hash(key))
        {
            /*���ѭ���ص�ԭ��*/
            return UNSUCCESS;    /*˵���ؼ��ֲ�����*/
        }
    }
    return SUCCESS;
}

