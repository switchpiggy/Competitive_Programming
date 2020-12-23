#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dp[200007][4][4];
string s;
const ll MOD = 1e9 + 7;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);

    if(y%2) return ((recurse * recurse)%MOD * x)%MOD;
    return (recurse * recurse)%MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    dp[0][0][0] = 1;
    ll cnt = 0;
    for(ll i = 0; i < n; ++i) {
        cnt += (s[i] == '?');
        for(ll j = 0; j <= 3; ++j) {
            for(ll k = 0; k <= j; ++k) {
                dp[i + 1][j][k] += dp[i][j][k];
                dp[i + 1][j][k] %= MOD;
            }
        }

        if(s[i] == 'a') {
            dp[i + 1][1][0] += dp[i][0][0], dp[i + 1][1][0] %= MOD;
        } else if(s[i] == 'b') {
            for(ll j = 0; j < 2; ++j) dp[i + 1][2][j] += dp[i][1][j], dp[i + 1][2][j] %= MOD;
        } else if(s[i] == 'c') {
            for(ll j = 0; j < 3; ++j) dp[i + 1][3][j] += dp[i][2][j], dp[i + 1][3][j] %= MOD;
        } else {
            for(ll j = 0; j < 3; ++j) {
                for(ll k = 0; k <= j; ++k) {
                    dp[i + 1][j + 1][k + 1] += dp[i][j][k];
                    dp[i + 1][j + 1][k + 1] %= MOD;
                }
            }
        }
    }

    std::cout << (((fastpow(3, cnt - 3) * dp[n][3][3])%MOD + (fastpow(3, cnt - 2) * dp[n][3][2])%MOD + (fastpow(3, cnt - 1) * dp[n][3][1])%MOD)%MOD + (fastpow(3, cnt) * dp[n][3][0])%MOD)%MOD << '\n';
    return 0;
}