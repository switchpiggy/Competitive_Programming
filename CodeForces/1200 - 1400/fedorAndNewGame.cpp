#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, x[1007], f;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    for(ll i = 0; i < m; ++i) cin >> x[i];
    cin >> f;

    ll ans = 0;
    for(ll i = 0; i < m; ++i) {
        ll res = 0;
        for(ll j = 0; j <= n; ++j) {
            if((x[i] & (1 << j))^(f & (1 << j))) res++;
        }

        if(res <= k) ans++;
    }

    cout << ans << '\n';
    return 0;
}