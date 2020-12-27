#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[307], b[307];
vector<pair<ll, ll>> seg;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < m; ++i) {
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        seg.push_back({x, y});
    }

    ll ans = *max_element(a, a + n) - *min_element(a, a + n), ind = -1;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) b[j] = a[j];
        for(ll j = 0; j < m; ++j) {
            if(seg[j].first <= i && seg[j].second >= i) continue;
            for(ll k = seg[j].first; k <= seg[j].second; ++k) {
                b[k]--;
            }
        }

        ll maxn = INT_MIN, minn = INT_MAX;
        for(ll j = 0; j < n; ++j) {
            maxn = max(maxn, b[j]);
            minn = min(minn, b[j]);
        }

        if(maxn - minn > ans) {
            ans = maxn - minn;
            ind = i;
        }
    }

    cout << ans << '\n';
    vector<ll> res;
    for(ll j = 0; j < m; ++j) {
        if(ind == -1 || (seg[j].first <= ind && ind <= seg[j].second)) continue;
        res.push_back(j + 1);
    }

    cout << (ll)res.size() << '\n';
    for(ll i : res) cout << i << ' ';
    return 0;
}