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
ll t, n, k, a[1007], occ[1007], occ2[1007];
bool used[1007];
const ll MOD = 1e9 + 7;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return ((recurse * recurse)%MOD * x)%MOD;
    return (recurse * recurse)%MOD;
}

ll inv(ll x) {
    return fastpow(x, MOD - 2);
}

ll choose(ll x, ll y) {
    ll res = 1;
    for(ll i = 1; i <= y; ++i) {
        res = (res * (x - y + i))%MOD;
        res = (res * inv(i))%MOD;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while(t--) {
        m0(occ);
        m0(occ2);
        m0(used);
        cin >> n >> k;
        for(ll i = 0; i < n; ++i) cin >> a[i];

        for(ll i = 0; i < n; ++i) occ[a[i]]++;

        sort(a, a + n, greater<ll>());

        for(ll i = 0; i < k; ++i) {
            occ2[a[i]]++;
        }

        ll ans = 1;
        for(ll i = 1; i <= n; ++i) {
            if(used[a[i]] || !occ2[a[i]]) continue;
            used[a[i]] = 1;
            ans = (ans * choose(occ[a[i]], occ2[a[i]]))%MOD;
        }

        cout << ans << '\n';
    }

    return 0;
}