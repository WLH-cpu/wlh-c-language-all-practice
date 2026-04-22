#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

int parent[MAXSIZE];
int rank_[MAXSIZE];

void InitUnionFind(int n)
{
    for(int i=0;i<n;i++)
    {
        parent[i]=i;
        rank_[i]=1;
    }
}

int Find(int x)
{
    if(parent[x]!=x)
    parent[x]=Find(parent[x]);
    return parent[x];
}

void Union(int x,int y)
{
    int fx=Find(x);
    int fy=Find(y);
    if(fx==fy) return;
    if(rank_[fx]<rank_[fy])
    {
        parent[fx]=fy;
    }
    else
    {
        parent[fy]=fx;
        if(rank_[fx]==rank_[fy])
        {
            rank_[fx]++;
        }
    }
}

int isConnected(int x,int y)
{
    return Find(x)==Find(y);
}

void PrintUnionFind(int n)
{
    printf("节点编号：");
    for(int i=0;i<n;i++)
    {
        printf("%d ",i);
    }
    printf("\n父节点：");
    for(int i=0;i<n;i++)
    {
        printf("%d ",parent[i]);
    }
    printf("\n树高：");
    for(int i=0;i<n;i++)
    {
        printf("%d ",rank_[i]);
    }
    printf("\n");
}

int main()
{
    int n=10;
    InitUnionFind(n);
    Union(0,1);
    Union(1,2);
    Union(3,4);
    Union(4,5);
    Union(0,3);
    PrintUnionFind(n);
    printf("\n0和5是否连通：%s\n",isConnected(0,5)?"是":"否");

    return 0;
}