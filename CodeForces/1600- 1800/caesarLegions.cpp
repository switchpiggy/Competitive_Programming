#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, k1, k2, dp[107][107][2];

const ll MOD = 100000000;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k1 >> k2;

    //1 - ending in horsemen
    //0 - ending in footman
    dp[n][m][0] = dp[n][m][1] = 1;
    for(ll i = n; i >= 0; --i) {
        for(ll j = m; j >= 0; --j) {
            for(ll k = 1; k <= k1 && k <= i; ++k) {
                dp[i - k][j][0] += dp[i][j][1];
                dp[i - k][j][0] %= MOD;
            }

            for(ll k = 1; k <= k2 && k <= j; ++k) {
                dp[i][j - k][1] += dp[i][j][0];
                dp[i][j - k][1] %= MOD;
            }
        }
    }

    cout << (dp[0][0][0] + dp[0][0][1])%MOD << '\n';
    return 0;
}