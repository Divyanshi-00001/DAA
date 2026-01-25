#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int n, e;
    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    struct Edge edges[e];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    int src;
    printf("Enter source vertex: ");
    scanf("%d", &src);

    int dist[n];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[src] = 0;

    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < e; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Check for negative cycles
    for (int j = 0; j < e; j++) {
        int u = edges[j].u, v = edges[j].v, w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains negative weight cycle\n");
            return 0;
        }
    }

    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", src, i, dist[i]);
    return 0;
}