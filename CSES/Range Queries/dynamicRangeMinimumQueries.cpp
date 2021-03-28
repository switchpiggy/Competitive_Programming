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
        v.assign(size * 2, INF);
    }

    void set(ll p, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(p < (lx + rx)/2) set(p, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(p, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = min(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll p, ll val) {
        set(p, val, 0, 0, size);
    }

    ll range_min(ll l, ll r, ll x, ll lx, ll rx) {
        if(l <= lx && rx <= r) return v[x];
        if(r <= lx || rx <= l) return INF;
        return min(range_min(l, r, 2 * x + 1, lx, (lx + rx)/2), range_min(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll range_min(ll l, ll r) {
        return range_min(l, r, 0, 0, size);
    }
};

ll n, q, x[200007], a, b;
segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    st.init(n);

    for(ll i = 0; i < n; ++i) cin >> x[i], st.set(i, x[i]);

    while(q--) {
        ll t;
        cin >> t;
        if(t == 1) {
            cin >> a >> b;
            a--;
            st.set(a, b);
        } else {
            cin >> a >> b;
            a--;
            cout << st.range_min(a, b) << '\n';
        }
    } 

    return 0;
}