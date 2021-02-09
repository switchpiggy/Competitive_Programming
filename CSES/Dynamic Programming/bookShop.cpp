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
ll n, x, h[1007], s[1007], dp[2][100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    for(ll i = 0; i < n; ++i) cin >> h[i];
    for(ll i = 0; i < n; ++i) cin >> s[i];

    for(ll i = 0; i < n; ++i) {
        for(ll j = 0; j <= x; ++j) {
            dp[1][j] = max(dp[1][j], dp[0][j]);
            if(j + h[i] <= x) {
                //dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
                dp[1][j + h[i]] = max(dp[1][j + h[i]], dp[0][j] + s[i]);
            }
        }

        for(ll j = 0; j <= x; ++j) {
            dp[0][j] = dp[1][j];
            dp[1][j] = 0;
        }
    }

    ll ans = 0;
    for(ll i = 0; i <= x; ++i) ans = max(ans, dp[0][i]);

    cout << ans << '\n';
    return 0;
}