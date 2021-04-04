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
ll n, k, a[100007], d[100007], p[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < n; ++i) cin >> d[i];

    if(!k) {
        for(ll i = n - 1; i >= 0; --i) a[i] += a[i + 1];
        ll ans = 0;
        for(ll i = 0; i < n; ++i) ans = max(ans, a[i] - d[i]);
        cout << ans << '\n';
    } else if(k == 1) {
        ll ans = 0;
        for(ll i = 0; i < n; ++i) p[i] = (i ? p[i - 1] + a[i] : a[i]);
        ll mins = d[0];
        for(ll i = 0; i < n - 1; ++i) {
            mins = min(mins, d[i]);
            if(i) ans = max(ans, p[n - 1] - d[i] - d[i + 1]);
        }

        for(ll i = 1; i < n - 1; ++i) ans = max(ans, p[n - 1] - a[i] - d[0]);
        for(ll i = 1; i < n; ++i) ans = max(ans, p[n - 1] - p[i - 1] - d[i]);

        ans = max(ans, p[n - 2] - mins + max(0ll, a[n - 1] - d[n - 1]));
        ans = max(ans, p[n - 1] - d[0] - d[1]);

        cout << ans << '\n';
    } else {
        ll mins = INF, sum = 0;
        for(ll i = 0; i < n - 1; ++i) mins = min(mins, d[i]), sum += a[i];
        cout << max({0ll, sum - mins + a[n - 1], a[n - 1] - d[n - 1]}) << '\n';
    }

    return 0;
}
