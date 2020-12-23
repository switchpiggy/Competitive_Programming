#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, pref[1000007], suf[1000007], mins[1000007];
bool v[1000007];
vector<ll> t[1000007], c[1000007], f[1000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(ll i = 0; i < m; ++i) {
        ll x, y, z, a;
        cin >> x >> y >> z >> a;
        t[x].push_back(z);
        f[x].push_back(y);
        c[x].push_back(a);
    }

    ll sum = 0;
    for(ll i = 1; i <= n; ++i) {
        mins[i] = INT_MAX;
        sum += INT_MAX;
    }

    ll cur = 0;
    for(ll i = 1; i <= 1e6; ++i) {
        for(ll j = 0; j < (ll)f[i].size(); ++j) {
            ll x = f[i][j], z = c[i][j];
            if(!x) continue;
            if(!v[x]) cur++;
            v[x] = 1;
            if(z < mins[x]) sum += z - mins[x];
            mins[x] = min(mins[x], z);
        }

        if(cur >= n) pref[i] = sum;
        else pref[i] = -1;
    }

    sum = 0;
    for(ll i = 1; i <= n; ++i) {
        mins[i] = INT_MAX;
        sum += INT_MAX;
        v[i] = 0;
    }

    cur = 0;
    for(ll i = 1e6; i >= 1; --i) {
        for(ll j = 0; j < (ll)f[i].size(); ++j) {
            ll x = t[i][j], z = c[i][j];
            if(!x) continue;
            if(!v[x]) cur++;
            v[x] = 1;
            if(z < mins[x]) sum += z - mins[x];
            mins[x] = min(mins[x], z);
        }

        if(cur >= n) suf[i] = sum;
        else suf[i] = -1;
    }

    ll ans = LLONG_MAX;
    for(ll i = 1; i <= 1e6; ++i) {
        if(i + k + 1 > 1e6) continue;
        if(pref[i] == -1 || suf[i + k + 1] == -1) continue;
        ans = min(ans, pref[i] + suf[i + k + 1]);
    }

    if(ans == LLONG_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
}