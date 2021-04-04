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
ll n, m, dp[15][5007], c[5007][5007];

void init() {
    c[0][0] = 1;
    for(ll i = 1; i <= 5000; ++i) {
        c[i][0] = c[i][i] = 1;
        for(ll j = 1; j < i; ++j) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j])%MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    init();
    cin >> n >> m;
    dp[0][0] = 1;

    ll lg = (ll)(floor(log2(m)));

    for(ll i = 0; i <= lg; ++i) {
        for(ll j = 0; j <= m; ++j) {
            // cout << dp[i][j] << ' ';
            for(ll k = 0; k <= n; k += 2) {
                if(j + k * (1 << i) > m) continue;
                (dp[i + 1][j + k * (1 << i)] += c[n][k] * dp[i][j]) %= MOD;
            }
        }
    }

    cout << dp[lg][m] << '\n';
    return 0;
}