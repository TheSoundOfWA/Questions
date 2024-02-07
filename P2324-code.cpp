#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

const int N = 110;
int w[N], c[N];
int dp[N];
vector<int> v[N];

int main() {
    int v, n, t;
	scanf("%d%d%d", &v, &n, &t);
	for (int i = 1; i <= n; i++) {
        int p;
		scanf("%d%d%d", &w[i], &c[i], &p);
		v[p].push_back(i);
	}

	for (int i = 1; i <= t; i++)
		for (int j = v; j >= 0; j--)
			for (int k = 0; k < v[i].size(); k++)
				if (w[v[i][k]] <= j)
					dp[j] = max(dp[j], dp[j - w[v[i][k]]] + c[v[i][k]]);
	printf("%d", dp[v]);

	return 0;
}
