#include <stdio.h>
#include <stdlib.h>

#define N 105
#define M 10005
typedef struct
{
	int u, v, w;
}Edge;

Edge edge[M];
int fa[N];
int n, m;

int find(int x)
{
	if (fa[x] != x)
		fa[x] = find(fa[x]);
	return fa[x];
}

int cmp(const void* a, const void* b)
{
	Edge* e1 = (Edge*)a;
	Edge* e2 = (Edge*)b;
	return e1->w - e2->w;
}

int kruskal()
{
	int res = 0;
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		fa[i] = i;
	qsort(edge, m, sizeof(Edge), cmp);
	for (int i = 0; i < m && cnt < n - 1; i++)
	{
		int u = edge[i].u;
		int v = edge[i].v;
		int w = edge[i].w;
		int fu = find(u);
		int fv = find(v);
		if (fu != fv)
		{
			fa[fu] = fv;
			res += w;
			cnt++;
		}
	}
	return res;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
	printf("%d\n", kruskal());

	return 0;
}