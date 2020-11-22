#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const ll MOD = 1000000007;
ll n, a, b;

ll fastpow(ll, ll);

ll choose(ll n, ll r) {
    ll ans = 1;
    for(ll i = 1; i <= r; ++i) {
        ans *= n - r + i;
        ans %= MOD;
        ans *= fastpow(i, MOD - 2);
        ans %= MOD;
    }

    return (ans%MOD + MOD)%MOD;
}

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2 == 0) return (recurse * recurse + MOD)%MOD;
    return ((recurse * recurse)%MOD * x + MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> a >> b;

    cout << ((((fastpow(2, n) - choose(n, a) + MOD)%MOD - choose(n, b) + MOD)%MOD - 1 + MOD)%MOD + MOD)%MOD << '\n';
    return 0;
}