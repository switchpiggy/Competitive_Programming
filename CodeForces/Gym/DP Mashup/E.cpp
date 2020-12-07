#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, p, a[1007], b[2007], dp[2007][2007];
// dp[i][j] -> ith prefix, last taken key was jth

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> p;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < k; ++i) cin >> b[i];
    sort(b, b + k);
    sort(a, a + n);

    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j <= k; ++j) dp[j][i] = LONG_LONG_MAX;
    }

    dp[0][0] = 0;
    for(ll i = 0; i < k; ++i) {
        for(ll j = 0; j <= n; ++j) {
            dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
            if(j < n) dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j], abs(a[j] - b[i]) + abs(p - b[i])));
        }
    }

    cout << dp[k][n] << '\n';
    return 0;
}