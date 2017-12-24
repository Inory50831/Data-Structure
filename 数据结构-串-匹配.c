/*TΪ�ǿմ���������S�е�pos���ַ�֮�������T��ȵ��Ӵ�,�򷵻ص�һ���������Ӵ���S�е�λ��,���򷵻�0*/
int Index(String S, String T, int pos)
{
    int n,m,i;
    String sub;
    if(pos>0)
    {
        n=StrLength(S);    /*�õ�����S�ĳ���*/
        m=StrLength(T);    /*�õ��Ӵ�T�ĳ���*/
        i=pos;
        while(i<=n-m+1)
        {
            SubString(sub,S,i,m);    /*ȡ������i��λ��,������T��ȵ��Ӵ���sub*/
            if(StrCopmare(sub,T)!=0)    /*������������*/
                ++i;
            else    /*����������*/
                return i;    /*�򷵻�i��ֵ*/
        }
    }
    return 0;    /*�����Ӵ���T���,�򷵻�0*/
}


/*����ʵ��,�����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0*/
/*T�ǿ�,1<=pos<=StrLength(S)*/
int Index1(String S, String T, int pos)
{
    int i=pos;    /*i��������S�е�ǰλ���±�,��pos��Ϊ1,���posλ�ÿ�ʼƥ��*/
    int j=1;    /*j�����Ӵ�T�е�ǰλ���±�*/
    while(i<=S[0]&&j<=T[0])    /*��iС��S�ĳ�����jС��T�ĳ���ʱѭ��*/
    {
        if(S[i]==T[j])    /*����ĸ��������*/
        {
            ++i;
            ++j;
        }
        else    /*ָ��������¿�ʼƥ��*/
        {
            i=i-j+2;    /*i�˻ص��ϴ�ƥ����λ����һλ*/
            j=1;    /*j�˻ص��Ӵ�T����λ*/
        }
    }
    if(j>T[0])
        return i-T[0];
    else
        return 0;
}


/*KMPģʽƥ���㷨*/
/*ͨ�����㷵���Ӵ�T��next����*/
void get_next(String T, int *next)
{
    int i,j;
    i=1;
    j=0;
    next[1]=0;
    while(i<T[0])    /*�˴�T[0]��ʾ��T�ĳ���*/
    {
        if(j==0||T[i]==T[j])    /*T[i]��ʾ��׺�ĵ����ַ�,T[j]��ʾǰ׺�ĵ����ַ�*/
        {
            ++i;
            ++j
            next[i]=j;
        }
        else
            j=next[j];    /*���ַ�����ͬ,��jֵ����*/
    }
}

/*�����Ӵ�T������S�е�pos���ַ�֮���λ�á���������,��������ֵΪ0*/
/*T�ǿ�,i<=pos<=StrLength(S)*/
int Index_KMP(String S, String T, int pos)
{
    int i=pos;    /*i��������S��ǰλ���±�ֵ,��pos��Ϊ1,���posλ�ÿ�ʼƥ��*/
    int j=1;    /*j�����Ӵ�T��ǰλ���±�ֵ*/
    int next[255];    /*����һnext����*/
    get_next(T,next);    /*�Դ�T������,�õ�next����*/
    while(i<=S[0]&&j<=T[0])    /*��iС��S�ĳ�����jС��T�ĳ���ʱ,ѭ������*/
    {
        if(j==0||S[i]==T[j])    /*����ĸ��������,���������ƥ���㷨������j=0���ж�*/
        {
            ++i;
            ++j;
        }
        else    /*ָ��������¿�ʼƥ��*/
        {
            j=next[j];    /*j���غ��ʵ�λ��,iֵ����*/
        }
    }
    if(j>T[0])
        return i-T[0];
    else
        return 0;
}

/*��ģʽ��T��next��������ֵ����������nextval*/
void get_nextval(String T, int *nextval)
{
    int i,j;
    i=0;
    j=1;
    nextval[1]=0;
    while(i<T[0])
    {
        if(j==0||T[i]==T[j])
        {
            ++i;
            ++j;
            if(T[i]!=T[j])    /*����ǰ�ַ���ǰ׺�ַ���ͬ*/
                nextval[i]=j;    /*��ǰ��jΪnextval��iλ�õ�ֵ*/
            else
                nextval[i]=nextval[j];    /*�����ǰ׺�ַ���ͬ,��ǰ׺�ַ���nextvalֵ��ֵ��nextval��iλ�õ�ֵ*/
        }
        else
            j=nextval[j];
    }
}
