#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, x, d[400007], b[400007], c[400007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(ll i = 0; i < n; ++i) {
        cin >> d[i];
        d[n + i] = d[i];
    }

    n *= 2;
    b[0] = c[0] = 0;
    for(ll i = 1; i <= n; ++i) {
        b[i] = b[i - 1] + d[i - 1];
        c[i] = c[i - 1] + (d[i - 1] * (d[i - 1] + 1))/2;
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        if(b[i + 1] >= x) {
            ll k = upper_bound(b, b + n, b[i + 1] - x) - b;
            ll cur = c[i + 1] - c[k];
            ll diff = b[i + 1] - b[k];
            ll t = x - diff;
            cur += (d[k - 1] * (d[k - 1] + 1))/2;
            cur -= ((d[k - 1] - t) * (d[k - 1] - t + 1))/2;
            ans = max(ans, cur);
        }
    }

    cout << ans << '\n';
    return 0;
}