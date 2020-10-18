#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, l, r, ql, qr, w[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> l >> r >> ql >> qr;
    for(ll i = 1; i <= n; ++i) cin >> w[i];
    for(ll i = 1; i <= n; ++i) w[i] += w[i - 1];

    ll ans = INT_MAX;
    for(ll i = 0; i <= n; ++i) {
        ll res = w[i] * l + (w[n] - w[i]) * r;
        if(i > n - i) res += (i - (n - i) - 1) * ql;
        if(i < n - i) res += ((n - i) - i - 1) * qr;

        ans = min(ans, res);
    }

    cout << ans << '\n';
    return 0;
}