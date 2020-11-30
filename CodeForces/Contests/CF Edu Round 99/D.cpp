#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, x, a[501], dp[2][501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> x;
        for(ll i = 1; i <= n; ++i) cin >> a[i];
        for(ll i = 0; i <= 1; ++i) {
            for(ll j = 0; j <= 500; ++j) {
                for(ll k = 0; k <= 500; ++k) {
                    dp[i][j][k] = INT_MAX;
                }
            }
        }

        dp[0][a[1]][x] = 0;
        if(a[1] > x) dp[0][x][a[1]] = 1;

        for(ll i = 1; i < n; ++i) {
            for(ll j = 0; j <= 500; ++j) {
                for(ll k = 0; k <= 500; ++k) {
                    if(dp[0][j][k] == INT_MAX) continue;
                    if(j <= a[i + 1]) dp[1][a[i + 1]][k] = min(dp[1][a[i + 1]][k], dp[0][j][k]);
                    if(a[i] <= k && k < a[i + 1]) dp[1][k][a[i + 1]] = min(dp[1][k][a[i + 1]], dp[0][j][k] + 1);
                }
            }

            for(ll j = 0; j <= 500; ++j) {
                for(ll k = 0; k <= 500; ++k) {
                    dp[0][j][k] = dp[1][j][k];
                    dp[1][j][k] = INT_MAX;
                }
            }
        }

        ll ans = INT_MAX;
        for(ll j = 0; j <= 500; ++j) {
            for(ll k = 0; k <= 500; ++k) ans = min(ans, dp[0][j][k]);
        }
        if(ans == INT_MAX) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}