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
ll r, g, dp[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> r >> g;
    
    ll h = -1, l = 0, q = 1007;
    while(l < q) {
        ll mid = (l + q)/2, cur = (mid * (mid + 1))/2;
        if(cur <= r + g) {
            h = mid;
            l = mid + 1;
        } else q = mid;
    }

    dp[0] = 1;
    for(ll i = 0; i < h; ++i) {
        for(ll j = r - (i + 1); j >= 0; --j) {
            (dp[j + (i + 1)] += dp[j]) %= MOD;
        }
    }

    ll ans = 0;
    for(ll i = 0; i <= r; ++i) {
        if(g + i >= (h * (h + 1))/2) {
            (ans += dp[i]) %= MOD;
        }
    }

    cout << ans << '\n';
}