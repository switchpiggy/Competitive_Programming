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
ll n, x, y, dp[20000007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x >> y;
    for(ll i = 0; i <= n; ++i) dp[i] = i * x;

    for(ll i = 1; i <= n + 1; ++i) {
        dp[2 * i] = min(dp[2 * i], dp[i] + y);
        dp[2 * i + 1] = min(dp[2 * i + 1], dp[i] + x + y);
        dp[2 * i - 1] = min(dp[2 * i - 1], dp[i] + x + y);
    }

    //for(ll i = 0; i <= n + 1; ++i) cout << dp[i] << ' ';
    //cout << '\n';

    cout << dp[n] << '\n';
    return 0;
}