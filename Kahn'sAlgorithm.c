#include <stdio.h>
#define MAX 100

int main() {
    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX];
    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int indegree[MAX] = {0};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (adj[i][j] == 1)
                indegree[j]++;

    int queue[MAX], front = 0, rear = 0;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    int count = 0;
    int topo[MAX];

    while (front < rear) {
        int u = queue[front++];
        topo[count++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1) {
                indegree[v]--;
                if (indegree[v] == 0)
                    queue[rear++] = v;
            }
        }
    }

    if (count != n) {
        printf("Graph contains a cycle, topological sort not possible.\n");
    } else {
        printf("Topological Order: ");
        for (int i = 0; i < count; i++)
            printf("%d ", topo[i]);
        printf("\n");
    }

    return 0;
}