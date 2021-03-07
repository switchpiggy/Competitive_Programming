#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, a, t, x, y;

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set(ll i, ll val, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] ^= val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1]^v[2 * x + 2];
    }

    void set(ll i, ll val) {
        set(i, val, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || r <= lx) return 0;
        if(l <= lx && rx <= r) return v[x];
        return sum(l, r, 2 * x + 1, lx, (lx + rx)/2)^sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll sum(ll l, ll r) {
        return sum(l, r, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    st.init(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a;
        st.set(i, a);
    }

    while(q--) {
        cin >> t >> x >> y;
        if(t == 1) st.set(x - 1, y);
        else {
            cout << st.sum(x - 1, y) << '\n';
        }
    }

    return 0;
}