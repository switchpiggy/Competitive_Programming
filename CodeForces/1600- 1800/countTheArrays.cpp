#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

const ll MOD = 998244353;

ll fastpow(ll x, ll y) {
    if(y == 0) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2 == 0) return (recurse * recurse)%MOD;
    return ((recurse * recurse)%MOD * x)%MOD;
}

ll choose(ll n, ll r) {
    ll ans = 1;
    for(ll i = 1; i <= r; ++i) {
        ans *= (n - r + i);
        ans %= MOD;
        ans *= fastpow(i, MOD - 2);
        ans %= MOD;
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    if(n == 2) {
        cout << (((choose(m, n - 1)%MOD * (n - 2)%MOD)%MOD)/2)%MOD << '\n';
        return 0;
    }

    cout << ((choose(m, n - 1)%MOD * (n - 2)%MOD)%MOD * fastpow(2, n - 3)%MOD)%MOD << '\n';
}