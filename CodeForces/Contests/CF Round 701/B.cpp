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
ll n, q, k, a[100007], mp[100007], pref[100007];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q >> k;
    for(ll i = 1; i <= n; ++i) cin >> a[i], mp[i] = max(mp[i - 1], a[i]);

    for(ll i = 1; i <= n; ++i) {
        pref[i] = pref[i - 1] + (a[i + 1] - a[i - 1] - 2);
    }

    while(q--) {
        ll l, r;
        cin >> l >> r;
        cout << pref[r - 1] - pref[l] + (k - a[r] + a[r] - a[r - 1] - 1) + (a[l + 1] - a[l] - 1 + a[l] - 1) << '\n';
    }

    return 0;
}