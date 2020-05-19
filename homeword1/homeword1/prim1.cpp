#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 500 + 10;
int n, m;
int g[N][N], dis[N], vis[N];


void prim()
{
	memset(dis, 0x1f, sizeof dis);
	dis[1] = 0;
	for (int j = 1; j <= n; j++)
	{
		int min_len = 2e+9, k;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i] && dis[i] < min_len)
			{
				min_len = dis[i];
				k = i;
			}
		}
		vis[k] = 1;
		for (int i = 1; i <= n; i++)
		{
			if (!vis[i] && dis[i] > g[k][i])
				dis[i] = g[k][i];
		}
	}

}

int main()
{
	scanf("%d%d", &n, &m);
	memset(g, 0x1f, sizeof g);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		g[u][v] = g[v][u] = min(g[u][v], w);  //因为有重边，所以取min
	}
	prim();
	int ans = 0;
	for (int i = 1; i <= n; i++)ans += dis[i];
	if (ans > 1e7)printf("impossible\n");
	else printf("%d\n", ans);
	return 0;
}