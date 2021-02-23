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

struct node {
    ll op, val;
    node(ll x, ll y) {
        op = x;
        val = y;
    }
};

struct segTree {
    ll size;
    vector<node> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, node(-1, 0));
    }

    void propagate(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        apply_op(v[2 * x + 1], v[x], lx, (lx + rx)/2);
        apply_op(v[2 * x + 2], v[x], (lx + rx)/2, rx);
        v[x].op = -1;
        v[x].val = 0;
        return;
    }

    void apply_op(node &x, node y, ll lx, ll rx) {
        if(y.op == -1) return;
        x.op = y.op;
        x.val = y.op * (rx - lx);
    }

    void pull(node &x, node y, node z) {
        x.val = y.val + z.val;
    }

    void range_assign(ll val, ll l, ll r, ll x, ll lx, ll rx) {
        propagate(x, lx, rx);
        if(rx <= l || lx >= r) return;
        if(l <= lx && rx <= r) {
            v[x].val = (rx - lx) * val;
            v[x].op = val;
            return;
        }

        range_assign(val, l, r, 2 * x + 1, lx, (lx + rx)/2);
        range_assign(val, l, r, 2 * x + 2, (lx + rx)/2, rx);
        pull(v[x], v[2 * x + 1], v[2 * x + 2]);
    }

    void range_assign(ll val, ll l, ll r) {
        range_assign(val, l, r, 0, 0, size);
    }

    ll range_sum(ll l, ll r, ll x, ll lx, ll rx) {
        propagate(x, lx, rx);
        if(rx <= l || lx >= r) return 0;
        if(l <= lx && rx <= r) return v[x].val;
        
        ll res = (range_sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + range_sum(l, r, 2 * x + 2, (lx + rx)/2, rx));
        if(v[x].op != -1) return res * v[x].op;
        return res;
    }

    ll range_sum(ll l, ll r) {
        return range_sum(l, r, 0, 0, size);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}