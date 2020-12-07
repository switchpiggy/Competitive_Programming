#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll t, a, b, dp[5000007][2];

ll knapsack(ll x, ll d) {
    if(x > t) return 0;
    if(dp[x][d]) return dp[x][d];
    if(x + a > t && x + b > t) {
        dp[x][d] = x;
        return x;
    }

    dp[x][d] = max(x, max(knapsack(x + a, d), knapsack(x + b, d)));
    return dp[x][d];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);
    cin >> t >> a >> b;

    knapsack(0, 0);

    ll ans = 0;
    for(ll i = 0; i <= t; ++i) {
        if(dp[i][0]) knapsack(i/2, 1);
    }

    for(ll i = 0; i <= t; ++i) {
        if(dp[i][0]) ans = max(ans, max(dp[i][0], dp[i/2][1]));
    }
    cout << ans << '\n';
    return 0;
}