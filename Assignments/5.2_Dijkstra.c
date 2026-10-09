/*A transportation network contains cities connected by roads with different costs.
Write a C program implementing Dijkstra’s Shortest Path Algorithm 
that accepts the number of vertices,Create weighted adjacency matrix and source vertex,
computes the minimum distance from the source to every other vertex,
and displays each destination with its shortest distance.
Test it using at least five vertices. */
#include <stdio.h>
#define MAX 20
#define INF 9999
int graph[MAX][MAX];
int distance[MAX];
int visited[MAX];
int n;
void dijkstra(int source)
{
    int i, j, min, u;
    for(i = 0; i < n; i++)
    {
        distance[i] = INF;
        visited[i] = 0;
    }
    distance[source] = 0;
    for(i = 0; i < n; i++)
    {
        min = INF;
        u = -1;
        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 && distance[j] < min)
            {
                min = distance[j];
                u = j;
            }
        }
        if(u == -1)
            break;
        visited[u] = 1;
        for(j = 0; j < n; j++)
        {
            if(graph[u][j] != 0 &&
               visited[j] == 0 &&
               distance[u] + graph[u][j] < distance[j])
            {
                distance[j] = distance[u] + graph[u][j];
            }
        }
    }
}
int main()
{
    int i, j, source;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    printf("Enter the weighted adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the source vertex: ");
    scanf("%d", &source);
    dijkstra(source);
    printf("\nShortest distances from source:\n");
    for(i = 0; i < n; i++)
    {
        printf("Destination %d = %d\n", i, distance[i]);
    }
    return 0;
}
