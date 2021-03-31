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

struct node {
    ll val, set, inc;
    node() {
        val = inc = 0;
        set = -1;
    }

    node(ll x, ll y, ll z) {
        val = x;
        set = y;
        inc = z;
    }

    node(ll x, ll y) {
        set = -1;
        val = x;
        inc = y;
    }
};

template<typename node> struct segtree {
    ll size;
    vector<node> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, node());
    }

    void build(vector<node> &a, ll x, ll lx, ll rx) {
        v[x].set = -1, v[x].inc = 0;
        if(rx - lx == 1) {
            if(lx < sz(a)) v[x] = a[lx];
            return;
        }

        build(a, 2 * x + 1, lx, (lx + rx)/2);
        build(a, 2 * x + 2, (lx + rx)/2, rx);

        lazy_pull(x, lx, rx);
    }

    void build(vector<node> &a) {
        v.clear();
        size = 1;
        while(size <= sz(a)) size *= 2;
        v.assign(size * 2, node());

        build(a, 0, 0, size);
    }

    void apply_op(node &x, ll lx, ll rx, ll s, ll i) {
        if(s == -1 && i == 0) return;
        if(s != -1) x.val = s * (rx - lx), x.set = s, x.inc = 0;
        if(i) x.val += i * (rx - lx), x.inc += i;
    }

    
    ll combine_query(ll x, ll y) {
        return x + y;
    }

    node combine(node x, node y) {
        return node(combine_query(x.val, y.val), 0);
    }

    void lazy_push(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        apply_op(v[2 * x + 1], lx, (lx + rx)/2, v[x].set, v[x].inc);
        apply_op(v[2 * x + 2], (lx + rx)/2, rx, v[x].set, v[x].inc);
        
        v[x].set = -1, v[x].inc = 0;
        return;
    }

    void lazy_pull(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        v[x] = combine(v[2 * x + 1], v[2 * x + 2]);
        return;
    }

    ll range_query(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return 0;
        if(l <= lx && rx <= r) return v[x].val;

        lazy_push(x, lx, rx);
        return combine_query(range_query(l, r, 2 * x + 1, lx, (lx + rx)/2), range_query(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll range_query(ll l, ll r) {
        return range_query(l, r, 0, 0, size);
    }

    void range_update(ll l, ll r, ll op, ll x, ll lx, ll rx, bool inc) {
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            if(inc) apply_op(v[x], lx, rx, -1, op);
            else apply_op(v[x], lx, rx, op, 0);
            return;
        }
        
        lazy_push(x, lx, rx);
        range_update(l, r, op, 2 * x + 1, lx, (lx + rx)/2, inc);
        range_update(l, r, op, 2 * x + 2, (lx + rx)/2, rx, inc);
        lazy_pull(x, lx, rx);

        return;
    }

    void range_update(ll l, ll r, ll op, bool inc) {
        range_update(l, r, op, 0, 0, size, inc);
    }
};

ll n, q, a, b, t[200007], x;
segtree<node> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    vector<node> v;
    for(ll i = 0; i < n; ++i) cin >> t[i], v.push_back({t[i], -1, 0});

    st.build(v);

    while(q--) {
        ll tt;
        cin >> tt;
        if(tt == 3) {
            cin >> a >> b;
            cout << st.range_query(a - 1, b) << '\n';
        } else {
            cin >> a >> b >> x;
            st.range_update(a - 1, b, x, (tt == 1));
        }
    }

    return 0;
}