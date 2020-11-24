#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, dp[1007][2007][4];
const ll MOD = 998244353;

ll getmask(ll x, ll y) {
    ll cnt = __builtin_popcount(x^y);
    if(!cnt) return 0;
    if(cnt == 2) return ((x == 0 || x == 3) ? 1 : 2);
    return ((x == 0 || x == 3) ? 0 : 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    dp[1][0][0] = dp[1][0][1] = dp[1][0][2] = dp[1][0][3] = 1;
    for(ll i = 1; i < n; ++i) {
        for(ll j = 0; j <= k; ++j) {
            for(ll mask = 0; mask < 4; ++mask) {
                for(ll mask2 = 0; mask2 < 4; ++mask2) {
                    dp[i + 1][j + getmask(mask, mask2)][mask2] += dp[i][j][mask];
                    dp[i + 1][j + getmask(mask, mask2)][mask2] %= MOD;
                }
            }
        }
    }

    /*for(ll i = 0; i < 4; ++i) {
        for(ll j = 0; j < 4; ++j) cout << getmask(i, j) << ' ';
        cout << '\n';
    }*/
    ll ans = 0;
    for(ll i = 0; i < 4; ++i) {
        if(k >= getmask(i, i^3)) ans += dp[n][k - getmask(i, i^3)][i];
        ans %= MOD;
    }

    cout << ans << '\n';
    return 0;
}