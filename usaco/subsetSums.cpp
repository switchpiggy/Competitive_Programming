/*
LANG: C++
PROG: subset
ID: alanxia
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dp[47][2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);

    cin >> n;
    if(((n * (n + 1))/2)%2 == 1) {
        cout << "0\n";
        return 0;
    }

    dp[0][0] = 1;
    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j <= (i * (i + 1))/2; ++j) {
            dp[i + 1][j + i + 1] += dp[i][j];
            dp[i + 1][j] += dp[i][j];
        }
    }

    cout << dp[n][(n * (n + 1))/4]/2 << '\n';
    return 0;
}