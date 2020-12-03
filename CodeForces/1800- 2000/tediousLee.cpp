#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, dp[2000007];
const ll MOD = 1000000007;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    dp[1] = dp[2] = 0;
    for(ll i = 3; i <= 2000000; ++i) dp[i] = (dp[i - 1] + 2 * dp[i - 2] + ((i%3 == 0) ? 4 : 0))%MOD;

    cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}