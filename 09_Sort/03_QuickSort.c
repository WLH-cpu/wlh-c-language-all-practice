#include <stdio.h>

void swap(int* a,int* b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

int patition(int a[],int l,int r)
{
    int pivot=a[l];
    int i=l,j=r;
    while(i<j)
    {
        while(i<j&&a[j]>=pivot) j--;
        while(i<j&&a[i]<=pivot) i++;
        if(i<j) swap(&a[i],&a[j]);
    }
    swap(&a[l],&a[i]);
    return i;
}

void quicksort(int a[],int l,int r)
{
    if(l<r)
    {
        int p=patition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
}

int main()
{
    int arr[]={3,1,4,1,5,9,2,6};
    int n=sizeof(arr)/sizeof(arr[0]);

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    return 0;
}