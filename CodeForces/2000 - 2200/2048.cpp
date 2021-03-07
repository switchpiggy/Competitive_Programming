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
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, k, dp[2007][(1 << 11)][2], a[2007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    dp[0][0][0] = 1;
    for(ll i = 0; i < n; ++i) {
        for(ll mask = 0; mask < (1 << k); ++mask) {
            if(a[i] == 0 || a[i] == 2) {
                ll cur = 1, nmask = mask;
                for(ll j = 1; j < k; ++j) {
                    if(mask & (1 << j)) cur = j + 1, nmask -= (1 << j);
                    else break;
                }

                if(cur == k) {
                    (dp[i + 1][0][1] += dp[i][mask][0] + dp[i][mask][1]) %= MOD;
                } else {
                    (dp[i + 1][nmask + (1 << cur)][0] += dp[i][mask][0]) %= MOD;
                    (dp[i + 1][nmask + (1 << cur)][1] += dp[i][mask][1]) %= MOD;
                }
            }

            if(a[i] == 0 || a[i] == 4) {
                ll cur = 2, nmask = mask;
                if(mask & 2) {
                    // if((mask | 1) == (1 << k) - 1) (dp[i + 1][2][1] += dp[i][mask][0]) %= MOD;
                    (dp[i + 1][4][0] += dp[i][mask][0]) %= MOD;
                    (dp[i + 1][4][1] += dp[i][mask][1]) %= MOD;
                    continue;
                }

                for(ll j = 2; j < k; ++j) {
                    if(mask & (1 << j)) cur = j + 1, nmask -= (1 << j);
                    else break;
                }

                if(cur == k) {
                    (dp[i + 1][nmask][1] += dp[i][mask][0] + dp[i][mask][1]) %= MOD;
                } else {
                    (dp[i + 1][nmask + (1 << cur)][0] += dp[i][mask][0]) %= MOD;
                    (dp[i + 1][nmask + (1 << cur)][1] += dp[i][mask][1]) %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for(ll i = 0; i < (1 << k); ++i) (ans += dp[n][i][1]) %= MOD; //cout << dp[3][i][1] << ' ';
    //cout << '\n';

    cout << ans << '\n';
    return 0;
}