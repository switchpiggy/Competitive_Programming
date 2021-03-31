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
    static const ll ID = 0, NONE = 0;

    ll val, lazy1, lazy2;
    node() {
        val = 0;
        lazy1 = lazy2 = 0;
    }

    node(ll x) {
        val = x;
        lazy1 = lazy2 = 0;
    }

    node(ll x, ll y, ll z) {
        val = x, lazy1 = y, lazy2 = z;
    }
};

template<typename node> struct segtree {
    ll size;
    vector<node> v;
    // vector<bool> u;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, node());
    }

    void build(vector<node> &a, ll x, ll lx, ll rx) {
        v[x].lazy1 = v[x].lazy2 = node::NONE;
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
        // u.assign(size * 2, 0);

        build(a, 0, 0, size);
    }

    void apply_op(node &x, ll lx, ll rx, ll op1, ll op2) {
        // if(op1 == node::NONE) return;
        x.val += (rx - lx) * op1;
        x.lazy1 += op1;
        x.val += (((rx - lx) * (rx - lx + 1))/2) * op2;
        x.lazy2 += op2;
    }

    
    ll combine_query(ll x, ll y) {
        return x + y;
    }

    node combine(node x, node y) {
        return node(combine_query(x.val, y.val), node::NONE, node::NONE);
    }

    void lazy_push(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        // if(u[x]) u[2 * x + 1] = u[2 * x + 2] = 1;
        apply_op(v[2 * x + 1], lx, (lx + rx)/2, v[x].lazy1, v[x].lazy2);
        apply_op(v[2 * x + 2], (lx + rx)/2, rx, v[x].lazy1 + ((lx + rx)/2 - lx) * v[x].lazy2, v[x].lazy2);
        
        v[x].lazy1 = v[x].lazy2 = node::NONE;
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

    void range_update(ll l, ll r, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            // u[x] = 1;
            apply_op(v[x], lx, rx, lx - l, 1);
            return;
        }
        
        lazy_push(x, lx, rx);
        range_update(l, r, 2 * x + 1, lx, (lx + rx)/2);
        range_update(l, r, 2 * x + 2, (lx + rx)/2, rx);
        lazy_pull(x, lx, rx);

        return;
    }

    void range_update(ll l, ll r) {
        range_update(l, r, 0, 0, size);
    }
};

ll n, q, t[200007], a, b;
segtree<node> st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    vector<node> v;
    for(ll i = 0; i < n; ++i) cin >> t[i], v.push_back(node(t[i], 0, 0));

    st.build(v);

    while(q--) {
        ll tt;
        cin >> tt >> a >> b;
        if(tt == 1) st.range_update(a - 1, b); 
        else cout << st.range_query(a - 1, b) << '\n';
    }

    return 0;
}