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
#define INF 0x3f3f3f3f3f3f3f3f
#define flout cout << fixed << setprecision(12)
ll n, a[1007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> a[i];
    ll ans = 0;
    for(ll i = 0; i < n - 1; ++i) {
        if(__gcd(a[i], a[i + 1]) > 1) {
            ans++;
        }
    }

    cout << ans << '\n';
    for(ll i = 0; i < n; ++i) {
        cout << a[i] << ' ';
        if(i < n - 1 && __gcd(a[i], a[i + 1]) > 1) {
            cout << 1 << ' ';
        }
    }

    cout << '\n';
    return 0;
}