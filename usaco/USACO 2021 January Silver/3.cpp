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
ll n, a[1007][1007], r[2][1007], c[2][1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) cin >> a[i][j];
    }

    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            r[i%2][j] += a[i][j];
            c[j%2][i] += a[i][j];
        }   
    }

    ll ans = 0, ans2 = 0;
    for(ll i = 1; i <= n; ++i) {
        ans += max(r[0][i], r[1][i]);
        ans2 += max(c[0][i], c[1][i]);
    }

    cout << max(ans, ans2) << '\n';
    return 0;
}