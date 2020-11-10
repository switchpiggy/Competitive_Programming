#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[5007], dp[5007][5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(ll i = 1; i <= n; ++i) {
        ll cur = 0;
        while(i + cur <= n && a[i + cur] <= a[i] + 5) cur++;
        for(ll j = 0; j <= k; ++j) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
            if(j + 1 <= k) dp[i + cur][j + 1] = max(dp[i + cur][j + 1], dp[i][j] + cur);
        }
    }

    cout << dp[n + 1][k] << '\n';
    return 0;
}