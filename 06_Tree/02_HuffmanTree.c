#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define OVERFLOW -1

typedef struct
{
    int weight;
    int parent,lch,rch;
}HTNode,*HuffmanTree;

typedef char** HuffmanCode;

void select(HuffmanTree HT,int n,int* s1,int* s2)
{
    *s1=*s2=0;
    int min1=INT_MAX,min2=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        if(HT[i].parent==0)
        {
            if(HT[i].weight<min1)
            {
                min2=min1;
                min1=HT[i].weight;
                *s2=*s1;
                *s1=i;
            }
            else if(HT[i].weight<min2)
            {
                min2=HT[i].weight;
                *s2=i;
            }
        }
    }
    if(*s1>*s2)
    {
        int temp=*s1;
        *s1=*s2;
        *s2=temp;
    }
}

void CreateHuffmanTree(HuffmanTree* HT,int n)
{
    if(n<=1) return;
    int m=2*n-1;
    *HT=(HuffmanTree)malloc(sizeof(HTNode)*(m+1));
    if(!(*HT)) exit(OVERFLOW);
    for(int i=1;i<=m;i++)
    {
        (*HT)[i].weight=0;
        (*HT)[i].parent=0;
        (*HT)[i].lch=0;
        (*HT)[i].rch=0;
    }
    for(int i=1;i<=n;i++)
        scanf("%d",&((*HT)[i].weight));
    for(int i=n+1;i<=m;i++)
    {
        int s1,s2;
        select(*HT,i-1,&s1,&s2);
        (*HT)[s1].parent=i;
        (*HT)[s2].parent=i;
        (*HT)[i].lch=s1;
        (*HT)[i].rch=s2;
        (*HT)[i].weight=(*HT)[s1].weight+(*HT)[s2].weight;
    }
}

void CreateHuffmanCode(HuffmanTree HT,HuffmanCode* HC,int n)
{
    if(n<=1) return;
    *HC=(HuffmanCode)malloc(sizeof(char*)*(n+1));
    char* cd=(char*)malloc(sizeof(char)*n);
    cd[n-1]='\0';
    for(int i=1;i<=n;i++)
    {
        int start=n-1;
        int c=i;
        int f=HT[i].parent;
        while(f!=0)
        {
            start--;
            if(c==HT[f].lch)
            cd[start]='0';
            else
            cd[start]='1';
            c=f;
            f=HT[f].parent;
        }
        (*HC)[i]=(char*)malloc(sizeof(char)*(n-start));
        strcpy((*HC)[i],&cd[start]);
    }
    free(cd);
}

int main()
{
    int n;
    scanf("%d",&n);
    HuffmanTree HT;
    HuffmanCode HC;

    CreateHuffmanTree(&HT,n);
    CreateHuffmanCode(HT,&HC,n);

    for(int i=1;i<=n;i++)
    {
        printf("%d %s\n",HT[i].weight,HC[i]);
    }

    for(int i=1;i<=n;i++)
    {
        free(HC[i]);
    }
    free(HC);
    free(HT);

    return 0;
}