#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mxn = 100007;
ll n, k, dp[mxn], h[mxn];

int main() {
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> h[i];
    memset(dp, -1, sizeof(dp));

    dp[0] = 0;

    for(ll i = 0; i < n; ++i) {
        for(ll j = i + 1; j <= i + k && j < n; ++j) {
            if(dp[j] == -1 || dp[j] > dp[i] + abs(h[j] - h[i])) dp[j] = dp[i] + abs(h[j] - h[i]);
        }
    }

    cout << dp[n - 1] << endl;
    return 0;
}