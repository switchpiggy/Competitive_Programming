#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, s, t, g[200007];
vector<pair<ll, ll>> v;

bool check(ll x) {
    ll res = 0;
    if(g[0] > x || s - g[k - 1] > x) return 0; 
    res += 2 * g[0] - min(g[0], x - g[0]);
    res += 2 * (s - g[k - 1]) - min(s - g[k - 1], x - (s - g[k - 1]));
    for(ll i = 1; i < k; ++i) {
        if(g[i] - g[i - 1] > x) return 0;
        res += 2 * (g[i] - g[i - 1]) - min(g[i] - g[i - 1], x - (g[i] - g[i - 1]));
    }

    return res <= t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k >> s >> t;
    for(ll i = 0; i < n; ++i) {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    for(ll i = 0; i < k; ++i) cin >> g[i];
    sort(g, g + k);

    ll ans = -1, l = 0, r = s + 1;
    while(l < r) {
        ll m = (l + r)/2;
        //cout << m << ' ';
        if(check(m)) {
            ans = m;
            r = m;
        } else l = m + 1;
    }

    if(ans == -1) {
        cout << "-1\n";
        return 0;
    }

    //cout << check(7) << '\n';

    ll ans2 = LONG_LONG_MAX;
    for(ll i = 0; i < n; ++i) {
        if(v[i].second >= ans) ans2 = min(ans2, v[i].first);
    }

    //cout << ans << '\n';
    if(ans2 == LONG_LONG_MAX) ans2 = -1;
    cout << ans2 << '\n';
    return 0;
}