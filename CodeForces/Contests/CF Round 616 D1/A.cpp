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
ll t, n, m, k, a[3507];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m >> k;
        for(ll i = 1; i <= n; ++i) cin >> a[i];
        if(k >= m) {
            ll maxn = -INF;
            for(ll i = 1; i <= m; ++i) maxn = max(maxn, a[i]);
            for(ll i = n; i >= n - m + 1; --i) maxn = max(maxn, a[i]);
            cout << maxn << '\n';
            continue;
        }

        ll ans = 0;
        for(ll i = 1; i <= n - (n - k) + 1; ++i) {
            //cout << i << ' ' << i + (n - k) - 1 << '\n';
            ll mins = INF;
            for(ll j = i; j <= i + (n - k) - (n - m + 1); ++j) {
                //cout << j << ' ' << j + n - m << '\n';
                mins = min(mins, max(a[j], a[j + n - m]));
            }

            ans = max(ans, mins);
        }

        cout << ans << '\n';
    }

    return 0;
}