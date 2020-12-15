#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a, b, x, n, ans;
const ll MOD = 1e9 + 7;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    return ((y%2 == 0) ? (recurse * recurse)%MOD : ((recurse * recurse)%MOD * x)%MOD);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b >> n >> x;
    if(!n) {
        cout << x << '\n';
        return 0;
    }

    if(a == 1) {
        cout << ((x%MOD) + ((n%MOD) * (b%MOD))%MOD)%MOD << '\n';
        return 0;
    }

    if(n == 1) {
        cout << ((a%MOD * x%MOD)%MOD + b%MOD)%MOD << '\n';
        return 0;
    }

    ll p1 = (fastpow(a, n) * ((x + ((b * fastpow(a - 1, MOD - 2))%MOD))%MOD))%MOD;
    ll p2 = (b * fastpow(1 - a, MOD - 2))%MOD;
    cout << (p1 + p2 + MOD)%MOD;
    return 0;
}