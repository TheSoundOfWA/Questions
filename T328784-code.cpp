#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll Mod = 998244353;
const int N = 310;
bool mp[N][N];
ll ans[N][N];

int main() {
    memset(mp, 1, sizeof mp);

    int n, m, k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        mp[x][y] = 0;
    }

    while (q--) {
        memset(ans, 0, sizeof ans);

        int sx, sy, tx, ty;
        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);

        if (!mp[sx][sy] || !mp[tx][ty]) printf("%d\n", 0);
        else if (sx == tx) {
            bool f = 1;
            for (int y = min(sy, ty); y <= max(sy, ty); y++)
                if (!mp[sx][y]) {
                    printf("%d\n", 0);
                    f = 0;
                    break;
                }
            if (f) printf("%d\n", 1);
        } else if (sy == ty) {
            bool f = 1;
            for (int x = min(sx, tx); x <= max(sx, tx); x++)
                if (!mp[x][sy]) {
                    printf("%d\n", 0);
                    f = 0;
                    break;
                }
            if (f) printf("%d\n", 1);
        } else if (sx > tx && sy > ty) {
            for (int i = sx; i >= tx; i--) {
                if (i == sx) ans[i][sy] = 1;
                else ans[i][sy] = (ans[i + 1][sy] == 1);

                for (int j = sy - 1; j >= ty; j--) {
                    if (!mp[i][j]) continue;

                    if (mp[i + 1][j]) ans[i][j] += (ans[i + 1][j] % Mod);
                    if (mp[i][j + 1]) ans[i][j] += (ans[i][j + 1] % Mod);

                    ans[i][j] %= Mod;
                }
            }

            printf("%lld\n", ans[tx][ty] % Mod);
        } else if (sx > tx && sy < ty) {
            for (int i = sx; i >= tx; i--) {
                if (i == sx) ans[i][sy] = 1;
                else ans[i][sy] = (ans[i + 1][sy] == 1);

                for (int j = sy + 1; j <= ty; j++) {
                    if (!mp[i][j]) continue;

                    if (mp[i + 1][j]) ans[i][j] += (ans[i + 1][j] % Mod);
                    if (mp[i][j - 1]) ans[i][j] += (ans[i][j - 1] % Mod);

                    ans[i][j] %= Mod;
                }
            }

            printf("%lld\n", ans[tx][ty] % Mod);
        } else if (sx < tx && sy > ty) {
            for (int i = sx; i <= tx; i++) {
                if (i == sx) ans[i][sy] = 1;
                else ans[i][sy] = (ans[i - 1][sy] == 1);

                for (int j = sy - 1; j >= ty; j--) {
                    if (!mp[i][j]) continue;

                    if (mp[i - 1][j]) ans[i][j] += (ans[i - 1][j] % Mod);
                    if (mp[i][j + 1]) ans[i][j] += (ans[i][j + 1] % Mod);

                    ans[i][j] %= Mod;
                }
            }

            printf("%lld\n", ans[tx][ty] % Mod);
        } else if (sx < tx && sy < ty) {
            for (int i = sx; i <= tx; i++) {
                if (i == sx) ans[i][sy] = 1;
                else ans[i][sy] = (ans[i - 1][sy] == 1);

                for (int j = sy + 1; j <= ty; j++) {
                    if (!mp[i][j]) continue;

                    if (mp[i - 1][j]) ans[i][j] += (ans[i - 1][j] % Mod);
                    if (mp[i][j - 1]) ans[i][j] += (ans[i][j - 1] % Mod);

                    ans[i][j] %= Mod;
                }
            }

            printf("%lld\n", ans[tx][ty] % Mod);
        }
    }

    return 0;
}
