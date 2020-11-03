#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[300007];

const ll MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= 2 * n; ++i) {
        cin >> a[i];
    }

    sort(a + 1, a + 2 * n + 1);
    ll ans = 0, last = 0, first = 0;
    
    for(ll i = n + 1; i <= 2 * n; ++i) {
        last += a[i];
        last %= MOD;
    }

    for(ll i = 1; i <= n; ++i) {
        first += a[i];
        first %= MOD;
    }

    cout << last << ' ' << first << '\n';

    for(ll i = 1; i <= 2 * n; ++i) {
        if(i <= n) ans += (last - (n * a[i])%MOD + MOD)%MOD;
        else ans += ((n * a[i])%MOD - first + MOD)%MOD;

        ans %= MOD;
    }

    cout << ans%MOD << '\n';
    return 0;
}