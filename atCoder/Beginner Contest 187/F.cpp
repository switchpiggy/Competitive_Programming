#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
bool ok[(1ll << 18)];
ll dp[(1ll << 18)];
bool adj[20][20];
ll n, a, b, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < m; ++i) {
        cin >> a >> b;
        adj[a][b] = adj[b][a] = 1;
    }

    for(ll i = 0; i < (1ll << n); ++i) {
        bool good = 1;
        for(ll j = 0; j < n; ++j) {
            for(ll k = 0; k < n; ++k) {
                if(j == k) continue;
                if((i & (1ll << j)) && (i & (1ll << k)) && !adj[j + 1][k + 1]) {
                    good = 0;
                    break;
                }
            }

            if(!good) break;
        }

        ok[i] = good;
    }

    dp[0] = 0;
    for(ll i = 1; i < (1ll << n); ++i) {
        if(ok[i]) dp[i] = 1;
        else dp[i] = INT_MAX;
    }

    for(ll i = 0; i < (1 << n); ++i) {
        for(ll j = i; ; j = (j - 1)&i) {
            dp[i] = min(dp[i], dp[j] + dp[i - j]);
            if(j == 0) break;
        }
    }

    //cout << ok[15] << '\n';
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}