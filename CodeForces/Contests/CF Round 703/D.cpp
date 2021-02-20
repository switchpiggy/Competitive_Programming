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
ll n, k, a[200007];

bool check(ll x) {
    vector<ll> pref(n), mins(n);
    for(ll i = 0; i < n; ++i) {
        pref[i] = (a[i] >= x ? 1 : -1) + (i ? pref[i - 1] : 0);
    }

    mins[0] = min(pref[0], 0ll);
    for(ll i = 1; i < n; ++i) {
        mins[i] = min(mins[i - 1], pref[i]);
    }

    if(pref[k - 1] > 0) return 1;
    for(ll i = k; i < n; ++i) {
        if(pref[i] - mins[i - k] > 0) return 1;
    }

    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(ll i = 0; i < n; ++i) cin >> a[i];

    ll l = 0, r = 1e12, ans = -1;
    while(l < r) {
        ll mid = (l + r)/2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        } else r = mid;
    }

    cout << ans << '\n';
    return 0;
}