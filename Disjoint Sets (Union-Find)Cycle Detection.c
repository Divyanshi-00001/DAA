#include <stdio.h>

#define MAX 100

int parent[MAX];

int find(int i) {
    if (parent[i] == -1)
        return i;
    return find(parent[i]);
}

void unionSet(int x, int y) {
    int xset = find(x);
    int yset = find(y);
    if (xset != yset)
        parent[xset] = yset;
}

int main() {
    int edges, u, v;
    printf("Enter number of vertices: ");
    int n; scanf("%d", &n);

    for (int i = 0; i < n; i++) parent[i] = -1;

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int cycle = 0;
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        int x = find(u), y = find(v);
        if (x == y) {
            cycle = 1;
            break;
        }
        unionSet(x, y);
    }

    if (cycle) printf("Graph contains cycle\n");
    else printf("Graph does not contain cycle\n");
    return 0;
}