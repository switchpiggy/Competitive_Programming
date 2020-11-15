#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, dp[107][107][107], c[107], p[107][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;
    //dp[i][j][k] = number of litres used after making k groups out of first i trees, with j
    //being the color of the last tree
    for(ll i = 1; i <= n; ++i) cin >> c[i];

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= m; ++j) cin >> p[i][j];
    }

    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j <= m; ++j) {
            for(ll l = 0; l <= k; ++l) dp[i][j][l] = LONG_LONG_MAX;
        }
    }

    dp[0][0][0] = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j <= m; ++j) {
            for(ll l = 0; l <= k; ++l) {
                if(dp[i][j][l] == LONG_LONG_MAX || (j == 0 && i != 0)) continue;
                if(c[i + 1]) {
                    if(c[i + 1] == j) dp[i + 1][c[i + 1]][l] = min(dp[i + 1][c[i + 1]][l], dp[i][j][l]);
                    else dp[i + 1][c[i + 1]][l + 1] = min(dp[i + 1][c[i + 1]][l + 1], dp[i][j][l]);
                } else {
                    for(ll h = 1; h <= m; ++h) {
                        if(h == j) dp[i + 1][h][l] = min(dp[i + 1][h][l], dp[i][j][l] + p[i + 1][h]);
                        else dp[i + 1][h][l + 1] = min(dp[i + 1][h][l + 1], dp[i][j][l] + p[i + 1][h]);
                    }
                }
            }
        }
    }

    ll ans = LONG_LONG_MAX;
    for(ll i = 1; i <= m; ++i) ans = min(ans, dp[n][i][k]);

    if(ans == LONG_LONG_MAX) ans = -1;
    cout << ans << '\n';
    return 0;
} 