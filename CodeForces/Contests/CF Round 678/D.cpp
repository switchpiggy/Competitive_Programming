#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, pos, f[100007];

const ll MOD = 1000000007;

ll fact(ll x) {
    return f[x];
}

ll fastpow(ll x, ll y) {
    if(y == 1) return x;
    if(y == 0) return 1;

    ll recurse = fastpow(x, y/2)%MOD;
    if(y%2 == 0) return (recurse * recurse)%MOD;
    return ((recurse * recurse)%MOD * x)%MOD;
}

ll choose(ll x, ll r) {
    if(r > x) return 0;

    return ((f[x] * fastpow(f[r], MOD - 2)%MOD)%MOD * fastpow(f[x - r], MOD - 2)%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    f[0] = 1;
    for(ll i = 1; i <= 100000; ++i) f[i] = (f[i - 1] * i)%MOD;

    cin >> n >> x >> pos;

    ll greater = 0, less = 0, l = 0, r = n;

    while(l < r) {
        ll m = (l + r)/2;
        if(m <= pos) {
            l = m + 1;
            if(m != pos) less++;
        } else {
            r = m;
            greater++;
        }
    }

    //cout << n - x << ' ' << x - 1 << ' ' << greater << ' ' << less << '\n';

    cout << choose(x - 1, less)%MOD * choose(n - x, greater)%MOD * f[greater]%MOD * f[less]%MOD * f[n - greater - less - 1]%MOD << '\n';
    return 0;
}