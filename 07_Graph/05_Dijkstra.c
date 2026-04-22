#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define N 105
#define INF 0x3f3f3f3f

int g[N][N];
int dist[N];
int vis[N];
int n, m, start;

void dijkstra()
{
	memset(dist, INF, sizeof(dist));
	dist[start] = 0;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
			if (!vis[j] && (t == -1 || dist[j] < dist[t]))
				t = j;

		vis[t] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && g[t][j] != INF)
				if (dist[j] > dist[t] + g[t][j]) 
					dist[j] = dist[t] + g[t][j];
		}
	}
}

int main()
{
	memset(g, INF, sizeof(g));
	scanf("%d %d %d", &n, &m, &start);
	for (int i = 0; i < m; i++ )
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		g[a][b] = w;
	}

	dijkstra();
	for (int i = 1; i <= n; i++)
		printf("%d\n", dist[i]);

	return 0;
}