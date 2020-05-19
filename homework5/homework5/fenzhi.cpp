#include<iostream>
#include<math.h>
#include<algorithm>
#include<float.h>
using namespace std;
const int maxn = 1e5 + 5;
struct node {
	double x, y;
}p[maxn], q[maxn];
bool cmp(node a, node b) {
	return a.x < b.x;
}
bool cmp1(node a, node b) {
	return a.y < b.y;
}
double solve_dis(node a, node b) {
	double x = (a.x - b.x) * (a.x - b.x);
	double y = (a.y - b.y) * (a.y - b.y);
	return sqrt(x + y);
}
double solve(node p[], int l, int r) {
	if (l == r)
		return FLT_MAX;
	if (r - l == 1)
		return solve_dis(p[l], p[r]);
	int mid = (l + r) / 2;
	double res = min(solve(p, l, mid), solve(p, mid + 1, r));
	int t = 0;
	for (int i = l; i <= r; i++) {
		if (fabs(p[i].x - p[mid].x) <= res)
			q[t++] = p[i];
	}
	sort(q, q + t, cmp1);
	for (int i = 0; i < t; i++) {
		for (int j = i + 1; j < t; j++) {
			if (q[j].y - q[i].y > res)
				break;
			res = min(res, solve_dis(q[i], q[j]));
		}
	}
	return res;
}
int main()
{
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> p[i].x >> p[i].y;
	sort(p, p + n, cmp);
	double ans = solve(p, 0, n - 1);
	cout << "最近点对的距离为：" << ans << endl;
	return 0;
}