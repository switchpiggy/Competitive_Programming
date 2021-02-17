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
ll t, n, dp[1000007][2];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    dp[1][0] = dp[1][1] = 1;
    for(ll i = 1; i < 1000000; ++i) {
        dp[i + 1][0] = (2 * dp[i][0] + dp[i][1])%MOD;
        dp[i + 1][1] = (dp[i][0] + 4 * dp[i][1])%MOD;
    }

    cin >> t;
    while(t--) {
        cin >> n;
        cout << (dp[n][1] + dp[n][0])%MOD << '\n';
    }

    return 0;
}