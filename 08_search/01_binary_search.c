#include <stdio.h>

int bin_search(int* a,int n,int key)
{
    int low,high,mid;
    low=1;
    high=n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(key<a[mid])
        high=mid-1;
        else if(key>a[mid])
        low=mid+1;
        else
        return mid;
    }
    return 0;
}

int main()
{
    int a[]={0,1,2,3,4,5,6,7,8,9};
    int n=9;
    int key=5;
    int res=bin_search(a,n,key);
    printf("%d\n",res);

    return 0;
}