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
ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll rec = fastpow(x, y/2);
    if(y%2) return ((rec * rec)%MOD * x)%MOD;
    return (rec * rec)%MOD;
}

struct node1 {
    static const ll NONE = 1, ID = 1;
    ll val, lazy;
    node1() {
        val = lazy = 1;
    }

    node1(ll x, ll y) {
        val = x;
        lazy = y;
    }
};

struct node2 {
    static const ll NONE = 0, ID = 0;
    ll val, lazy;
    node2() {
        val = lazy = 0;
    }

    node2(ll x, ll y) {
        val = x, lazy = y;
    }
};

template<typename node> struct prod_segtree {
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
        (x.val *= fastpow(op, rx - lx)) %= MOD;
        (x.lazy *= op) %= MOD;
    }

    
    ll combine_query(ll x, ll y) {
        return (x * y)%MOD;
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

template<typename node> struct or_segtree {
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

    void apply_op(node &x, ll op) {
        if(op == node::NONE) return;
        x.val |= op;
        x.lazy |= op;
    }

    
    ll combine_query(ll x, ll y) {
        return (x|y);
    }

    node combine(node x, node y) {
        return node(combine_query(x.val, y.val), node::NONE);
    }

    void lazy_push(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        apply_op(v[2 * x + 1], v[x].lazy);
        apply_op(v[2 * x + 2], v[x].lazy);
        
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
            apply_op(v[x], op);
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
ll n, m, a[400007], l, r, x, inv[63];
vector<node1> v1;
vector<node2> v2;
prod_segtree<node1> prodst;
or_segtree<node2> orst;
vector<ll> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; ++i) {
        cin >> a[i];
        v1.push_back(node1(a[i], 1));
        ll cur = 0;
        for(ll j = 0; j < 62; ++j) if(a[i]%p[j] == 0) cur |= (1ll << j);
        v2.push_back(node2(cur, 0));
    }   

    for(ll i = 0; i < 62; ++i) {
        inv[i] = fastpow(p[i], MOD - 2);
    }

    prodst.build(v1);
    orst.build(v2);
    while(m--) {
        string s;
        cin >> s;
        if(s == "MULTIPLY") {
            cin >> l >> r >> x;
            prodst.range_update(l - 1, r, x);
            ll cur = 0;
            for(ll j = 0; j < 62; ++j) if(x%p[j] == 0) cur |= (1ll << j);
            orst.range_update(l - 1, r, cur);
        } else {
            cin >> l >> r;
            ll prod = prodst.range_query(l - 1, r), mask = orst.range_query(l - 1, r);
            ll ans = prod;
            for(ll i = 0; i < 62; ++i) {
                if(mask & (1ll << i)) {
                    (ans *= p[i] - 1) %= MOD;
                    (ans *= inv[i]) %= MOD;
                }
            }

            cout << ans << '\n';
        }
    }

    return 0;
}