#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dp[5007], w[5007], h[5007], nxt[5007];

ll solve(ll x) {
    if(dp[x]) return dp[x];
    dp[x] = 1;
    for(ll i = 0; i <= n; ++i) {
        if(w[i] > w[x] && h[i] > h[x]) {
            if(solve(i) + 1 > dp[x]) {
                nxt[x] = i;
                dp[x] = dp[i] + 1;
            }
        }
    }

    return dp[x];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 0; i <= n; ++i) {
        cin >> w[i] >> h[i];
        nxt[i] = -1;
    }

    solve(0);

    cout << dp[0] - 1 << '\n';
    for(ll i = nxt[0]; i != -1; i = nxt[i]) cout << i << ' ';
    cout << '\n';
    return 0;
}