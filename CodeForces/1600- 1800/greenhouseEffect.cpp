#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, x[5007], dp[5007][5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        ll s;
        long double d;
        cin >> s >> d;
        x[i] = s;
        dp[i][x[i]] = 1;
    }

    for(ll i = 1; i < n; ++i) {
        //cout << x[i] << ' ';
        for(ll j = 0; j <= m; ++j) {
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if(j <= x[i]) dp[i][x[i]] = max(dp[i][x[i]], dp[i - 1][j] + 1);
        }
    }

    ll ans = 0;
    for(ll i = 0; i <= m; ++i) ans = max(ans, dp[n - 1][i]);

    cout << n - ans << '\n';
    return 0;
}