#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct node {
    ll a, b, c, d;
};
ll n, m, r;

struct segTree {
    ll size;
    vector<node> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, {1, 1, 1, 1});
    }

    node multiply(node x, node y) {
        return {((x.a * y.a)%r + (x.b * y.c)%r)%r, ((x.a * y.b)%r + (x.b * y.d)%r)%r, ((x.c * y.a)%r + (x.d * y.c)%r)%r, ((x.c * y.b)%r + (x.d * y.d)%r)%r};
    }

    void set(ll i, node val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = multiply(v[2 * x + 1], v[2 * x + 2]);
    }

    void set(ll i, node val) {
        set(i, val, 0, 0, size);
    }

    node rangeMultiply(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || lx >= r) return {1, 1, 1, 1};
        if(l <= lx && rx <= r) return v[x];
        return multiply(rangeMultiply(l, r, 2 * x + 1, lx, (lx + rx)/2), rangeMultiply(l, r, 2 * x + 2, (lx + rx)/2, rx));
    }

    node rangeMultiply(ll l, ll r) {
        return rangeMultiply(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> r >> n >> m;
    st.init(n);

    for(ll i = 0; i < n; ++i) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        st.set(i, {a, b, c, d});
    }

    for(ll i = 0; i < m; ++i) {
        ll l, k;
        cin >> l >> k;
        l--;
        node cur = st.rangeMultiply(l, k);
        cout << cur.a << ' ' << cur.b << '\n' << cur.c << ' ' << cur.d << '\n';
        cout << '\n';
    }

    return 0;
}