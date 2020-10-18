#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, q, n;

ll fastpow(ll x, ll y) {
    if(y == 1) return x;
    if(y == 0) return 1;

    ll cur = fastpow(x, y/2);

    if(y%2 == 0) return cur * cur;
    return cur * cur * x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> q >> n;

        ll ans = 0;
        for(ll i = 1; i <= n; ++i) {
            if(!q) break;

            ll cur = min(q, fastpow(n, i));
            q -= cur;
            ans += cur * i;
        }

        cout << ans << '\n';
    }

    return 0;
}