#include <bits/stdc++.h>
using namespace std;

const int INF = 1e12;
const int N = 5e3 + 10;
int n;
double x[N], y[N];
double dis[N];
bool vis[N];
double ans;

double get(double x1x, double y1y, double x2x, double y2y) { return sqrt(abs(x1x - x2x) * abs(x1x - x2x) + abs(y1y - y2y) * abs(y1y - y2y)); }

void prim() {
    dis[1] = 0;
    vis[1] = 1;

    double mi = INF;
    int cnt = 1;
    for (int i = 1; i <= n; i++) {
        mi = INF, cnt = 1;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && dis[j] < mi)
                mi = dis[j], cnt = j;

        vis[cnt] = 1;
        ans += dis[cnt];

        for (int j = 1; j <= n; j++) dis[j] = min(dis[j], get(x[cnt], y[cnt], x[j], y[j]));
    }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
        dis[i] = INF;
    }

    prim();
    printf("%.2f", ans);

    return 0;
}
