#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, fence[5007], val[5007];
ll twocount[5007];
vector<pair<ll, ll>> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> q;
    for(ll i = 0; i < q; ++i) {
        ll l, r;
        cin >> l >> r;
        v.push_back({l, r});
        fence[l]++;
        fence[r + 1]--;
    }
    
    sort(v.begin(), v.end());

    ll sum = 0;
    for(ll i = 1; i <= n; ++i) {
        fence[i] += fence[i - 1];
        if(fence[i]) sum++;
    }
    //for(ll i = 1; i <= n; ++i) cout << fence[i] << ' ';
    for(ll i = 0; i < q; ++i) {
        for(ll j = v[i].first; j <= v[i].second; ++j) if(fence[j] == 1) val[i]++;
        //cout << val[i] << ' ';
    }

    for(ll i = 1; i <= n; ++i) twocount[i] = twocount[i - 1] + (fence[i] == 2);
    //for(ll i = 1; i <= n; ++i) cout << twocount[i] << ' ';

    ll ans = 0;
    for(ll i = 0; i < q; ++i) {
        for(ll j = i + 1; j < q; ++j) {
            ll res = sum - val[i] - val[j];
            if(v[i].second >= v[j].first) res -= twocount[min(v[j].second, v[i].second)] - twocount[v[j].first - 1];
            ans = max(ans, res);
        }
    }

    cout << ans << '\n';
    return 0;
}