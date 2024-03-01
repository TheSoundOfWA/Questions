#include <bits/stdc++.h>
#define ll long long
#define FOR(type, a, b, c) for(type a = b; a <= c; a++)
using namespace std;

ll check(ll x) {
	ll ans = 0;
	FOR(ll, i, 2, sqrt(x)) {
		if (i * i * i > x) break;
		ans += x / (i * i * i);
	}
	return ans;
}

int main() {
	ll m; scanf("%lld", &m);
	
	ll l = 1, r = (ll)1e5;
	while (l < r) {
		ll mid = (l + r) / 2;
		if (check(mid) >= m) r = mid;
		else l = mid + 1;
	}
	
	if (check(r) == m) printf("%lld", r);
	else printf("-1");
	
	return 0;
}
