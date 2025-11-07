#include <stdio.h>

struct edge {
    int u, v, w;
};

int p[30];

int find(int i) {
    while (p[i] != i)
        i = p[i];
    return i;
}

void join(int i, int j) {
    int a = find(i);
    int b = find(j);
    p[a] = b;
}

int main() {
    struct edge e[30], t[30], tmp;
    int n, m, i, j, k = 0, c = 0;

    printf("enter no of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("enter edges (u v w):\n");
    for (i = 0; i < m; i++)
        scanf("%d %d %d", &e[i].u, &e[i].v, &e[i].w);

    for (i = 0; i < n; i++)
        p[i] = i;

    for (i = 0; i < m - 1; i++)
        for (j = 0; j < m - i - 1; j++)
            if (e[j].w > e[j + 1].w) {
                tmp = e[j];
                e[j] = e[j + 1];
                e[j + 1] = tmp;
            }

    for (i = 0; i < m; i++) {
        int a = find(e[i].u);
        int b = find(e[i].v);
        if (a != b) {
            t[k++] = e[i];
            join(a, b);
            c += e[i].w;
        }
    }

    printf("\nminimum spanning tree edges:\n");
    for (i = 0; i < k; i++)
        printf("%d - %d = %d\n", t[i].u, t[i].v, t[i].w);

    printf("total cost = %d\n", c);
    return 0;
}