#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, b[4007], dp[4007][4007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> b[i];

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ll last = 0;
        for(ll j = 0; j < i; ++j) {
            dp[i][j] = dp[j][last] + 1;
            if(b[i] == b[j]) last = j;
            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans << '\n';
    return 0;
}