#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define benq queue
#define pbenq priority_queue
#define all(x) x.begin(), x.end()
#define sz(x) (ll)x.size()
#define m1(x) memset(x, 1, sizeof(x))
#define m0(x) memset(x, 0, sizeof(x))
#define inf(x) memset(x, 0x3f, sizeof(x))
#define MOD 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, c[26], dp[407][26][26], dp1[407][407][3][3], rep[407][407], pre[407], dp2[2][407][407][4][4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < 26; ++i) cin >> c[i];
    
    for(ll i = 0; i < 26; ++i) {
        for(ll j = 0; j < 26; ++j) {
            for(ll k = 0; k < 26; ++k) {
                if(i != k) dp[3][j][k]++;
            }
        }
    }

    for(ll i = 3; i < n; ++i) {
        for(ll j = 0; j < 26; ++j) {
            for(ll k = 0; k < 26; ++k) {
                for(ll l = 0; l < 26; ++l) {
                    if(l == j) continue;
                    (dp[i + 1][k][l] += dp[i][j][k]) %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < 26; ++i) {
        for(ll j = 0; j < 26; ++j) (ans += dp[n][i][j]) %= MOD;
    }

    for(ll i = 0; i < 26; ++i) {
        for(ll j = 0; j < 26; ++j) {
            for(ll k = 0; k < 26; ++k) {
                if(i != k) dp1[3][(i == 0) + (j == 0) + (k == 0)][min(1ll, j)][min(1ll, k)]++;
            }
            //dp1[2][(i == 0) + (j == 0)][min(1ll, i)][min(1ll, j)]++;
        }
    }

    for(ll i = 3; i < n; ++i) {
        for(ll j = 0; j <= n; ++j) {
            for(ll k = 0; k < 2; ++k) {
                for(ll l = 0; l < 2; ++l) {
                    if(!k) {
                        (dp1[i + 1][j + 1][l][1] += dp1[i][j][k][l]) %= MOD;
                        (dp1[i + 1][j][l][0] += (dp1[i][j][k][l] * 24)%MOD) %= MOD;
                    } else {
                        (dp1[i + 1][j][l][0] += (dp1[i][j][k][l] * 25)%MOD) %= MOD;
                    }
                }
            }
        }
    }

    for(ll i = 0; i < 26; ++i) {
        for(ll j = c[i] + 1; j <= n; ++j) {
            for(ll k = 0; k < 2; ++k) {
                for(ll l = 0; l < 2; ++l) {
                    ans = (ans - dp1[n][j][k][l] + MOD)%MOD;
                }
            }
        }
    }

    for(ll i = 0; i < 26; ++i) {
        for(ll j = 0; j < 26; ++j) {
            for(ll k = 0; k < 26; ++k) {
                if(i != k) dp2[0][(i == 0) + (j == 0) + (k == 0)][(i == 1) + (j == 1) + (k == 1)][min(2ll, j)][min(2ll, k)]++;
            }
        }
    }

    for(ll i = 3; i < n; ++i) {
        for(ll j = 0; j <= n; ++j) {
            for(ll k = 0; k <= n; ++k) {
                for(ll l = 0; l < 3; ++l) {
                    for(ll m = 0; m < 3; ++m) {
                        if(l == 0) {
                            (dp2[1][j + 1][k][m][1] += dp2[0][j][k][l][m]) %= MOD;
                            (dp2[1][j][k + 1][m][2] += dp2[0][j][k][l][m]) %= MOD;
                            (dp2[1][j][k][m][0] += (dp2[0][j][k][l][m] * 23)%MOD) %= MOD;
                        } else if(l == 1) {
                            (dp2[1][j][k + 1][m][2] += dp2[0][j][k][l][m]) %= MOD;
                            (dp2[1][j][k][m][0] += (dp2[0][j][k][l][m] * 24)%MOD) %= MOD;
                        } else {
                            (dp2[1][j + 1][k][m][1] += dp2[0][j][k][l][m]) %= MOD;
                            (dp2[1][j][k][m][0] += (dp2[0][j][k][l][m] * 24)%MOD) %= MOD; 
                        }
                    }
                }
            }
        }

        for(ll j = 0; j <= n; ++j) {
            for(ll k = 0; k <= n; ++k) {
                for(ll l = 0; l < 3; ++l) {
                    for(ll m = 0; m < 3; ++m) {
                        dp2[0][j][k][l][m] = dp2[1][j][k][l][m];
                        dp2[1][j][k][l][m] = 0;
                    }
                }
            }
        }
    }

    //vector<vector<ll>> rep(n + 1, vector<ll>(n + 1, 0));
    for(ll i = 0; i <= n; ++i) {
        for(ll j = 0; j <= n; ++j) {
            for(ll l = 0; l < 3; ++l) {
                for(ll k = 0; k < 3; ++k) {
                    (rep[i][j] += dp2[0][i][j][l][k]) %= MOD;
                }
            }
        }
    }

    
    /*for(ll i = 0; i <= 10; ++i, cout << '\n') {
        for(ll j = 0; j <= 10; ++j) cout << rep[i][j] << ' ';
    }*/

    /*for(ll i = n; i >= 0; --i, cout << '\n') {
        for(ll j = n; j >= 0; --j) cout << rep[i][j] << ' ';
    }*/

    for(ll i = 1; i <= n; ++i) (rep[i][0] += rep[i - 1][0]) %= MOD, (rep[0][i] += rep[0][i - 1]) %= MOD;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            rep[i][j] = ((rep[i - 1][j] + rep[i][j - 1])%MOD - rep[i - 1][j - 1] + MOD)%MOD;
        }
    }

    for(ll i = 0; i < 26; ++i) {
        for(ll j = i + 1; j < 26; ++j) {
            //if(i == j) continue;
            (ans += (rep[n][n] - rep[n][c[i]] + MOD - rep[c[j]][n] + MOD + rep[c[i]][c[j]])) %= MOD;
        }
    }

    cout << ans << '\n';
    return 0;
}