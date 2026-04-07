#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef char ElemType;

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode* lchild,* rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree* T)
{
    ElemType ch;
    scanf(" %c",&ch);
    if(ch=='#')
    {
        *T=NULL;
    }
    else
    {
        *T=(BiTree)malloc(sizeof(BiTNode));
        (*T)->data=ch;
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

void PreOrder(BiTree T)
{
    if(!T) return;
        printf("%c ",T->data);
        PreOrder(T->lchild);
        PreOrder(T->rchild);
}

void InOrder(BiTree T)
{
    if(!T) return;
        InOrder(T->lchild);
        printf("%c ",T->data);
        InOrder(T->rchild);
}

void PostOrder(BiTree T)
{
    if(!T) return;
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        printf("%c ",T->data);
}

void InOrderNonRec(BiTree T)
{
    if(!T) return;
    BiTree stack[MAXSIZE];
    int top=-1;
    BiTree p=T;
    while(p||top!=-1)
    {
        if(p)
        {
            stack[++top]=p;
            p=p->lchild;
        }
        else
        {
            p=stack[top--];
            printf("%c ",p->data);
            p=p->rchild;
        }
    }
}

void LevelOrder(BiTree T)
{
    if(!T) return;
    BiTree queue[MAXSIZE];
    int front=0,rear=0;
    queue[rear++]=T;
    while(front<rear)
    {
        BiTree node=queue[front++];
        printf("%c ",node->data);
        if(node->lchild)
        queue[rear++]=node->lchild;
        if(node->rchild)
        queue[rear++]=node->rchild;
    }
}

int TreeHeight(BiTree T)
{
    if(!T) return 0;
    int lh=TreeHeight(T->lchild);
    int rh=TreeHeight(T->rchild);
    return (lh>rh?lh:rh)+1;
}

int NodeCount(BiTree T)
{
    if(!T) return 0;
    return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

int LeafCount(BiTree T)
{
    if(!T) return 0;
    if(!T->lchild&&!T->rchild) return 1;
    return LeafCount(T->lchild)+LeafCount(T->rchild);
}

int main()
{
    BiTree T;
    CreateBiTree(&T);
    printf("前序："); PreOrder(T); printf("\n");
    printf("中序："); InOrder(T); printf("\n");
    printf("后序："); PostOrder(T); printf("\n");

    printf("中序非递归："); InOrderNonRec(T); printf("\n");
    printf("层序遍历："); LevelOrder(T); printf("\n");

    printf("树高度：%d\n",TreeHeight(T));
    printf("节点数：%d\n",NodeCount(T));
    printf("叶子数：%d\n",LeafCount(T));

    return 0;
}