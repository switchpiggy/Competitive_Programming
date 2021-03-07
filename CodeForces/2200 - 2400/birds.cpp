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
ll n, w, b, x, dp[1007][20007], c[1007], cost[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> w >> b >> x;
    dp[0][0] = w;
    for(ll i = 0; i < n; ++i) cin >> c[i];
    for(ll i = 0; i < n; ++i) cin >> cost[i];

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j <= 10000 && dp[i][j] != -1; ++j) {
            // cout << dp[i][j] << ' ';
            // if(dp[i][j] == -1) continue;
            for(ll k = 0; cost[i] * k <= dp[i][j] && k <= c[i]; ++k) {
                dp[i + 1][j + k] = max(dp[i + 1][j + k], min(w + (j + k) * b, dp[i][j] - k * cost[i] + x));
            }
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= 10000; ++i) if(dp[n][i] != -1) ans = i;

    cout << ans << '\n';
    return 0;
}