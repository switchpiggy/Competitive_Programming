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
ll n, m, a[1000007];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    sort(a, a + n);
    ll mid = a[n/2], ans = 0;
    ll i = n/2;
    while(i > 0) {
        i -= min(m, i);
        ans += 2 * abs(a[i] - mid);
    }

    i = n/2;
    while(i < n - 1) {
        i += min(m, n - 1 - i);
        ans += 2 * abs(a[i] - mid);
    }

    cout << ans << '\n';
    return 0;
}