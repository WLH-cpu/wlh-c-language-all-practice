#include <stdio.h>
#include <stdlib.h>

typedef struct BSTNode
{
    int data;
    struct BSTNode* lchild,*rchild;
}BSTNode,*BSTree;

int bst_search(BSTree T,int key)
{
    if(!T) return 0;
    if(T->data==key) return 1;
    else if(T->data>key) return bst_search(T->lchild,key);
    else return bst_search(T->rchild,key);
}

int bst_insert(BSTree* T,int key)
{
    if(*T==NULL)
    {
        *T=(BSTNode*)malloc(sizeof(BSTNode));
        (*T)->data=key;
        (*T)->lchild=(*T)->rchild=NULL;
        return 1;
    }
    if(key==(*T)->data) return 0;
    return key<(*T)->data?bst_insert(&(*T)->lchild,key):bst_insert(&(*T)->rchild,key);
}

BSTree bst_create(int arr[],int n)
{
    BSTree T=NULL;
    for(int i=0;i<n;i++)
    bst_insert(&T,arr[i]);
    return T;
}

void bst_in_order(BSTree T)
{
    if(T==NULL) return;
    bst_in_order(T->lchild);
    printf("%d ",T->data);
    bst_in_order(T->rchild);
}

void bst_destroy(BSTree* T)
{
    if(*T==NULL) return;
    bst_destroy(&(*T)->lchild);
    bst_destroy(&(*T)->rchild);
    free(*T);
    *T=NULL;
}

int main()
{
    int arr[]={5,3,7,2,4};
    int n=sizeof(arr)/sizeof(arr[0]);

    BSTree T=bst_create(arr,n);
    bst_in_order(T);
    printf("\n");

    printf("查找3:%s\n",bst_search(T,3)?"找到":"未找到");
    printf("查找9:%s\n",bst_search(T,9)?"找到":"未找到");

    bst_destroy(&T);

    return 0;
}