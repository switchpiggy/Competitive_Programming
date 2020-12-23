#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll a[200007], dp[200007][2], n;

ll dfs(ll loc, ll dir) {
    if(loc <= 0 || loc > n) return 0;
    if(dp[loc][dir] != 0) return dp[loc][dir];
    dp[loc][dir] = -1;
    ll nxt = dfs((dir ? loc + a[loc] : loc - a[loc]), 1 - dir);
    if(nxt == -1) return -1;
    return dp[loc][dir] = a[loc] + nxt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 2; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i < n; ++i) {
        a[1] = i;
        dp[1][1] = 0;
        cout << dfs(1, 1) << '\n';
    }

    return 0;
}