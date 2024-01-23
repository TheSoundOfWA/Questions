#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;
const int N = 310, M = 4;
int n, m;
bool mp[N][N];
int sx, sy, tx, ty;
int dx[M] = {0, 0, -1, 1};
int dy[M] = {-1, 1, 0, 0};
queue<pair<int, int> > q;
int ans = 0;

void solve1() {
    q = queue<pair<int, int> >();
    q.push(make_pair(sx, sy));

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if (u.first == tx && u.second == ty) {
            ans = (ans + 1) % Mod;
            continue;
        }

        pair<int, int> v1 = make_pair(u.first + dx[0], u.second + dy[0]);
        if (mp[v1.first][v1.second] && u.first >= tx && u.second >= ty) q.push(v1);

        pair<int, int> v2 = make_pair(u.first + dx[2], u.second + dy[2]);
        if (mp[v2.first][v2.second] && u.first >= tx && u.second >= ty) q.push(v2);
    }
}

void solve2() {
    q = queue<pair<int, int> >();
    q.push(make_pair(sx, sy));

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if (u.first == tx && u.second == ty) {
            ans = (ans + 1) % Mod;
            continue;
        }

        pair<int, int> v1 = make_pair(u.first + dx[1], u.second + dy[1]);
        if (mp[v1.first][v1.second] && u.first >= tx && u.second <= ty) q.push(v1);

        pair<int, int> v2 = make_pair(u.first + dx[2], u.second + dy[2]);
        if (mp[v2.first][v2.second] && u.first >= tx && u.second <= ty) q.push(v2);
    }
}

void solve3() {
    q = queue<pair<int, int> >();
    q.push(make_pair(sx, sy));

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if (u.first == tx && u.second == ty) {
            ans = (ans + 1) % Mod;
            continue;
        }

        pair<int, int> v1 = make_pair(u.first + dx[0], u.second + dy[0]);
        if (mp[v1.first][v1.second] && u.first <= tx && u.second >= ty) q.push(v1);

        pair<int, int> v2 = make_pair(u.first + dx[3], u.second + dy[3]);
        if (mp[v2.first][v2.second] && u.first <= tx && u.second >= ty) q.push(v2);
    }
}

void solve4() {
    q = queue<pair<int, int> >();
    q.push(make_pair(sx, sy));

    while (!q.empty()) {
        pair<int, int> u = q.front();
        q.pop();

        if (u.first == tx && u.second == ty) {
            ans = (ans + 1) % Mod;
            continue;
        }

        pair<int, int> v1 = make_pair(u.first + dx[1], u.second + dy[1]);
        if (mp[v1.first][v1.second] && u.first <= tx && u.second <= ty) q.push(v1);

        pair<int, int> v2 = make_pair(u.first + dx[3], u.second + dy[3]);
        if (mp[v2.first][v2.second] && u.first <= tx && u.second <= ty) q.push(v2);
    }
}

int main() {
    memset(mp, 1, sizeof mp);

    int k, q;
    scanf("%d%d%d%d", &n, &m, &k, &q);
    for (int i = 1; i <= k; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        mp[x][y] = 0;
    }

    while (q--) {
        ans = 0;

        scanf("%d%d%d%d", &sx, &sy, &tx, &ty);

        if (!mp[sx][sy] || !mp[tx][ty]) ans = 0;
        else if (sx == tx) {
            bool f = 1;
            for (int y = min(sy, ty); y <= max(sy, ty); y++)
                if (!mp[sx][y]) {
                    ans = 0;
                    f = 0;
                    break;
                }
            if (f) ans = 1;
        } else if (sy == ty) {
            bool f = 1;
            for (int x = min(sx, tx); x <= max(sx, tx); x++)
                if (!mp[x][sy]) {
                    ans = 0;
                    f = 0;
                    break;
                }
            if (f) ans = 1;
        } else if (sx > tx && sy > ty) solve1();
        else if (sx > tx && sy < ty) solve2();
        else if (sx < tx && sy > ty) solve3();
        else if (sx < tx && sy < ty) solve4();

        printf("%d\n", ans % Mod);
    }

    return 0;
}
