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

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set_max(ll p, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = max(v[x], val);
            return;
        }

        if(p < (lx + rx)/2) set_max(p, val, 2 * x + 1, lx, (lx + rx)/2);
        else set_max(p, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = max(v[2 * x + 1], v[2 * x + 2]);
    }

    void set_max(ll p, ll val) {
        set_max(p, val, 0, 0, size);
    }

    ll range_max(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) return v[x];
        if(r <= lx || rx <= l) return 0;
        return max(range_max(l, r, 2 * x + 1, lx, (lx + rx)/2), range_max(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll range_max(ll l, ll r) {
        return range_max(l, r, 0, 0, size);
    }
};

ll n, h[200007], a[200007];
segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(ll i = 0; i < n; ++i) cin >> h[i];
    for(ll i = 0; i < n; ++i) cin >> a[i];

    st.init(n + 1);
    for(ll i = 0; i < n; ++i) {
        ll k = st.range_max(0, h[i] + 1);
        st.set_max(h[i], k + a[i]);
    }

    ll ans = 0;
    for(ll i = 1; i <= n; ++i) {
        ans = max(ans, st.range_max(i, i + 1));
    }

    cout << ans << '\n';
    return 0;
}