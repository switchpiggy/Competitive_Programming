#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node {
    //node stuff here
    ll sum, op = 0;
    
    node() {
        sum = 0;
    }

    node(ll x) {
        sum = x;
    }
};

struct segTree {
    ll size;
    vector<node> v;

    node IDENTITY = node(0);

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, node(0));
    }

    void build_dfs(vector<node> &a, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            if(lx < (ll)a.size()) v[x] = a[lx];
            return;
        }

        build_dfs(a, 2 * x + 1, lx, (lx + rx)/2);
        build_dfs(a, 2 * x + 2, (lx + rx)/2, rx);
        v[x] = merge(v[2 * x + 1], v[2 * x + 2]);
        return;
    }

    void build(vector<node> &x) {
        size = 1;
        while(size <= (ll)x.size()) size *= 2;
        v.resize(size * 2);

        build_dfs(x, 0, 0, size);
    }

    void apply_op(node &x, node y) {
        //combiner function for operations
        x.sum += y.sum;
        x.op += y.sum;
        return;
    }

    node merge(node y, node z) {
        return node(y.sum + z.sum);
    }

    void modify(node &x, node z) {
        x.sum = z.sum;
    }

    void lazy_prop(ll x, ll lx, ll rx) {
        if(rx - lx == 1) return;
        apply_op(v[2 * x + 1], v[x]);
        apply_op(v[2 * x + 2], v[x]);
        v[x] = IDENTITY;
        return;
    }

    void point_update(ll i, node val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            apply_op(v[x], val);
            return;
        }

        if(i < (lx + rx)/2) point_update(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else point_update(i, val, 2 * x + 2, (lx + rx)/2, rx);
        v[x] = merge(v[2 * x + 1], v[2 * x + 2]);
    }

    void point_update(ll i, node val) {
        point_update(i, val, 0, 0, size);
    }

    node range_query(ll x, ll lx, ll rx, ll l, ll r) {
        if(lx >= r || rx <= l) return IDENTITY;
        if(l <= lx && rx <= r) return v[x];

        return merge(range_query(2 * x + 1, lx, (lx + rx)/2, l, r), range_query(2 * x + 2, (lx + rx)/2, rx, l, r));
    }

    node range_query(ll l, ll r) {
        return range_query(0, 0, size, l, r);
    }

    void range_update(node val, ll x, ll lx, ll rx, ll l, ll r) {
        lazy_prop(x, lx, rx);
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            apply_op(v[x], val);
            return;
        }

        range_update(val, 2 * x + 1, lx, (lx + rx)/2, l, r);
        range_update(val, 2 * x + 2, (lx + rx)/2, rx, l, r);
    }

    void range_update(node val, ll l, ll r) {
        range_update(val, 0, 0, size, l, r);
    }

    node point_query(ll i, ll x, ll lx, ll rx) {
        lazy_prop(x, lx, rx);
        if(rx - lx == 1) return v[x];
        node res = node(v[x].op);
        if(i < (lx + rx)/2) apply_op(res, point_query(i, 2 * x + 1, lx, (lx + rx)/2));
        else apply_op(res, point_query(i, 2 * x + 2, (lx + rx)/2, rx));
        return res;
    }

    node point_query(ll i) {
        return point_query(i, 0, 0, size);
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
}