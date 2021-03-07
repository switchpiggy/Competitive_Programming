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
ll n, a[27], b[27], c[27];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n;++i) cin >> a[i];
    for(ll i = 1; i <= n; ++i) cin >> b[i];
    for(ll i = 1; i < n; ++i) cin >> c[i];
    ll ans = 0;

    for(ll i = 0; i < n; ++i) {
        ans += b[a[i]];
        if(i < n - 1 && a[i + 1] == a[i] + 1) ans += c[a[i]];
    }

    cout << ans << '\n';
    return 0;
}