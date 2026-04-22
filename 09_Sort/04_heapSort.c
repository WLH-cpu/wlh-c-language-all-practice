#include <stdio.h>

void swap(int* x,int* y)
{
    int t=*x;
    *x=*y;
    *y=t;
}

void heapify(int a[],int n,int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n&&a[l]>a[largest])
    largest=l;
    if(r<n&&a[r]>a[largest])
    largest=r;
    if(largest!=i) 
    {
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }
}

void heapSort(int a[],int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(a,n,i);
    for(int i=n-1;i>0;i--)
    {
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}

int main()
{
    int arr[]={3,1,4,1,5,9,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    printArray(arr,n);

    heapSort(arr,n);

    printArray(arr,n);

    return 0;
}