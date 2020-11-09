#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, h, l, r, a[2007], dp[2007][2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> h >> l >> r;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    for(ll i = 0; i <= n; ++i) 
        for(ll j = 0; j < h; ++j) dp[i][j] = -1;

    dp[0][0] = 0;

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < h; ++j) {
            if(dp[i][j] != -1) {
                dp[i + 1][(j + a[i])%h] = max(dp[i + 1][(j + a[i])%h], dp[i][j] + ((j + a[i])%h >= l && (j + a[i])%h <= r));
                dp[i + 1][(j + a[i] - 1)%h] = max(dp[i + 1][(j + a[i] - 1)%h], dp[i][j] + ((j + a[i] - 1)%h <= r && (j + a[i] - 1)%h >= l));
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < h; ++i) ans = max(ans, dp[n][i]);

    cout << ans << '\n';
    return 0;
}