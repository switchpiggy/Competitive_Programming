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
    const ll mod = 1000000007;

    void build(ll x, ll lx, ll rx) {
        v[x].op = 1;
        if(rx - 1 == lx) {
            v[x].value = 1;
            return;
        }

        //v[x].op = 1;

        build(2 * x + 1, lx, (lx + rx)/2);
        build(2 * x + 2, (lx + rx)/2, rx);

        v[x].value = v[2 * x + 1].value + v[2 * x + 2].value;
    }

    void init(ll x) {
        size = 1;
        while(size < x) size *= 2;
        v.resize(2 * size);
        build(0, 0, size);
    }

    void modify(ll l, ll r, ll val, ll x, ll lx, ll rx) {
        if(lx >= r || rx <= l) return;
        if(l <= lx && rx <= r) {
            v[x].value *= val;
            v[x].value %= mod;
            v[x].op *= val;
            v[x].op %= mod;
            return;
        }

        modify(l, r, val, 2 * x + 1, lx, (lx + rx)/2);
        modify(l, r, val, 2 * x + 2, (lx + rx)/2, rx);
        v[x].value = ((v[2 * x + 1].value%mod + v[2 * x + 2].value%mod)%mod * v[x].op)%mod;
    }

    void modify(ll l, ll r, ll val) {
        modify(l, r, val, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || r <= lx) return 0;
        if(l <= lx && rx <= r) return v[x].value%mod;

        return ((sum(l, r, 2 * x + 1, lx, (lx + rx)/2)%mod + sum(l, r, 2 * x + 2, (lx + rx)/2, rx)%mod)%mod * v[x].op)%mod;
    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, size)%mod;
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
            st.modify(l, r, c%(1000000007));
        } else {
            cin >> l >> r;
            cout << st.sum(l, r) << '\n';
        }
    }

    return 0;
}