#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 100000 + 10, M = 200000 + 10;

struct Edge {
	int u, v, w;
	bool operator < (const Edge &E)const
	{
		return w < E.w;
	}
}edge[M];
int fa[N];
int n, m, cnt, ans;

int find(int x)
{
	if (fa[x] == x)return x;
	else return fa[x] = find(fa[x]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)fa[i] = i;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c; scanf("%d%d%d", &a, &b, &c);
		edge[i].u = a; edge[i].v = b; edge[i].w = c;
	}
	sort(edge + 1, edge + m + 1);
	for (int i = 1; i <= m; i++)
	{
		int u = find(edge[i].u), v = find(edge[i].v), w = edge[i].w;
		if (u != v)
		{
			cnt++;
			fa[u] = v;
			ans += w;
		}
	}
	if (cnt == n - 1)printf("%d\n", ans);
	else printf("impossible\n");
	return 0;
}