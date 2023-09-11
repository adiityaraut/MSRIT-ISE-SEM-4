#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void selection_sort(int a[],int n){
    for(int i=0;i<n;i++){
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int temp = a[i];
            a[i]=a[min];
            a[min]=temp;
    }
}
void random_array(int a[],int n){
    for(int i=0;i<n;i++){
        a[i]=rand()%n;
    }
}
void print_array(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
}
void main()
{
    int n,a[10000];
    clock_t start,end;
    double t;
    printf("Enter the value of n:\t");
    scanf("%d",&n);
    random_array(a,n);
    printf("\nRandom variables are:\n");
    print_array(a,n);
    start=clock();
    selection_sort(a,n);
    end=clock();
    printf("\n Sorted elements \n");
    print_array(a,n);
    t=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Time Taken:%d",t);


}