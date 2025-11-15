#include <stdio.h>
#define max 20

int p[max];

int find(int x) {
    while(p[x] != -1) x = p[x];
    return x;
}

void join(int x,int y) {
    int a = find(x);
    int b = find(y);
    p[a] = b;
}

int main() {
    int n,i,j,u,v,c[max][max],cost=0,e=1;

    printf("vertices: ");
    scanf("%d",&n);

    printf("matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++) {
            scanf("%d",&c[i][j]);
            if(c[i][j]==0) c[i][j]=999;
        }

    for(i=0;i<n;i++) p[i]=-1;

    printf("\nmst edges:\n");
    while(e<n) {
        int min=999;
        u=v=-1;

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(c[i][j]<min) {
                    min=c[i][j];
                    u=i;
                    v=j;
                }

        if(find(u)!=find(v)) {
            printf("%d-%d(%d)\n",u+1,v+1,min);
            cost+=min;
            join(u,v);
            e++;
        }

        c[u][v]=c[v][u]=999;
    }

    printf("\ntotal=%d\n",cost);
    return 0;
}
