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
    static const ll NONE = 0, ID = 0;
    ll val, lazy;

    node() {
        val = lazy = 0;
    }

    node(ll x, ll y) {
        val = x, lazy = y;
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
        v[x].lazy = node::NONE;
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

    void apply_op(node &x, ll lx, ll rx, ll op) {
        if(op == node::NONE) return;
        x.val += op * (rx - lx);
        x.lazy += op;
    }

    
    ll combine_query(ll x, ll y) {
        return x + y;
    }

    node combine(node x, node y) {
        return node(combine_query(x.val, y.val), node::NONE);
    }

    void lazy_push(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        apply_op(v[2 * x + 1], lx, (lx + rx)/2, v[x].lazy);
        apply_op(v[2 * x + 2], (lx + rx)/2, rx, v[x].lazy);
        
        v[x].lazy = node::NONE;
        return;
    }

    void lazy_pull(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        v[x] = combine(v[2 * x + 1], v[2 * x + 2]);
        return;
    }

    ll range_query(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return node::ID;
        if(l <= lx && rx <= r) return v[x].val;

        lazy_push(x, lx, rx);
        return combine_query(range_query(l, r, 2 * x + 1, lx, (lx + rx)/2), range_query(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll range_query(ll l, ll r) {
        return range_query(l, r, 0, 0, size);
    }

    void range_update(ll l, ll r, ll op, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            apply_op(v[x], lx, rx, op);
            return;
        }
        
        lazy_push(x, lx, rx);
        range_update(l, r, op, 2 * x + 1, lx, (lx + rx)/2);
        range_update(l, r, op, 2 * x + 2, (lx + rx)/2, rx);
        lazy_pull(x, lx, rx);

        return;
    }

    void range_update(ll l, ll r, ll op) {
        range_update(l, r, op, 0, 0, size);
    }
};
ll n, a[100007], q, l, r, x;
segtree<node> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<node> v;
    ll cur = 0;
    for(ll i = 0; i < n; ++i) cin >> a[i], v.push_back(node(a[i], 0)), cur += max(0ll, (i ? a[i] - a[i - 1] : 0));

    st.build(v);
    cout << max((cur + a[0])/2, cur - (cur + a[0])/2 + a[0]) << '\n';
    cin >> q;
    while(q--) {
        cin >> l >> r >> x;
        l--;
        r--;
        if(l) cur -= max(0ll, st.range_query(l, l + 1) - st.range_query(l - 1, l));
        if(r < n - 1) cur -= max(0ll, st.range_query(r + 1, r + 2) - st.range_query(r, r + 1));
        st.range_update(l, r + 1, x);
        if(l) cur += max(0ll, st.range_query(l, l + 1) - st.range_query(l - 1, l));
        if(r < n - 1) cur += max(0ll, st.range_query(r + 1, r + 2) - st.range_query(r, r + 1));

        cout << max((cur + st.range_query(0, 1))/2, cur - (cur + st.range_query(0, 1))/2 + st.range_query(0, 1)) << '\n';
    }

    return 0;
}