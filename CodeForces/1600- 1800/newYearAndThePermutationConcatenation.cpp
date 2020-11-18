#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, f[1000007];
const ll MOD = 998244353;

ll fastpow(ll x, ll y) {
    if(y == 0) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2 == 0) return (recurse * recurse)%MOD;
    return (x * (recurse * recurse)%MOD)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    f[0] = 1;
    for(ll i = 1; i <= n; ++i) {
        f[i] = (f[i - 1] * i)%MOD;
    }

    ll ans = f[n], cur = n;
    for(ll i = n - 1; i > 1; --i) {
        ans =  (ans + cur * (f[i] - 1)%MOD)%MOD;
        cur = (cur * i)%MOD;
    }

    cout << ans << '\n';
    return 0;
}