#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, d[100007], a[100007];

bool check(ll x) {
    vector<ll> latest(m + 1, -1);
    ll days = 0;

    for(ll i = x; i >= 1; --i) {
        if(d[i] && latest[d[i]] == -1) latest[d[i]] = i;
    }

    for(ll i = 1; i <= m; ++i) if(latest[i] == -1) return 0;

    for(ll i = 1; i <= x; ++i) {
        if(d[i] && latest[d[i]] == i) {
            if(days < a[d[i]]) return 0;
            days -= a[d[i]];
        } else days++;
    }

    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(ll i = 1; i <= n; ++i) cin >> d[i];
    for(ll i = 1; i <= m; ++i) cin >> a[i];

    ll l = 0, r = n + 1, ans = LONG_LONG_MAX;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            r = mid;
        } else l = mid + 1;
    }

    if(ans == LONG_LONG_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
}