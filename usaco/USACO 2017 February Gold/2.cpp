#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[1007], b[1007], dp[1007][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("nocross.in", "r", stdin);
    freopen("nocross.out", "w", stdout);

    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> b[i];

    dp[0][0] = (abs(a[0] - b[0]) <= 4);
    ll ans = 0;
    for(ll i = 1; i < n; ++i) dp[i][0] = max(dp[i - 1][0], (ll)(abs(a[i] - b[0]) <= 4));
    for(ll i = 1; i < n; ++i) dp[0][i] = max(dp[0][i - 1], (ll)(abs(a[0] - b[i]) <= 4));

    for(ll i = 1; i < n; ++i) {
        for(ll j = 1; j < n; ++j) {
            dp[i][j] = max(dp[i - 1][j], max(dp[i][j - 1], dp[i - 1][j - 1] + (ll)(abs(a[i] - b[j]) <= 4)));
        }
    }

    cout << dp[n - 1][n - 1] << '\n';
    return 0;
}