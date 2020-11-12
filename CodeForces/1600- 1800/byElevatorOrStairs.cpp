#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n,c, a[200007], b[200007], dp[200007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> c;
    for(ll i = 1; i < n; ++i) cin >> a[i];
    for(ll i = 1; i < n; ++i) cin >> b[i];
    for(ll i = 2; i <= n; ++i) dp[i][0] = dp[i][1] = INT_MAX;

    //dp[i][1] -> elevator
    //dp[i][0] -> stairs
    dp[1][1] = c;
    for(ll i = 1; i < n; ++i) {
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + b[i]);
        dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + c + b[i]);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a[i]);
        dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + a[i]);
    }

    for(ll i = 1; i <= n; ++i) cout << min(dp[i][0], dp[i][1]) << ' ';
    cout << '\n';
    return 0;
}