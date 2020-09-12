#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, d, dp[100007][2];

const ll MOD = 1e9 + 7;

int main() {
    cin >> n >> k >> d;

    dp[0][0] = 1;
    for(ll i = 0; i <= n; ++i) {
        for(ll j = 1; j <= d - 1; ++j) {
            dp[i + j][0] += dp[i][0];
            dp[i + j][0] %= MOD;
        }

        for(ll j = d; j <= k; ++j) {
            dp[i + j][1] += dp[i][0];
            dp[i + j][1] %= MOD;
        }

        for(ll j = 1; j <= k; ++j) {
            dp[i + j][1] += dp[i][1];
            dp[i + j][1] %= MOD;
        }

    }

    cout << (dp[n][1]%MOD + MOD)%MOD << '\n';

    return 0;
}