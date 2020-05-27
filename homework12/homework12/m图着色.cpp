#include <iostream>

#define MAX_N (100 + 5)
#define MAX_K (2500 + 5)
#define MAX_M (2500 + 5)

using namespace std;

struct Edge
{
	int to;
	int next;
};

int n, k, m;
int h[MAX_N], tot;
Edge e[MAX_K + MAX_K];
int c[MAX_N][MAX_M];
int ans;

inline void Add_Edge(int u, int v)
{
	e[++tot].to = v;
	e[tot].next = h[u];
	h[u] = tot;
	return;
}

void DFS(int u)
{
	if (u > n)
	{
		++ans;
		return;
	}
	for (register int i = 1; i <= m; ++i)
	{
		if (c[u][i]) continue;
		for (register int j = h[u]; j; j = e[j].next)
		{
			++c[e[j].to][i];
		}
		DFS(u + 1);
		for (register int j = h[u]; j; j = e[j].next)
		{
			--c[e[j].to][i];
		}
	}
	return;
}

int main()
{
	cin >> n >> k >> m;
	int u, v;
	for (register int i = 1; i <= k; ++i)
	{
		cin >> u >> v;
		Add_Edge(u, v);
		Add_Edge(v, u);
	}
	for (register int i = h[1]; i; i = e[i].next)
	{
		++c[e[i].to][1];
	}
	DFS(2);
	cout << ans * m;
	return 0;
}
