#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, a[100007], dp[100007][6];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    for(ll i = 2; i <= n; ++i) {
        for(ll j = 1; j <= 5; ++j) dp[i][j] = -1;
    }

    for(ll i = 1; i < n; ++i) {
        for(ll j = 1; j <= 5; ++j) {
            if(dp[i][j] == -1) continue;
            if(a[i] < a[i + 1]) {
                for(ll k = j + 1; k <= 5; ++k) dp[i + 1][k] = j;
            } else if(a[i] == a[i + 1]) {
                for(ll k = 1; k <= 5; ++k) {
                    if(k != j) dp[i + 1][k] = j;
                }
            } else {
                for(ll k = 1; k < j; ++k) dp[i + 1][k] = j;
            }
        }
    }

    for(ll i = 1; i <= 5; ++i) {
        if(dp[n][i] != -1) {
            ll cur = i;
            vector<ll> ans;
            for(ll j = n; j >= 1; --j) {
                ans.push_back(cur);
                cur = dp[j][cur];
            }

            reverse(ans.begin(), ans.end());

            for(ll i = 0; i < n; ++i) cout << ans[i] << ' ';
            return 0;
        }
    }

    cout << "-1\n";
    return 0;
}