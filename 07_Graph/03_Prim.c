#include <stdio.h>
#include <string.h>

#define N 105
#define INF 0x3f3f3f3f

int g[N][N];
int dist[N];
int vis[N];
int n, m;

int prim()
{
	memset(dist, INF, sizeof(dist));
	dist[1] = 0;
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		int t = -1;
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && (t == -1 || dist[j] < dist[t]))
				t = j;
		}
		vis[t] = 1;
		res += dist[t];
		for (int j = 1; j <= n; j++)
		{
			if (!vis[j] && g[t][j] < dist[j])
				dist[j] = g[t][j];
		}
	}
	return res;
}

int main()
{
	memset(g, INF, sizeof(g));
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		scanf("%d %d %d", &a, &b, &w);
		g[a][b] = w;
		g[b][a] = w;
	}
	printf("%d\n", prim());

	return 0;
}