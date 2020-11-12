#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, x, y, dp[1007][2], w[1007], b[1007];
char grid[1007][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> x >> y;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 1; j <= m; ++j) cin >> grid[i][j];
    }

    for(ll i = 1; i <= m; ++i) {
        for(ll j = 0; j < n; ++j) {
            if(grid[j][i] == '.') b[i]++;
            else w[i]++;
        }

        w[i] += w[i - 1];
        b[i] += b[i - 1];

        dp[i][1] = dp[i][0] = INT_MAX;
    }

    dp[0][0] = dp[0][1] = 0;  
    for(ll i = 0; i < m; ++i) {
        for(ll j = x; j <= y; ++j) {
            if(i + j > m) continue;
            if(dp[i][1] != INT_MAX) dp[i + j][0] = min(dp[i + j][0], dp[i][1] + (w[i + j] - w[i]));
            if(dp[i][0] != INT_MAX) dp[i + j][1] = min(dp[i + j][1], dp[i][0] + (b[i + j] - b[i]));
        }   
    }  

    cout << min(dp[m][1], dp[m][0]) << '\n';
    return 0;
}