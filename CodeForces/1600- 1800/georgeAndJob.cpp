#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k, a[5007], pref[5007], dp[5007][5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i) pref[i] = pref[i - 1] + a[i];

    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j < k; ++j) {
            if(i + m  <= n) dp[i + m][j + 1] = max(dp[i + m][j + 1], dp[i][j] + pref[i + m] - pref[i]);
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }

        dp[i + 1][k] = max(dp[i + 1][k], dp[i][k]);
    }

    cout << dp[n][k] << '\n';
    return 0;
}