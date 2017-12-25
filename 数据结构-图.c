/*ͼ���ڽӾ���洢�ṹ����*/
typedef char VertexType    /*��������Ӧ���û�����*/
typedef int EdgeType    /*����Ȩֵ����Ӧ���û�����*/
#define MAXVEX 100    /*��󶥵���,Ӧ���û�����*/
#define INFINITY 65535    /*��65535��������*/
typedef struct
{
    VertexType vexs[MAXVEX];    /*�����*/
    EdgeType arc[MAXVEX][MAXVEX];    /*�ڽӾ���,�ɿ����߱�*/
    int numVertexes, numEdges;    /*ͼ�е�ǰ�������ͱ���*/
}MGraph;


/*����������ͼ���ڽӾ����ʾ*/
void CreateMGraph(MGraph *G)
{
    int i,j,k,w;
    printf("���붥�����ͱ���:\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);    /*���붥�����ͱ���*/
    for(i=0;i<G->numVertexes;i++)    /*���붥����Ϣ,���������*/
    {
        scanf(&G->vexs[i]);
    }
    for(i=0;i<G->numVertexes;i++)
        for(j=0;j<G->numVertexes;j++)
            G->arc[i][j]=INFINITY;    /*�ڽӾ����ʼ��*/
    for(k=0;k<G->numEdges;k++)    /*����numEdges����,�����ڽӾ���*/
    {
        printf("�����(vi,vj)�ϵ��±�i,�±�j��Ȩw:\n");
        scanf("%d,%d,%d",&i,&j,&w);    /*�����(vi,vj)�ϵ�Ȩw*/
        G->arc[i][j]=w;
        G->arc[j][i]=G->arc[i][j];    /*��Ϊ������ͼ,����Գ�*/
    }
}


/*ͼ���ڽӱ�洢�ṹ����*/
typedef char VertexType    /*��������Ӧ���û�����*/
typedef int EdgeType    /*����Ȩֵ����Ӧ���û�����*/

typedef struct EdgeNode    /*�߱���*/
{
    int adjvex;    /*�ڽӵ���,�洢�ö����Ӧ���±�*/
    EdgeType weight;    /*���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ*/
    struct EdgeNode *next;    /*����,ָ����һ���ڽӵ�*/
}EdgeNode;

typedef struct VertexNode    /*�������*/
{
    VertexType data;    /*������,�洢������Ϣ*/
    EdgeNode *firstedge;    /*�߱�ͷָ��*/
}VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges;    /*ͼ�е�ǰ�������ͱ���*/
}GraphAdjList;


/*��������ͼ���ڽӱ�ṹ*/
void CreateALGraph(GraphAdjList *G)
{
    int i,j,k;
    EdgeNode *e;
    printf("���붥�����ͱ���:\n");
    scanf("%d,%d",&G->numVertexes,&G->numEdges);    /*���붥�����ͱ���*/
    for(i=0;i<G->numVertexes;i++)
    {
        scanf(&G->adjList[i].data);    /*���붥����Ϣ*/
        G->adjList[i].firstedge=NULL;    /*���߱���Ϊ�ձ�*/
    }
    for(k=0;k<G->numEdges;k++)    /*�����߱�*/
    {
        printf("�����(vi,vj)�ϵĶ������:\n");
        scanf("%d,%d",&i,&j);    /*�����(vi,vj)�ϵĶ������*/
        e=(EdgeNode*)mallic(sizeof(EdgeNode));    /*���ڴ�����ռ�,���ɱ߱���*/
        e->adjvex=j;    /*�ڽ����Ϊj*/
        e->next=G->adjList[i].firstedge;    /*��eָ��ָ��ǰ����ָ��Ľ��*/
        G->adjList[i].firstedge=e;    /*����ǰ�����ָ��ָ��e*/
        e=(EdgeNode*)malloc(sizeof(EdgeNode));    /*���ڴ�����ռ�,���ɱ߱���*/
        e->adjvex=i;    /*�ڽ����Ϊi*/
        e->next=G->adjList[j].firstedge;    /*��eָ��ָ��ǰ����ָ��Ľ��*/
        G->adjList[j].firstedge=e;    /*����ǰ�����ָ��ָ��e*/

    }
}


typedef int Boolean;    /*Boolean�ǲ�������,��ֵ��TRUE��FALSE*/
Boolean visited[MAX];    /*���ʱ�־������*/
/*�ڽӾ����������ȵݹ��㷨*/
void DFS(MGraph G,int i)
{
    int j;
    visited[i]=TRUE;
    printf("%c",G.vexs[i]);    /*��ӡ����,Ҳ������������*/
    for(j=0;j<G.numVertexes;j++)
        if(G.arc[i][j]==1&&!visited[j])
            DFS(G,j);    /*��Ϊ���ʵ��ڽӶ���ݹ����*/
}

/*�ڽӾ������ȱ�������*/
void DFSTraverse(MGraph G)
{
    int i;
    for(i=0;i<G.numVertexes;i++)
        visited[i]=FALSE;    /*��ʼ���ж���״̬����δ���ʹ���״̬*/
    for(i=0;i<G.numVertexes;i++)
        if(!visited[i])    /*��δ���ʹ��Ķ������DFS,������ͨͼ,ֻ��ִ��һ��*/
            DFS(G,i);
}


/*�ڽӱ��������ȵݹ��㷨*/
void DFS(GraphAdjList GL,int i)
{
    EdgeNode *p;
    visited[i]=TRUE;
    printf("%c ",GL->adjList[i].data);    /*��ӡ����,Ҳ������������*/
    p=GL->adjList[i].firstedge;
    while(p)
    {
        if(!visited[p->adjvex])
            DFS(GL,p->adjvex);    /*��Ϊ���ʵ��ڽӶ���ݹ����*/
        p=p->next;
    }
}

/*�ڽӱ����ȱ�������*/
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for(i=0;i<GL->numVertexes;i++)
        visited[i]=FALSE;    /*��ʼ���ж���״̬����δ���ʹ���״̬*/
    for(i=0;i<GL->numVertexes;i++)
        if(!visited[i])    /*��δ���ʹ��Ķ������DFS,������ͨͼ,ֻ��ִ��һ��*/
            DFS(GL,i);
}


/*�ڽӾ���Ĺ�ȱ����㷨*/
void BFSTraverse(MGraph G)
{
    int i,j;
    Queue Q;
    for(i=0;i<G.numVertexes;i++)
        visited[i]=FALSE;
    InitQueue(&Q);    /*��ʼ��һ�����õĶ���*/
    for(i=0;i<G.numVertexes;i++)    /*��ÿһ��������ѭ��*/
    {
        if(!visited[i])    /*����δ���ʹ��ʹ���*/
        {
            visited[i]=TRUE;    /*���õ�ǰ������ʹ�*/
            printf("%c",G.vexs[i]);    /*��ӡ����,Ҳ������������*/
            EnQueue(&Q,i);    /*���˶��������*/
            while(!QueueEmpty(Q))    /*����ǰ���в�Ϊ��*/
            {
                DeQueue(&Q,&i);    /*������Ԫ�س�����,��ֵ��i*/
                for(j=0;j<G.numVertexes;j++)
                {
                    /*�ж������������뵱ǰ������ڱ���δ���ʹ�*/
                    if(G.arc[i][j]==1&&!visited[j])
                    {
                        visited[j]=TRUE;    /*���ҵ��Ĵ˶�����Ϊ�ѷ���*/
                        printf("%c",G.vexs[j]);    /*��ӡ����*/
                        EnQueue(&Q,j);    /*���ҵ��Ĵ˶��������*/
                    }
                }
            }
        }
    }
}

/*�ڽӱ�Ĺ�ȱ����㷨*/
void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    Queue Q;
    for(i=0;i<GL->numVertexes;i++)
        visited[i]=FALSE;
    InitQueue(&Q);
    for(i=0;i<GL->numVertexes;i++)
    {
        if(!visited[i])
        {
            visited[i]=TRUE;
            printf("%c ",GL->adjList[i].data);    /*��ӡ���,Ҳ������������*/
            EnQueue(&Q,i);
            while(!QueueEmpty(Q))
            {
                DeQueue(&Q,&i);
                p=GL->adjList[i].firstedge;    /*�ҵ���ǰ������߱�����ͷָ��*/
                while(p)
                {
                    if(!visited[p->adjvex])    /*���˶���δ������*/
                    {
                        visited[p->adjvex]=TRUE;
                        printf("%c ",GL->adjList[p->adjvex].data);
                        EnQueue(&Q,p->adjvex);    /*���˶��������*/
                    }
                    p=p->next;    /*ָ��ָ����һ�ڽӵ�*/
                }
            }
        }
    }
}


/*Prim�㷨������С������*/
void MiniSpanTree_Prim(MGraph G)
{
    int min,i,j,k;
    int adjvex[MAXVEX];    /*������ض����±�*/
    int lowcost[MAXVEX];    /*������ض����ߵı�Ȩ*/
    lowcost[0]=0;    /*��ʼ����һ��ȨֵΪ0,��v0������������lowcost��ֵΪ0,��������Ǵ��±�Ķ����Ѿ�����������*/
    adjvex[0]=0;    /*��ʼ����һ�������±�Ϊ0*/
    for(i=1;i<G.numVertexes;i++)    /*ѭ�����±�Ϊ0���ȫ������*/
    {
        lowcost[i]=G.arc[0][i];    /*��v0������֮�бߵ�Ȩֵ��������*/
        adjvex[i]=0;    /*��ʼ����Ϊv0���±�*/
    }
    for(i=1;i<G.numVertexes;i++)
    {
        min=INFINITY;    /*��ʼ����СȨֵΪ����*/
        j=1;
        k=0;
        while(j<G.numVertexes)    /*ѭ��ȫ������*/
        {
            if(lowcost[j]!=0&&lowcost[j]<min)
            {
                /*���Ȩֵ��Ϊ0��ȨֵС��min*/
                min=lowcost[j];    /*���õ�ǰȨֵ��Ϊ��Сֵ*/
                k=j;    /*����ǰ��Сֵ���±����k*/
            }
            j++;
        }
        printf("(%d,%d)",adjvex[k],k);    /*��ӡ��ǰ�������Ȩֵ��С��*/
        lowcost[k]=0;    /*����ǰ�����Ȩֵ����Ϊ0,��ʾ�˶����Ѿ��������*/
        for(j=1;j<G.numVertexes;j++)    /*ѭ�����ж���*/
        {
            if(lowcost[j]!=0&&G.arc[k][j]<lowcost[j])
            {
                /*���±�Ϊk�������ȨֵС�ڴ�ǰ��Щ����δ������������Ȩֵ*/
                lowcost[j]=G.arc[k][j];    /*����СȨֵ����lowcost*/
                adjvex[j]=k;    /*���±�Ϊk�Ķ������adjvex*/
            }
        }
    }
}


/*Kruskal�㷨������С������*/
/*�Ա߼�����Edge�ṹ�Ķ���*/
typedef struct
{
    int begin;
    int end;
    int weight;
}Edge;

void MiniSpanTree_Kruskal(MGraph G)   /*������С������*/
{
    int i,n,m;
    Edge edges[MAXEDGE];    /*����߼�����*/
    int parent[MAXVEX];    /*����һ���������жϱ�����Ƿ��γɻ�·*/
    /*�˴�ʡ�Խ��ڽӾ���Gת��Ϊ�߼�����edges����Ȩ��С�������еĴ���*/
    for(i=0;i<G.numVertexes;i++)
        parent[i]=0;    /*��ʼ������ֵΪ0*/
    for(i=0;i<G.numEdges;i++)    /*ѭ��ÿһ����*/
    {
        n=Find(parent,edges[i].begin);
        m=Find(parent,deges[i].end);
        if(n!=m)    /*����n��m����,��˵���˱�û���������������γɻ�·*/
        {
            parent[n]=m;    /*���˱ߵĽ�β��������±�Ϊ����parent��,��ʾ�˶����Ѿ���������������*/
            printf("(%d,%d) %d",edges[i].begin,edges[i].end,edges[i].weight);
        }
    }
}

int Find(int *parent,int f)    /*�������߶����β���±�*/
{
    while(parent[f]>0)
        f=parent[f];
    return f;
}


#define MAXVEX 9
#define INFINITY 65535
typedef int Patharc[MAXVEX];    /*���ڴ洢���·���±������*/
typedef int ShortPathTable[MAXVEX];    /*���ڴ洢���������·����Ȩֵ��*/
/*Dijkstra�㷨,��������G��v0���㵽���ඥ��v���·��P[v]����Ȩ����D[v]*/
/*P[v]��ֵΪǰ�������±�,D[v]��ʾv0��v�����·�����Ⱥ�*/
void ShortestPath_Dijkstra(MGrapg G,int v0,Patharc *P,ShortPathTable *D)
{
    int v,w,k,min;
    int final[MAXVEX];    /*final[w]=1��ʾ��ö���v0��vw�����·��*/
    for(v=0;v<G.numVertexes;v++)    /*��ʼ������*/
    {
        final[v]=0;    /*ȫ�������ʼ��Ϊδ֪���·��״̬*/
        (*D)[v]=G.arc[v0][v];    /*����v0�������ߵĶ������Ȩֵ*/
        (*P)[v]=0;    /*��ʼ��·������PΪ0*/
    }
    (*D)[v0]=0;    /*v0��v0·��Ϊ0*/
    final[v0]=1;    /*v0��v0����Ҫ��·��*/
    /*��ʼ��ѭ��,ÿ�����v0��ĳ��v��������·��*/
    for(v=1;v<G.numVertexes;v++)
    {
        min=INFINITY;    /*��ǰ��֪��v0������������*/
        for(w=0;w<G.numVertexes;w++)    /*Ѱ����v0����Ķ���*/
        {
            if(!final[w]&&(*D)[w]<min)
                {
                    k=w;
                    min=(*D)[w];    /*w������v0�������*/
                }
        }
        final[k]=1;    /*��Ŀǰ�ҵ�������Ķ�����Ϊ1*/
        for(w=0;w<G.numVertexes;w++)    /*������ǰ���·��������*/
        {
            /*�������v�����·������������·���ĳ��ȶ̵Ļ�*/
            if(!final[w]&&(min+G.arc[k][w])<(*D)[w])
            {
                /*˵���ҵ��˸��̵�·��,�޸�D[w]��P[w]*/
                (*D)[w]=min+.arc[k][w];    /*�޸ĵ�ǰ·������*/
                (*P)[w]=k;
            }
        }
    }
}


typedef int Pathmatirx[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];
/*Floyd�㷨,����ͼG�и�����v�����ඥ��w���·��P[V][W]����Ȩ����D[v][w]*/
void ShortestPath_Floyd(MGraph G,Pathmatirx *P,ShortPathTable *D)
{
    int v,w,k;
    for(v=0;v<G.numVertexes;++v)    /*��ʼ��D��P*/
    {
        for(w=0;w<G.numVertexes;++w)
            {
                (*D)[v][w]=G.matirx[v][w];    /*D[v][w]ֵ��Ϊ��Ӧ����Ȩֵ*/
                (*P)[v][w]=w;    /*��ʼ��P*/
            }
    }
    for(k=0;k<G.numVertexes;++k)
    {
        for(v=0;v<G.numVertexes;++v)
        {
            for(w=0;w<G.numVertexes;++w)
            {
                if((*D)[v][w]>(*D)[v][k]+(*D)[k][w])
                {
                    /*��������±�Ϊk����·����ԭ�����·������*/
                    /*����ǰ�����Ȩֵ��Ϊ��С��һ��*/
                    (*D)[v][w]=(*D)[v][k]+(*D)[k][w];
                    (*P)[v][w]=(*P)[v][k];    /*·�����þ����±�Ϊk�Ķ���*/
                }
            }
        }
    }
}

/*�����·������ʾ*/
for(v=0;v<G.numVertexes;++v)
{
    for(w=v+1;w<G.numVertexes;w++)
    {
        printf("v%d-v%d weight: %d",v,w,D[v][w]);
        k=P[v][w];    /*��õ�һ��·�������±�*/
        printf(" path: %d",v);    /*��ӡԴ��*/
        while(k!=w)
        {
            printf(" -> %d",k);    /*��ӡ·������*/
            k=P[k][w];    /*�����һ��·�������±�*/
        }
        printf(" -> %d\n",w);    /*��ӡ�յ�*/
    }
    printf("\n");
}


typedef struct EdgeNode    /*�߱���*/
{
    int adjvex;    /*�ڽӵ���,�洢�ö����Ӧ���±�*/
    int weight;    /*���ڴ洢Ȩֵ,���ڷ���ͼ���Բ���Ҫ*/
    struct EdgeNode *next;    /*����,ָ����һ���ڽӵ�*/
}EdgeNode;

typedef struct VertexNode    /*�������*/
{
    int in;    /*�������*/
    int data;    /*������,�洢������Ϣ*/
    EdgeNode *firstedge;    /*�߱�ͷָ��*/
}VertexNode,AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes,numEdges;    /*ͼ�е�ǰ�������ͱ���*/
}graphAdjList,*GraphAdjList;


/*��������,��GL�޻�·,����������������в�����OK,���л�·����ERROR*/
Status TopologicalSort(GraphAdjList GL)
{
    EdgeNode *e;
    int i,k,gettop;
    int top=0;    /*����ջָ���±�*/
    int count=0    /*����ͳ���������ĸ���*/
    int *stack;    /*��ջ�洢���Ϊ0�Ķ���*/
    stack=(int *)malloc(GL->numVertexes * sizeof(int));
    for(i=0;i<GL->numVertexes;i++)
        if(GL->adjList[i].in==0)
            stack[++top]=i;    /*�����Ϊ0�Ķ�����ջ*/
    while(top!=0)
    {
        gettop=stack[top--];    /*��ջ*/
        printf("%d ->",GL->adjList[gettop].data);    /*��ӡ�˶���*/
        count++;    /*ͳ�����������*/
        for(e=GL->adjList[gettop].firstedge;e;e=e->next)
        {
            /*�Դ˶��㻡�����*/
            k=e->adjvex;
            if(!(--GL->adjList[k].in))    /*��k�Ŷ����ڽӵ����ȼ�1*/
                stack[++top]=k;    /*��Ϊ0����ջ,�Ա����´�ѭ�����*/
        }
    }
    if(count<GL->numVertexes)    /*���countС�ڶ�����,˵�����ڻ�*/
        return ERROR;
    else
        return OK;
}


int *etv,*ltv;    /*�¼����緢��ʱ�����ٷ���ʱ������*/
int *stack2;    /*���ڴ洢�������е�ջ*/
int top2;    /*����stack2��ָ��*/

/*��������,���ڹؼ�·������*/
Status TopologicalSort(GraphAdjList GL)
{
    EdgeNode *e;
    int i,k,gettop;
    int top=0;    /*����ջָ���±�*/
    int count=0;    /*����ͳ���������ĸ���*/
    int *stack;    /*��ջ�����Ϊ0�Ķ�����ջ*/
    stack=(int *)malloc(GL->numVertexes * sizeof(int));
    for(i=0;i<GL->numVertexes;i++)
        if(0==GL->adjList[i].in)
        stack[++top]=i;
    top2=0;    /*��ʼ��Ϊ0*/
    etv=(int *)malloc(GL->numVertexes * sizeof(int));    /*�¼����緢��ʱ��*/
    for(i=0;i<GL->numVertexes;i++)
        etv[i]=0;    /*��ʼ��Ϊ0*/
    stack2=(int *),malloc(GL->numVertexes * sizeof(int));    /*��ʼ��*/
    while(top!=0)
    {
        gettop=stack[top--];
        count++;
        stack2[++top2]=gettop;    /*�������Ķ������ѹ���������е�ջ*/
        for(e=GL->adjList[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            if(!(--GL->adjList[k].in))
                stack[++top]=k;
            if((etv[gettop]+e->weight)>etv[k])    /*��������¼����緢��ʱ��ֵ*/
                etv[k]=etv[gettop]+e->weight;
        }
    }
    if(count<GL->numVertexes)
        return ERROR;
    else
        return OK;
}


/*��ؼ�·��,GLΪ����ͼ,���GL�ĸ���ؼ��*/
void CriticalPath(GraphAdjList GL)
{
    EdgeNode *e;
    int i,j,k,gettop;
    int ete,lte;    /*��������緢��ʱ�����ٷ���ʱ�����*/
    Topological(GL);    /*����������,��������etv��stack2��ֵ*/
    ltv(int *)malloc(GL->numVertexes * sizeof(int));    /*�¼�������ʱ��*/
    for(i=0;i<GL->numVertexes;i++)
        ltv[i]=evt[GL->numVertexes-1];    /*��ʼ��ltv*/
    while(top2!=0)    /*����ltv*/
    {
        gettop=stack[top2--];    /*���������г�ջ,����ȳ�*/
        for(e=GL->adjList[gettop].firstedge;e;e=e->next)
        {
            /*��������¼�����ٷ���ʱ��ltvֵ*/
            k=e->adjvex;
            if(ltv[k]-e>weight<ltv[gettop])    /*��������¼�������ʱ��ltv*/
                ltv[gettop]=ltv[k]-e->weight;
        }
    }
    for(j=0;j<GL->numVertexes;j++)    /*��ete,lte�͹ؼ��*/
    {
        for(e=GL->adjList[gettop].firstedge;e;e=e->next)
        {
            k=e->adjvex;
            ete=etv[j];    /*����緢��ʱ��*/
            lte=ltv[k]-e->weight;    /*���ٷ���ʱ��*/
            if(ete==lte)
                printf("<v%d,v%d> length: %d ,",Gl->adjList[j].data,GL->adjList[k].data,e->weight);
        }
    }
}


