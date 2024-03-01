#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10;
struct point { int x, y; } pt[N];
int cnt1[N], cnt2[N];

bool check(point a, point b, point c) {
	int x_1 = b.x - a.x;
	int y_1 = b.y - a.y;
	int x_2 = c.x - a.x;
	int y_2 = c.y - a.y;
	return (x_1 * y_2 - x_2 * y_1) == 0;
}

bool check2(point a, point b, point c, point d) {
	int x_1 = b.x - a.x;
	int y_1 = b.y - a.y;
	int x_2 = d.x - c.x;
	int y_2 = d.y - c.y;
	return (x_1 * y_2 - x_2 * y_1) == 0;
}

int main() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int y; scanf("%d", &y);
		pt[i] = (point){i, y};
	}
	
	bool ans = 0;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			
			int tot1 = 0, tot2 = 0;
			memset(cnt1, 0, sizeof cnt1); memset(cnt2, 0, sizeof cnt2);
			
			cnt2[++tot2] = i, cnt2[++tot2] = j;
			for (int k = 1; k <= n; k++) if (k != i && k != j) {
				if (!check(pt[i], pt[j], pt[k])) cnt1[++tot1] = k;
				else cnt2[++tot2] = k;
			}
			
			bool f = 1;
			for (int k = 3; k <= tot1; k++)
				if (!check(pt[cnt1[1]], pt[cnt1[2]], pt[cnt1[k]]))
					f = 0;
			
			if (tot1 && f && (tot1 == 1 ? 1 : check2(pt[cnt1[1]], pt[cnt1[2]], pt[cnt2[1]], pt[cnt2[2]]))) ans = 1;
		}
	printf("%s", (ans ? "Yes" : "No"));
	
	return 0;
}
