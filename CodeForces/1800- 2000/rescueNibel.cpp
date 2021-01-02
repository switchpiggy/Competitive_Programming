#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, l, r, fact[300007];
vector<pair<ll, ll>> v;

const ll MOD = 998244353;

ll fastpow(ll x, ll y) {
    if(!y) return 1;

    ll recurse = fastpow(x, y/2);
    if(y%2) return ((recurse * recurse)%MOD * x)%MOD;
    return (recurse * recurse)%MOD;
}

ll inv(ll x) {
    return fastpow(x, MOD - 2);
}

ll choose(ll n, ll r) {
    return ((fact[n] * inv(fact[r]))%MOD * inv(fact[n - r])%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        cin >> l >> r;
        v.push_back({l, 1ll});
        v.push_back({r, 2ll});
    }

    fact[0] = 1;
    for(ll i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i)%MOD;

    sort(v.begin(), v.end());

    ll cnt = 0, ans = 0;
    for(ll i = 0; i < 2 * n; ++i) {
        if(v[i].second == 1) {
            cnt++;
            continue;
        }

        if(cnt >= k) ans = (ans + choose(cnt - 1, k - 1))%MOD;

        if(v[i].second == 2) cnt--;
    }

    cout << ans << '\n';
    return 0;
}