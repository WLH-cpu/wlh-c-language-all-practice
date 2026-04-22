#include <stdio.h>
#include <string.h>

#define MAXN 205
#define INF 0x3f3f3f3f

int dist[MAXN][MAXN];
int n, m;

void floyd() {
    for (int k = 1; k <= n; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    if (dist[i][j] > dist[i][k] + dist[k][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
}

int main()
{
    memset(dist, 0x3f, sizeof(dist));
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        dist[u][v] = w;
        dist[v][u] = w;
    }

    floyd();

    if (dist[1][n] == INF)
        printf("-1\n");
    else
        printf("%d\n", dist[1][n]);

    return 0;
}