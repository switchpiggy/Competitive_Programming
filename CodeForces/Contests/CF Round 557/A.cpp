#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, h, m, maxn[57];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(ll i = 1; i <= 56; ++i) maxn[i] = 1000;

    cin >> n >> h >> m;
    for(ll i = 0; i < m; ++i) {
        ll l, r, x;
        cin >> l >> r >> x;
        for(ll j = l; j <= r; ++j) maxn[j] = min(maxn[j], x);
    }

    ll ans = 0;

    for(ll i = 1; i <= n; ++i) {
        if(maxn[i] == 1000) ans += h * h;
        else ans += maxn[i] * maxn[i];
    }

    cout << ans << '\n';
    return 0;
}