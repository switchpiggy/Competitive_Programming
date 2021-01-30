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
#define flout cout << fixed << setprecision(12)
ll t, n, cnt[200007], dp[200007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        m0(cnt);
        m0(dp);

        for(ll i = 0; i < n; ++i) {
            ll a;
            cin >> a;
            cnt[a]++;
        }

        ll ans = 0;
        for(ll i = 1; i <= 200000; ++i) {
            dp[i] += cnt[i];
            //ans = max(ans, dp[i]);
            for(ll j = 2 * i; j <= 200000; j += i) dp[j] = max(dp[j], dp[i]);
        }

        for(ll i = 1; i <= 200000; ++i) ans = max(ans, dp[i]);
        cout << n - ans << '\n';
    }

    return 0;
}