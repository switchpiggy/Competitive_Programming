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
ll t, n, s[5007], tag[5007], dp[5007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        for(ll i = 1; i <= n; ++i) cin >> tag[i];
        for(ll i = 1; i <= n; ++i) cin >> s[i];

        m0(dp);
        for(ll i = 2; i <= n; ++i) {
            for(ll j = i - 1; j >= 1; --j) {
                if(tag[i] == tag[j]) continue;
                ll di = dp[i], dj = dp[j];
                dp[j] = max(dp[j], di + abs(s[i] - s[j]));
                dp[i] = max(dp[i], dj + abs(s[i] - s[j]));
            }
        }

        ll ans = 0;
        for(ll i = 1; i <= n; ++i) ans = max(ans, dp[i]);
        cout << ans << '\n';
    }

    return 0;
}