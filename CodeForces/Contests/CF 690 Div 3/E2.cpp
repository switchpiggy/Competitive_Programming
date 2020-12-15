#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, m, k, a[200007], choose[200007][107];
const ll MOD = 1e9 + 7;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return ((recurse * recurse)%MOD * x)%MOD;
    return (recurse * recurse)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(ll i = 1; i <= 200000; ++i) {
        for(ll j = 1; j <= 100; ++j) {
            if(j == i || j == 1) {
                choose[i][j] = 1;
            } else choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1])%MOD;
            //cout << choose[i][j] << ' ';
        }
    }
    while(t--) {
        cin >> n >> m >> k;
        for(ll i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);

        ll ans = 0;
        for(ll i = 0; i < n; ++i) {
            ll j = upper_bound(a, a + n, a[i] + k) - a;
            j--;
            //cout << i << ' ' << j << '\n';
            if(j - i + 1 < m) continue;
            ans += choose[j - i + 1][m - 1 + 1];
            ans %= MOD;
        }

        cout << ans << '\n';
    }
    
    return 0;
}