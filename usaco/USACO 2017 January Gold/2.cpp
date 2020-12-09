#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, k, a[100007], dp[100007][21][3];

ll match(ll x, ll y) {
    if(x == 0 && y == 2) return 1;
    if(x == 2 && y == 1) return 1;
    if(x == 1 && y == 0) return 1;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) {
        char c;
        cin >> c;
        if(c == 'H') a[i] = 0;
        else if(c == 'P') a[i] = 1;
        else a[i] = 2;
    }

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j <= k; ++j) {
            for(ll l = 0; l < 3; ++l) {
                if(j < k) {
                    dp[i + 1][j + 1][(l + 1)%3] = max(dp[i + 1][j + 1][(l + 1)%3], dp[i][j][l] + match((l + 1)%3, a[i]));
                    dp[i + 1][j + 1][(l + 2)%3] = max(dp[i + 1][j + 1][(l + 2)%3], dp[i][j][l] + match((l + 2)%3, a[i]));
                }

                dp[i + 1][j][l] = max(dp[i + 1][j][l], dp[i][j][l] + match(l, a[i]));
            }
        }
    }

    ll ans = 0;
    for(ll j = 0; j <= 20; ++j) {
        for(ll i = 0; i < 3; ++i) ans = max(ans, dp[n][j][i]);
    }

    cout << ans << '\n';
    return 0;
}