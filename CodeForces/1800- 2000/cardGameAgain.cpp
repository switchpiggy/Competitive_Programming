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
ll n, k, a[100007];

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 1);
    }

    void set(ll p, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(p < (lx + rx)/2) set(p, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(p, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = (v[2 * x + 1] * v[2 * x + 2])%k;
    }

    void set(ll p, ll val) {
        set(p, val, 0, 0, size);
    }

    ll range_prod(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) return v[x];
        if(r <= lx || rx <= l) return 1;
        return (range_prod(l, r, 2 * x + 1, lx, (lx + rx)/2) * range_prod(l, r, 2 * x + 2, (lx + rx)/2, rx))%k;
    }

    ll range_prod(ll l, ll r) {
        return range_prod(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    st.init(n + 1);
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        st.set(i, a[i]);
    }

    ll ans = 0;
    for(ll i = 0; i < n; ++i) {
        ll l = i, r = n, res = n;
        while(l < r) {
            ll mid = (l + r)/2;
            if(st.range_prod(i, mid + 1) == 0) {
                res = mid;
                r = mid;
            } else l = mid + 1;
        }

        ans += n - res;
    }

    cout << ans << '\n';
    return 0;
}