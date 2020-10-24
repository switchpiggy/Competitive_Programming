#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll dp[(1 << 22)], n, grid[27][27];

const ll MOD = 1000000007;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, 0, sizeof(dp));

    dp[0] = 1;

    cin >> n;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j < n; ++j) cin >> grid[i][j];
    }

    for(ll mask = 0; mask < (1 << n) - 1; ++mask) {
        ll i = __builtin_popcount(mask);
        for(ll j = 0; j < n; ++j) {
            if(grid[i][j] && !(mask & (1 << j))) {
               ll mask2 = mask ^ (1 << j);
                dp[mask2] += dp[mask];
                dp[mask2] %= MOD;
            }
                
        }
    }

    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}