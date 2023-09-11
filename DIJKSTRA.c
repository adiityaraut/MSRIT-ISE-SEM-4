#include<stdio.h>
int visited[10],dist[10];
void dijkstra(int graph[10][10],int n,int source){
    int u,v;
    //sabse pehele dono arrays ko initialise kardo
    for(int i=0;i<n;i++){
        visited[i]=0;
        dist[i]=graph[source][i]; //saari values daaldo usme source node vali
    }
    visited[source]=1; // mark source as visited
    int ne=0;
    //saari edges cover honi hai
    for(ne=0;ne<n;ne++){
        int min=999;
        for(int i=0;i<n;i++){
            if(visited[i]==0 && dist[i]<min){// minm value find karne ke liye
                min=dist[i]; //update minimum value
                u=i; //node jaha minimum value haii
            }
        }
        visited[u]=1;//mark the node with minimum distance as visited
        for(v=0;v<n;v++){
            if(visited[v]==0 && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
}
int main(){
    int graph[10][10],n,source=0;
    printf("Enter the no of nodes:\t");
    scanf("%d",&n);
    printf("\nEnter the weighted graph:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]); // Input the graph weights
        }
    }
    dijkstra(graph,n,source);
     printf("...........shortest path from source to all other node..........\n");
    for(int i=0;i<n;i++)
    {
        printf("%d-------->%d= %d \n",source,i,dist[i]);
    }
    return 0;
}