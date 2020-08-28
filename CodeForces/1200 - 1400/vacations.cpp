#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[107], dp[107][3];

int main() {
    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    //memset(dp, -1, sizeof(dp[0][0]) * 107 * 3);

    dp[0][0] = dp[0][1] = dp[0][2] = 0;

    for(ll i = 1; i <= n; ++i) {
        dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1], dp[i - 1][2]));

        if(a[i] == 1) {
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        } 
        if(a[i] == 2) {
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        }
        if(a[i] == 3) {
            dp[i][2] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][2]) + 1;
        }
    }

    cout << n - max(dp[n][0], max(dp[n][1], dp[n][2]));

    return 0;
}