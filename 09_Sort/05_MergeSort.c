#include <stdio.h>
#include <stdlib.h>

void merge(int arr[],int low,int mid,int high,int temp[])
{
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid&&j<=high)
    {
        if(arr[i]<=arr[j])
        temp[k++]=arr[i++];
        else
        temp[k++]=arr[j++];
    }
    while(i<=mid)
    temp[k++]=arr[i++];
    while(j<=high)
    temp[k++]=arr[j++];
    for(i=0;i<k;i++)
    {
        arr[low+i]=temp[i];
    }
}

void mergeSort(int arr[],int low,int high,int temp[])
{
    if(low<high)
    {
        int mid=(low+high)/2;
        mergeSort(arr,low,mid,temp);
        mergeSort(arr,mid+1,high,temp);
        merge(arr,low,mid,high,temp);
    }
}

void sort(int arr[],int n)
{
    int* temp=(int*)malloc(sizeof(int)*n);
    mergeSort(arr,0,n-1,temp);
    free(temp);
}

void printArr(int arr[],int n)
{
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int main()
{
    int arr[]={8,4,5,7,1,3,6,2};
    int n=sizeof(arr)/sizeof(arr[0]);

    printArr(arr,n);

    sort(arr,n);

    printArr(arr,n);

    return 0;
}