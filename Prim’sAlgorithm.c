#include <stdio.h>
#include <limits.h>

#define MAX 100

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    int key[n], parent[n], mstSet[n];
    for (int i = 0; i < n; i++) {
        key[i] = INT_MAX;
        mstSet[i] = 0;
    }
    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n - 1; count++) {
        int min = INT_MAX, u;
        for (int v = 0; v < n; v++)
            if (!mstSet[v] && key[v] < min) {
                min = key[v];
                u = v;
            }
        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
    }

    printf("Prim MST:\n");
    for (int i = 1; i < n; i++)
        printf("%d - %d (%d)\n", parent[i], i, graph[i][parent[i]]);
    return 0;
}