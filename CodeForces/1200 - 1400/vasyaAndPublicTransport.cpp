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
ll c1, c2, c3, c4, n, m, a[1007], b[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> c1 >> c2 >> c3 >> c4;
    cin >> n >> m;
    ll x = 0, y = 0;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    for(ll i = 0; i < m; ++i) cin >> b[i];

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        x += min(a[i] * c1, c2);
    }

    for(ll i = 0; i < m; ++i) y += min(b[i] * c1, c2);

    cout << min({x + y, c3 + x, c3 + y, 2 * c3, c4}) << '\n';
}