#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int key;
    struct Node* next;
}Node;

#define HASH_TABLE_SIZE 11

Node* hashTable[HASH_TABLE_SIZE];

int hash(int key)
{
    return key%HASH_TABLE_SIZE;
}

void initHashTable()
{
    for(int i=0;i<HASH_TABLE_SIZE;i++)
    {
        hashTable[i]=NULL;
    }
}

Node* createNode(int key)
{
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(newNode==NULL) exit(-2);
    newNode->key=key;
    newNode->next=NULL;
    return newNode;
}

void insert(int key)
{
    int index=hash(key);
    Node* newNode=createNode(key);
    newNode->next=hashTable[index];
    hashTable[index]=newNode;
}

Node* search(int key)
{
    int index=hash(key);
    Node* p=hashTable[index];
    while(p!=NULL)
    {
        if(p->key==key)
        return p;
        p=p->next;
    }
}

void printHashTable()
{
    for(int i=0;i<HASH_TABLE_SIZE;i++)
    {
        printf("[%02d]:",i);
        Node* p=hashTable[i];
        while(p!=NULL)
        {
            printf("%d->",p->key);
            p=p->next;
        }
        printf("NULL\n");
    }
}

void destryHashTable()
{
    for(int i=0;i<HASH_TABLE_SIZE;i++)
    {
        Node* p=hashTable[i];
        while(p!=NULL)
        {
            Node* temp=p;
            p=p->next;
            free(temp);
        }
        hashTable[i]=NULL;
    }
}

int main()
{
    initHashTable();

    int arr[]={12, 22,32,45,55,6,7,89,9,23,34};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        insert(arr[i]);
    }
    printHashTable();

    int searchKey=22;
    Node* result=search(searchKey);
    if(result!=NULL) printf("找到了");
    else printf("没找到");

    return 0;
}