#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], dp[100007], d[100007];

int main() {
    cin >> n;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        dp[a[i]] = 1;
    }

    if(n == 1 && a[0] == 1) {
        cout << 1 << '\n';
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        ll res = 0;
        for(ll j = 2; j * j <= a[i]; ++j) {
            if(a[i]%j == 0) {
                res = max(res, d[j]);
                res = max(res, d[a[i]/j]);
            }
        }

        res = max(res, d[a[i]]);

        dp[a[i]] = max(dp[a[i]], res + 1);
        //cout << res << ' ' << dp[a[i]] << '\n';

        for(ll j = 2; j * j <= a[i]; ++j) {
            if(a[i]%j == 0) {
                d[j] = max(d[j], dp[a[i]]);
                d[a[i]/j] = max(d[a[i]/j], dp[a[i]]);
            }
        }

        d[a[i]] = max(d[a[i]], dp[a[i]]);
    }

    ll ans = 1;
    for(ll i = 0; i < n; ++i) ans = max(ans, dp[a[i]]);

    cout << ans << '\n';

    return 0;
}