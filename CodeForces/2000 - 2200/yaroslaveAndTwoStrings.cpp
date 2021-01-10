#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, dp[100007][4];
string s, t;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s >> t;

    dp[0][0] = 1;
    for(ll i = 0; i < n; ++i) {
        if(s[i] != '?' && t[i] != '?') {
            if(s[i] > t[i]) {
                dp[i + 1][2] = (dp[i + 1][2] + dp[i][0] + dp[i][2])%MOD;
                dp[i + 1][3] = (dp[i + 1][3] + dp[i][1] + dp[i][3])%MOD;
            } else if(s[i] == t[i]) {
                for(ll j = 0; j < 4; ++j) {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j])%MOD;
                }
            } else {
                dp[i + 1][1] = (dp[i][0] + dp[i][1] + dp[i + 1][1])%MOD;
                dp[i + 1][3] = (dp[i][2] + dp[i][3] + dp[i + 1][3])%MOD;
            }
        } else if(s[i] == '?' && t[i] == '?') {
            for(ll j = 0; j < 4; ++j) {
                ll fst = j&1, snd = j&2;
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 10)%MOD;
                if(fst) {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 1] * 45)%MOD;
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 45)%MOD;
                }

                if(snd) {
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 2] * 45)%MOD;
                    dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * 45)%MOD;
                }
            }
        } else {
            for(ll j = 0; j < 4; ++j) {
                ll fst = j&1, snd = j&2;
                dp[i + 1][j] = (dp[i + 1][j] + dp[i][j])%MOD;
                
                if(fst) {
                    if(t[i] == '?') {
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 1] * (9 - (s[i] - '0')))%MOD;
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (9 - (s[i] - '0')))%MOD;
                    } else {
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 1] * (t[i] - '0'))%MOD;
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (t[i] - '0'))%MOD;
                    }
                }

                if(snd) {
                    if(s[i] == '?') {
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 2] * (9 - (t[i] - '0')))%MOD;
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (9 - (t[i] - '0')))%MOD;
                    } else {
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j - 2] * (s[i] - '0'))%MOD;
                        dp[i + 1][j] = (dp[i + 1][j] + dp[i][j] * (s[i] - '0'))%MOD;
                    }
                }
            }
        }
    }

    /*for(ll i = 0; i < n; ++i, cout << '\n') {
        for(ll j = 0; j < 4; ++j) cout << dp[i][j] << ' ';
    }*/

    cout << dp[n][3] << '\n';
    return 0;
}