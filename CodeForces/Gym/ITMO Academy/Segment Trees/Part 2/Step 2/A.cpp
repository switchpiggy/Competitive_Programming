#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, l, r, c;

struct node {
    ll value, op;
};

struct segTree {
    ll size;
    vector<node> v;
    const ll none = LONG_LONG_MAX;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, {0, 0});
    }

    void add(ll l, ll r, ll val, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            v[x].op += val;
            v[x].value += val;
            return;
        }

        add(l, r, val, 2 * x + 1, lx, (lx + rx)/2);
        add(l, r, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x].value = std::min(v[2 * x + 1].value, v[2 * x + 2].value) + v[x].op;
    }

    void add(ll l, ll r, ll val) {
        add(l, r, val, 0, 0, size);
    }

    ll getmin(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || lx >= r) return none;
        if(l <= lx && rx <= r) return v[x].value;                           

        return std::min(getmin(l, r, 2 * x + 1, lx, (lx + rx)/2), getmin(l, r, 2 * x + 2, (lx + rx)/2, rx)) + v[x].op;
    }

    ll getmin(ll l, ll r) {
        return getmin(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    st.init(n);
    for(ll i = 0; i < m; ++i) {
        ll t;
        cin >> t;
        if(t == 1) {
            cin >> l >> r >> c;
            st.add(l, r, c);
        } else {
            cin >> l >> r;
            cout << st.getmin(l, r) << '\n';
        }
    }

    return 0;
}