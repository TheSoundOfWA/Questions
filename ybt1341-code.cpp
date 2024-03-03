#include <bits/stdc++.h>
#define FOR(type, a, b, c) for(type a = b; a <= c; a++)
#define pb push_back
#define PII pair<int, int>
#define mp make_pair
#define fst first
#define sec second
using namespace std;

const int N = 1e3 + 10, M = 1e5 + 10;
vector<PII> G[N];
int d[N];
bool vis[M];

void dfs(int x) {
    printf("%d ", x);

    for (PII pir : G[x]) {
        if (vis[pir.sec]) continue;
        vis[pir.sec] = 1;
        dfs(pir.fst);
    }
}

int main() {
    int n, m; scanf("%d%d", &n, &m);
    FOR(int, i, 1, m) {
        int u, v; scanf("%d%d", &u, &v);

        G[u].pb(mp(v, i));
        G[v].pb(mp(u, i));
        d[u]++; d[v]++;
    }

    FOR(int, i, 1, n)
        if (d[i] & 1) {
            dfs(i);
            return 0;
        }
    dfs(1);

    return 0;
}
