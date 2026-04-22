#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 100

typedef struct ArcNode
{
    int adjvex;
    struct ArcNode* nextarc;
}ArcNode;

typedef struct VNode
{
    int data;
    ArcNode* firstarc;
}VNode,AdjList[MaxVertexNum];

typedef struct
{
    AdjList adjList;
    int n,e;
}ALGraph;

void TopologicalSort(ALGraph* G)
{
    int count=0;
    int indegree[MaxVertexNum]={0};
    int queue[MaxVertexNum],front=0,rear=0;
    ArcNode* p;
    for(int i=0;i<G->n;i++)
    {
        p=G->adjList[i].firstarc;
        while(p!=NULL)
        {
            indegree[p->adjvex]++;
            p=p->nextarc;
        }
    }
    for(int i=0;i<G->n;i++)
    {
        if(indegree[i]==0)
        queue[rear++]=i;
    }
    while(front<rear)
    {
        int v=queue[front++];
        printf("%d ",G->adjList[v].data);
        count++;
        p=G->adjList[v].firstarc;
        while(p!=NULL)
        {
            int k=p->adjvex;
            if(--indegree[k]==0)
            queue[rear++]=k;
            p=p->nextarc;
        }
    }
    printf("\n");
    if(count<G->n)
    printf("图中有环，无法拓扑排序\n");
    else    
    printf("拓扑排序完成\n");
}

void CreateGraph(ALGraph* G)
{
    scanf("%d %d",&G->n,&G->e);
    for(int i=0;i<G->n;i++)
    {
        scanf("%d",&G->adjList[i].data);
        G->adjList[i].firstarc=NULL;
    }
    for(int k=0;k<G->e;k++)
    {
        int i,j;
        scanf("%d %d",&i,&j);
        ArcNode* p=(ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex=j;
        p->nextarc=G->adjList[i].firstarc;
        G->adjList[i].firstarc=p;
    }
}

int main()
{
    ALGraph G;
    CreateGraph(&G);
    TopologicalSort(&G);

    return 0;
}