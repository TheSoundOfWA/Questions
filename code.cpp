#include <bits/stdc++.h>
#define FOR(a, b, c) for(int a = b; a <= c; a++)
#define ll long long
using namespace std;

const ll inf = 0x3f3f3f3f3f3f3f3f;
const int N = 1e5 + 10, M = 2;
ll c[N];
string s[N];
ll dp[N][M];

int main() {
    int n; scanf("%d", &n);
    FOR(i, 1, n) scanf("%lld", &c[i]);
    FOR(i, 1, n) cin >> s[i];

    FOR(i, 1, n)
        FOR(j, 0, M - 1)
            dp[i][j] = inf;
    dp[1][0] = 0, dp[1][1] = c[1];
    FOR(i, 2, n) {
        if (s[i] > s[i - 1]) dp[i][0] = dp[i - 1][0];
        reverse(s[i - 1].begin(), s[i - 1].end());
        if (s[i] > s[i - 1]) dp[i][0] = min(dp[i][0], dp[i - 1][1]);
        reverse(s[i - 1].begin(), s[i - 1].end());

        reverse(s[i].begin(), s[i].end());
        if (s[i] > s[i - 1]) dp[i][1] = dp[i - 1][0] + c[i];
        reverse(s[i - 1].begin(), s[i - 1].end());
        if (s[i] > s[i - 1]) dp[i][1] = min(dp[i][1], dp[i - 1][1] + c[i]);
        reverse(s[i - 1].begin(), s[i - 1].end());
        reverse(s[i].begin(), s[i].end());
    }

    if (dp[n][0] == inf && dp[n][1] == inf) printf("-1");
    else if (dp[n][0] == inf) printf("%lld", dp[n][1]);
    else if (dp[n][1] == inf) printf("%lld", dp[n][0]);
    else printf("%lld", min(dp[n][1], dp[n][0]));

    return 0;
}
