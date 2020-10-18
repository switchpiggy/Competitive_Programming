#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n;

const ll MOD = 1000000007;

ll fastpow(ll x, ll y) {
    if(y == 1) return x;
    if(y == 0) return 1;

    ll recurse = fastpow(x, y/2);
    if(y%2 == 0) return (recurse * recurse)%MOD;
    return (recurse * recurse * x)%MOD;
}

ll calc(ll x) {
    ll ans = fastpow(2, x);

    return ((ans%MOD * (ans + 1)%MOD) * fastpow(2, 1000000005)%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    cout << calc(n) << '\n';

    return 0;
}