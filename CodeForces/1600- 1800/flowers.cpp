#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, k, a, b, dp[100007][2], res[100007];

const ll MOD = 1000000007;

int main() {
    cin >> t >> k;
    //memset(dp, -1, sizeof(dp));
    dp[0][0] = 1;

    for(ll i = 0; i <= 100000; ++i) {
        if(i + k <= 100000) {
            dp[i + k][1] += dp[i][0] + dp[i][1];
            dp[i + k][1] = (dp[i + k][1]%MOD + MOD)%MOD;
        }

        dp[i + 1][0] += dp[i][0] + dp[i][1];
        dp[i + 1][0] = (dp[i + 1][0]%MOD + MOD)%MOD;
    }

    for(ll i = 1; i <= 100000; ++i) {
        res[i] = dp[i][0] + dp[i][1] + res[i - 1];
        res[i] = (res[i]%MOD + MOD)%MOD;
        //cout << dp[i][0] << ' ' << dp[i][1] << '\n';
    }

    while(t--) {
        cin >> a >> b;
        cout << ((res[b] - res[a - 1])%MOD + MOD)%MOD << '\n';
    }

    return 0;
}