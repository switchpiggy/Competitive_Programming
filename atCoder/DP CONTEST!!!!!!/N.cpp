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
ll n, a[407], dp[407][407], sum[407][407];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;
    inf(dp);
    for(ll i = 1; i <= n; ++i) cin >> a[i], dp[i][i] = 0;

    for(ll i = 1; i <= n; ++i) {
        ll cur = 0;
        for(ll j = i; j <= n; ++j) {
            cur += a[j];
            sum[i][j] = cur;
        }
    }
    
    for(ll i = 2; i <= n; ++i) {
        for(ll j = 1; j + i - 1 <= n; ++j) {
            for(ll k = 0; k < i; ++k) {
                dp[j][j + i - 1] = min(dp[j][j + i - 1], dp[j][j + k] + dp[j + k + 1][j + i - 1] + sum[j][j + k] + sum[j + k + 1][j + i - 1]);
            }
        }
    }

    cout << dp[1][n] << '\n';
    return 0;
}   