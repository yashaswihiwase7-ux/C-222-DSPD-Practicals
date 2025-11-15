#include <stdio.h>

int g[20][20], vis[20];

void bfs(int s, int n){
    int q[50], f = 0, r = 0;
    q[r++] = s;
    vis[s] = 1;

    printf("BFS: ");
    while(f < r){
        int x = q[f++];
        printf("%d ", x);

        for(int i = 1; i <= n; i++){
            if(g[x][i] && !vis[i]){
                vis[i] = 1;
                q[r++] = i;
            }
        }
    }
}

void dfs(int s, int n){
    printf("%d ", s);
    vis[s] = 1;

    for(int i = 1; i <= n; i++){
        if(g[s][i] && !vis[i]){
            dfs(i, n);
        }
    }
}

int main(){
    int n, s;

    printf("N: ");
    scanf("%d", &n);

    printf("Mat:\n");
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            scanf("%d", &g[i][j]);

    printf("Start: ");
    scanf("%d", &s);

    bfs(s, n);

  
    for(int i = 1; i <= n; i++)
        vis[i] = 0;

    printf("\nDFS: ");
    dfs(s, n);

    return 0;
}
