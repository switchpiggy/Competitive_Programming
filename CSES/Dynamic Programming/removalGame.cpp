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
ll n, x[5007], dp[5007][5007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    ll sum = 0;
    for(ll i = 1; i <= n; ++i) cin >> x[i], dp[i][i][0] = x[i], dp[i][i][1] = -x[i], sum += x[i];

    for(ll i = 2; i <= n; ++i) {
        for(ll j = 1; j <= n - i + 1; ++j) {
            dp[j][j + i - 1][0] = max(x[j + i - 1] + dp[j][j + i - 2][1], x[j] + dp[j + 1][j + i - 1][1]);
            dp[j][j + i - 1][1] = min(dp[j + 1][j + i - 1][0] - x[j], dp[j][j + i - 2][0] - x[j + i - 1]);
        }
    }

    //cout << dp[1][n][0] << '\n';
    cout << (sum - dp[1][n][0])/2 + dp[1][n][0] << '\n';
    return 0;
}