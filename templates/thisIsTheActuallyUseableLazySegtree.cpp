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

    void apply_op(node &x, ll op) {
        if(op == NONE) return;
    }

    node combine(node x, node y) {
        return node(combine_op(x, y), node::NONE);
    }

    ll combine_op(ll x, ll y) {
        
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
        return combine_op(range_query(l, r, 2 * x + 1, lx, (lx + rx)/2), range_query(l, r, 2 * x + 2, (lx + rx)/2, rx));
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}