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
ll n, k, a[407], dp[407][407];

void fileIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fileIO("snakes");

    inf(dp);
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i) cin >> a[i];

    ll maxn = 0, sum = 0;
    for(ll i = 1; i <= n; ++i) {
        maxn = max(maxn, a[i]);
        sum += a[i];
        dp[0][i] = maxn * i - sum;
    }

    for(ll i = 1; i <= k; ++i) {
        for(ll j = 1; j <= n; ++j) {
            maxn = 0, sum = 0;
            for(ll l = j + 1; l <= n; ++l) {
                maxn = max(maxn, a[l]);
                sum += a[l];
                dp[i][l] = min(dp[i][l], dp[i - 1][j] + maxn * (l - j) - sum);
            }
        }
    }

    /*for(ll i = 0; i <= k; ++i) {
        for(ll j = 1; j <= n; ++j) cout << dp[i][j] << ' ';
        cout << '\n';
    }*/

    ll ans = INF;
    for(ll i = 0; i <= k; ++i) ans = min(ans, dp[i][n]);
    cout << ans << '\n';
    return 0;
}