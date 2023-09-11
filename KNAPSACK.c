#include <stdio.h>
int profit[20],weight[20],table[20][20],capacity,selected[20]={0};
int max(int a,int b){
    if(a>b){
        return a;
    }
    else return b;
}
void knapsack(int n){
    for(int i=0;i<=n;i++){
        table[i][0]=0;
    }
    for(int i=0;i<=capacity;i++){
        table[0][i]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=capacity;j++){
            if(weight[i]<=j){
                table[i][j]=max(table[i-1][j],table[i-1][j-weight[i]]+profit[i]);
            }
            else{
                table[i][j]=table[i-1][j];
            }
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=capacity;j++){
           printf("%d\t",table[i][j]);
        }
        printf("\n");
    }
    int netCap=capacity;
    printf("\nThe items selectes are:\t");
    for(int i=n;i>=0 && netCap!=0;i--){
        if(table[i][netCap]!=table[i-1][netCap]){
            selected[i]=1;
            printf("%d ",i);
            netCap=netCap-weight[i];
        }
        else{
            selected[i]=0;
        }
    }
    int maxProfit=0;
    for(int i=1;i<=n;i++){
        if(selected[i]){
            maxProfit+=profit[i];
        }
    }
    printf("\nThe maximum profit is %d\n",maxProfit);
}
void main(){
     int n;
    printf("\nEnter the number of objects:\t");
    scanf("%d",&n);

    printf("Enter the profit and weight of each of the following item:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&profit[i]);
        scanf("%d",&weight[i]);
    }
    printf("\nEnter the capacity of the knapsack:\t");
    scanf("%d",&capacity);
    
    knapsack(n);
}