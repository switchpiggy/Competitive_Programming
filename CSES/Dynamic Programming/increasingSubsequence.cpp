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
ll n, x[200007], dp[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inf(dp);

    dp[0] = 0;
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> x[i];

    for(ll i = 0; i < n; ++i) {
        ll k = lower_bound(dp, dp + n + 1, x[i]) - dp;
        if(!k) continue;
        k--;

        dp[k + 1] = min(dp[k + 1], x[i]);
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) if(dp[i] != INF) ans = i;

    cout << ans << '\n';
    return 0;
}