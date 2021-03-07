#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll x, y;
const ll MOD = 1000000007;

ll fastpow(ll x, ll y) {
    if(y == 0) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return ((recurse * recurse)%MOD * x)%MOD;
    return (recurse * recurse)%MOD;
}

ll inv(ll x) {
    return fastpow(x, MOD - 2)%MOD;
}

ll choose(ll n, ll r) {
    ll ans = 1;
    for(ll i = 1; i <= r; ++i) {
        ans *= n - r + i;
        ans %= MOD;
        ans *= inv(i);
        ans %= MOD;
    }

    return ans%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> x >> y;
    ll ans = 0;
    ll i = y%2;
    for(; i <= y; i += 2) {
        ll cur = (y - i)/2;
        if(i * 2 + cur == x) {
            ans += choose(cur + i, i);
            ans %= MOD;
        }
    }

    cout << ans%MOD << '\n';
    return 0;
}