#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

int parent[MAX];

int find(int i) {
    if (parent[i] == -1) return i;
    return find(parent[i]);
}

void unionSet(int x, int y) {
    int xset = find(x), yset = find(y);
    if (xset != yset) parent[xset] = yset;
}

int main() {
    int n, e;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &e);

    struct Edge edges[e];
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);

    for (int i = 0; i < n; i++) parent[i] = -1;

    // Sort edges by weight
    for (int i = 0; i < e - 1; i++)
        for (int j = i + 1; j < e; j++)
            if (edges[i].w > edges[j].w) {
                struct Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }

    printf("Kruskal MST:\n");
    for (int i = 0; i < e; i++) {
        int x = find(edges[i].u);
        int y = find(edges[i].v);
        if (x != y) {
            printf("%d - %d (%d)\n", edges[i].u, edges[i].v, edges[i].w);
            unionSet(x, y);
        }
    }
    return 0;
}