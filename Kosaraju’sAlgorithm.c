#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], n;

void dfs1(int v, int stack[], int *top) {
    visited[v] = 1;
    for (int i = 0; i < n; i++)
        if (adj[v][i] && !visited[i])
            dfs1(i, stack, top);
    stack[(*top)++] = v;
}

void dfs2(int v, int transpose[MAX][MAX]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++)
        if (transpose[v][i] && !visited[i])
            dfs2(i, transpose);
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    int stack[MAX], top = 0;
    for (int i = 0; i < n; i++) visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i, stack, &top);

    int transpose[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            transpose[i][j] = adj[j][i];

    for (int i = 0; i < n; i++) visited[i] = 0;

    printf("Strongly Connected Components:\n");
    for (int i = top - 1; i >= 0; i--) {
        if (!visited[stack[i]]) {
            dfs2(stack[i], transpose);
            printf("\n");
        }
    }
    return 0;
}