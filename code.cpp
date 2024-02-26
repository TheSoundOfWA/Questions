#include <bits/stdc++.h>
#define FOR(a, b, c) for(int a = b; a <= c; a++)
using namespace std;

const int N = 5e3 + 10;
int p[N];
int sum[N];
int dp[N][N];

int main() {
    int n, m, k; scanf("%d%d%d", &n, &m, &k);
    FOR(i, 1, n) scanf("%d", &p[i]);

    FOR(i, 1, n) sum[i] = sum[i - 1] + p[i];

    FOR(i, 1, k)
        FOR(j, m, n)
            dp[i][j] = max(dp[i][j - 1], dp[i][j - m] + sum[j] - sum[j - m]);

    int ans = 0;
    FOR(i, 1, n) ans = max(ans, dp[k][i]);
    printf("%d", ans);

    return 0;
}
