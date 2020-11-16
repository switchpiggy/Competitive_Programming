#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[1000007];
bool dp[2][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    if(n > m) {
        cout << "YES\n";
        return 0;
    }

    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
    }

    dp[0][a[0]%m] = 1;
    for(ll i = 1; i < n; ++i) {
        dp[1][a[i]%m] = 1;
        for(ll j = 0; j < m; ++j) {
            if(dp[0][j]) {
                dp[1][j] = 1;
                dp[1][(j + a[i])%m] = 1;
            }
        }

        copy(dp[1], dp[1] + m, dp[0]);
    }

    if(dp[0][0]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}