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
#define MOD 1000000009
#define INF 0x3f3f3f3f3f3f3f3f
#define PI 3.14159265358979323846264338
#define flout cout << fixed << setprecision(12)
ll n, m, k, dp[1007][11], a[1007], b[1007], cnt[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; ++i) cin >> a[i];
    for(ll i = 1; i <= m; ++i) cin >> b[i];

    sort(b + 1, b + m + 1, greater<ll>());
    sort(a + 1, a + n + 1, greater<ll>());

    for(ll i = 1; i <= m; ++i) {
        for(ll j = 1; j <= n; ++j) if(a[j] > b[i]) cnt[i]++;
        else break;
        cout << cnt[i] << ' ';
    }

    cout << '\n';

    dp[0][0] = 1;
    for(ll i = 0; i < m; ++i) {
        for(ll j = 0; j <= k; ++j) {
            (dp[i + 1][j] += dp[i][j]) %= MOD;
            if(cnt[i + 1] > j) (dp[i + 1][j + 1] += dp[i][j] * (cnt[i + 1] - j)) %= MOD;
        }
    }

    for(ll i = 1; i <= m; ++i, cout << '\n') {
        for(ll j = 0; j <= k; ++j) cout << dp[i][j] << ' ';
    }

    cout << dp[m][k] << '\n';
    return 0;
}