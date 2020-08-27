#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, val[100007][3], dp[100007][3];

int main() {
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        cin >> val[i][0] >> val[i][1] >> val[i][2];
    }

    dp[1][0] = val[1][0], dp[1][1] = val[1][1], dp[1][2] = val[1][2];
    for(ll i = 2; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][2]) + val[i][0];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + val[i][1];
        dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + val[i][2];
    }

    cout << max(dp[n][0], max(dp[n][1], dp[n][2])) << endl;
    return 0;
}