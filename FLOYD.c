#include <stdio.h>
#include <time.h>
int min(int x,int y)
{
    if(x < y)
    {
        return x; 
    }
    else
        return y;
}
void floyd(int graph[10][10],int n){
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
        }
    }
}
}
int main()
{
    int graph[10][10],n,source,i,j;
    clock_t start,end;
    double t;
    printf("Enter the number of nodes:\n");
    scanf("%d",&n);
    printf("\nEnter the weighted matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    
    }
    start = clock();
    floyd(graph,n);
    end = clock();
    printf(".................All pair shortest path......................\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",graph[i][j]);
        }
        printf("\n");
    }
    t= (double)((end - start)/CLOCKS_PER_SEC);
    printf("Warshall's Algo time: %d",t);
    return 0;
}