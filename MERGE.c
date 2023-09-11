#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int a[],int low, int mid, int high)
{
    int temp[10000];
    int i=low;
    int j=mid+1;
    int k=low;
    while(i<=mid && j<=high){
        if(a[i]<=a[j])
        {
            temp[k++]=a[i++];
        }
        else{
            temp[k++]=a[j++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=high)
    {
        temp[k++]=a[j++];
    }
    for(int k=low;k<=high;k++)
    {
        a[k]=temp[k];
    }
}

void divide(int a[],int low,int high)
{
    if(low<high)
    {
       int mid=(low+high)/2;
       divide(a,low,mid);
       divide(a,mid+1,high);
       merge(a,low,mid,high);
    }
}
void main()
{
    int n,a[10000];
    clock_t start,end;
    double t;
    printf("Enter the value of n:\n");
    scanf("%d",&n);
    printf("Random variables are:\n");
    for(int k=0;k<n;k++)
    {
        a[k]=rand()%n;
        printf("   %d",a[k]);
    }
    start=clock();
    divide(a,0,n-1);
    end=clock();
    printf("\n Sorted elements \n");
    for(int i=0;i<n;i++){
        printf("   %d",a[i]);
    }
    t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken:%d",t);


}