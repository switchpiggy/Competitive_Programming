#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, t;
long double p, dp[2007][2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p >> t;

    //dp[i][j] -> after time i, j groups have went

    dp[0][0] = 1;
    for(ll i = 1; i <= t; ++i) {
        for(ll j = 0; j <= n; ++j) {
            dp[i][j] += dp[i - 1][j] * ((j == n) ? 1.0 : (1.0 - p));
            if(j) dp[i][j] += dp[i - 1][j - 1] * p;
            //cout << dp[i][j] << ' ';
        }

        //cout << '\n';
    }

    long double ans = 0;
    for(ll i = 0; i <= n; ++i) ans += ((long double)i * dp[t][i]);

    cout << fixed << setprecision(12) << ans << '\n';
    return 0;
}