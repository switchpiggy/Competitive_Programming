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
ll n, m, x[100007], dp[100007][107];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> x[i];
    if(!x[0]) for(ll i = 1; i <= m; ++i) dp[0][i] = 1;
    else dp[0][x[0]] = 1;

    for(ll i = 0; i < n; ++i) {
        if(x[i + 1] == 0) {
            for(ll j = 1; j <= m; ++j) {
                (dp[i + 1][j] += (dp[i][j - 1] + dp[i][j] + dp[i][j + 1])) %= MOD;
            }
        } else {
            (dp[i + 1][x[i + 1]] += (dp[i][x[i + 1] - 1] + dp[i][x[i + 1]] + dp[i][x[i + 1] + 1])) %= MOD;
        }
    }

    ll ans = 0;
    for(ll i = 1; i <= m; ++i) {
        (ans += dp[n - 1][i]) %= MOD;
    }

    cout << ans << '\n';
    return 0;
}