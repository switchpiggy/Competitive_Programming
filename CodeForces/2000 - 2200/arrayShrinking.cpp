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
ll n, a[507], dp[507][507], dp2[507][507];

ll solve(ll l, ll r) {
    if(r < l) return dp[l][r] = 0;
    if(dp2[l][r] != -1) return dp2[l][r];

    ll res = r - l + 1;
    for(ll i = l; i <= r; ++i) {
        if(dp[l][i] != -1) res = min(res, solve(i + 1, r) + 1);
    }

    return dp2[l][r] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    memset(dp2, -1, sizeof(dp2));
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i], dp[i][i] = a[i];

    ll ans = n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 0; j < n - i + 1; ++j) {
            for(ll k = 0; k < j; ++k) {
                if(dp[k][j - 1] == dp[j][j + i - 1] && dp[k][j - 1] != -1) {
                    dp[k][j + i - 1] = dp[k][j  - 1] + 1;
                }
            }

            for(ll k = j + i; k < n; ++k) {
                if(dp[j][j + i - 1] == dp[j + i][k] && dp[j][j + i - 1] != -1) {
                    dp[j][k] = dp[j][j + i - 1] + 1;
                }
            }
        }
    }

    /*for(ll i = 0; i < 7; ++i) {
        for(ll j = 0; j < 7; ++j) cout << dp[i][j] << ' ';
        cout << '\n';
    }*/

    cout << solve(0, n - 1) << '\n';
    return 0;
}