#include <stdio.h>
int visited[20];
int graph[10][10],n;
void BFS(int start_node){
    int u,v;
    for(int i=0;i<n;i++){
        visited[i]=0; //abhi koi visited nahi haii
    }
    visited[start_node]=1; //sabse pehele start node ko visited
    int q[20];
    int r=-1,f=0;
    q[++r]=start_node;
    while(r>=f){
        u=q[f++];
        printf("BFS--->%d\t",u);
        for(int v=0;v<n;v++){
            if(graph[u][v]==1 && visited[v]==0){
                q[++r]=v;
                visited[v]=1;
            }
        }
    }

}
int main()
{
    int start_node=0;
    printf("Enter number of node=");
    scanf("%d",&n);
    printf("\n Enter weighted graph\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    printf("..................BFS Traversal..............\n");
    BFS(start_node);
    
    return 0;
}
