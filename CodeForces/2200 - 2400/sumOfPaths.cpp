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
ll n, k, q, a[5007], x, y, dp[5007][5007], cnt[5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> q;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        dp[1][i] = 1;
    }

    for(ll i = 2; i <= k + 1; ++i) {
        dp[i][0] = dp[i - 1][1];
        dp[i][n - 1] = dp[i - 1][n - 2];
        for(ll j = 1; j < n - 1; ++j) {
            dp[i][j] = (dp[i - 1][j + 1] + dp[i - 1][j - 1])%MOD;
        }
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        for(ll j = 2; j <= k; ++j) {
            (cnt[i] += (dp[j][i] * dp[k + 1 - j + 1][i])%MOD) %= MOD;
        }

        (cnt[i] += 2 * dp[k + 1][i]) %= MOD;
        (ans += cnt[i] * a[i]) %= MOD;
    }

    // for(ll i = 0; i < n; ++i) {
        // for(ll j = 1; j <= k + 1; ++j) cout << dp[j][i] << ' ';
        // cout << '\n';
    // }

    // for(ll i = 0; i < n; ++i) cout << cnt[i] << ' ';
    // cout << '\n';

    while(q--) {
        cin >> x >> y;
        x--;
        ans = (ans - (cnt[x] * a[x])%MOD + MOD)%MOD;
        (ans += cnt[x] * y) %= MOD;
        a[x] = y;
        cout << ans << '\n';
    }

    return 0;
}