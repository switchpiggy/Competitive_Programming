#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
//hopefully getting a CP girlfriend soon
ll n, h, l, r, p[200007];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> h;
    for(ll i = 0; i < n; ++i) {
        cin >> l >> r;
        v.push_back({l, r});
    }

    p[0] = v[0].first;
    for(ll i = 1; i < n; ++i) {
        p[i] = p[i - 1] + (v[i].first - v[i - 1].second);
    }

    ll ans = INT_MIN;
    for(ll i = 0; i < n; ++i) {
        ll k = lower_bound(p, p + n, h + p[i]) - p;
        if(k == n) ans = max(ans, (h - p[n - 1] + p[i]) + v[n - 1].second - v[i].first);
        else ans = max(ans, v[k].first - (p[k] - (h + p[i])) - v[i].first);
        //cout << v[i].first << ' ' << ans << '\n';
    }

    cout << ans << '\n';
    return 0;
}