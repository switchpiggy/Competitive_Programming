#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[100007], n, h[100007];

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> h[i];
    dp[0] = 0;
    
    for(ll i = 0; i < n; ++i) {
        if(i + 1 < n && (dp[i + 1] == -1 || dp[i + 1] > dp[i] + abs(h[i + 1] - h[i]))) dp[i + 1] = dp[i] + abs(h[i + 1] - h[i]);
        if(i + 2 < n && (dp[i + 2] == -1 || dp[i + 2] > dp[i] + abs(h[i + 2] - h[i]))) dp[i + 2] = dp[i] + abs(h[i + 2] - h[i]);
    }

    cout << dp[n - 1] << endl;
    return 0;
}