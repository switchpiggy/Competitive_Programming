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
ll t, n, k, dp[1007][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        m0(dp);
        for(ll i = 1; i <= n; ++i) dp[k - 1][i] = 1;

        ll ans = 1;
        for(ll i = k - 1; i >= 1; --i) {
            if(i%2 == k%2) {
                for(ll j = 1; j <= n; ++j) {
                    (ans += dp[i][j]) %= MOD;
                    (dp[i - 1][j] += dp[i - 1][j - 1]) %= MOD;
                    (dp[i - 1][j + 1] += dp[i][j]) %= MOD;
                }
            } else {
                for(ll j = n; j >= 1; --j) {
                    (ans += dp[i][j]) %= MOD;
                    (dp[i - 1][j] += dp[i - 1][j + 1]) %= MOD;
                    (dp[i - 1][j - 1] += dp[i][j]) %= MOD;
                }
            }
        }

        cout << ans%MOD << '\n';
    }

    return 0;
}