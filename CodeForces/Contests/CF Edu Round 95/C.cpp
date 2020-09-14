#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a[200007], dp[200007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> a[i];
        
        for(ll i = 0; i <= n; ++i) dp[i][0] = dp[i][1] = 1e9;

        dp[0][0] = 0;
        for(ll i = 0; i < n; ++i) {
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + a[i + 1]);
            dp[i + 2][1] = min(dp[i + 2][1], dp[i][0] + a[i + 1] + a[i + 2]);
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][1]);
            dp[i + 2][0] = min(dp[i + 2][0], dp[i][1]);
        }

        cout << min(dp[n][1], dp[n][0]) << '\n';
    }

    return 0;
}