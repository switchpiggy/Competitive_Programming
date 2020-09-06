#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, n, a, b;
string s;
ll dp[200007][2];

int main() {
    cin >> t;
    while(t--) {
        cin >> n >> a >> b >> s;
        for(ll i = 0; i <= n + 1; ++i) dp[i][1] = dp[i][0] = 1e18;
        //cout << dp[0][0] << endl;

        dp[0][0] = b;

        for(ll i = 0; i <= n; ++i) {
            if(s[i] == '1') {
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a + 2 * b);
            } else {
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + a + b);
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 2 * a + 2 * b);
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + a + 2 * b);
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][1] + 2 * a + b);
            }
        }

        cout << dp[n][0] << '\n';
    }

    return 0;
}