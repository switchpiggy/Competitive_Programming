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
ll t, n, m, k, dp[37][37][57];

ll solve(ll x, ll y, ll g) {
    if(dp[x][y][g] || !g || g == x * y) return dp[x][y][g];
    ll res = INF;
    for(ll i = 1; i < x; ++i) {
        for(ll j = 0; j <= g; ++j) {
            res = min(res, y * y + solve(x - i, y, g - j) + solve(i, y, j));         
        }
    }

    for(ll i = 1; i < y; ++i) {
        for(ll j = 0; j <= g; ++j) {
            res = min(res, x * x + solve(x, y - i, g - j) + solve(x, i, j));         
        }
    }

    return dp[x][y][g] = res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        cout << solve(n, m, k) << '\n';
    }

    return 0;
}