#include <stdio.h>
#include <time.h>
void warshall(int graph[10][10],int n){
for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(graph[i][j]==1 ||(graph[i][k]==1 && graph[k][j]==1)){
                graph[i][j]=1;
            }
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
    printf("\nEnter the adjacency matrix\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    
    }
    start = clock();
    warshall(graph,n);
    end = clock();
    printf(".................Transitive Closure......................\n");
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