#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dp[507][507], c[507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> c[i];

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            if(j < i) dp[i][j] = 0;
            else dp[i][j] = LONG_LONG_MAX;
        }
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n - i + 1; ++j) {
            ll k = i + j - 1;
            if(j == k) {
                dp[j][k] = 1;
                continue;
            }

            dp[j][k] = min(dp[j][k], 1 + dp[j + 1][k]);
            if(k >= j + 1 && c[j] == c[j + 1]) dp[j][k] = min(dp[j][k], 1 + dp[j + 2][k]);
            //dp[j][k] = min(dp[j][k], 1 + dp[j][k - 1]);

            for(ll kk = j + 2; kk <= k; ++kk) {
                if(c[kk] == c[j]) dp[j][k] = min(dp[j][k], dp[j + 1][kk - 1] + dp[kk + 1][k]);
            }
        }
    }

    cout << dp[1][n] << '\n';
    return 0;
}