#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m;

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
            v[x] += val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void setRange(ll l, ll r, ll val) {
        set(l, val, 0, 0, size);
        set(r, -1 * val, 0, 0, size);
    }

    ll sum(ll l, ll r, ll x, ll lx, ll rx) {
        if(rx <= l || lx >= r) return 0;
        if(l <= lx && rx <= r) return v[x];
        return sum(l, r, 2 * x + 1, lx, (lx + rx)/2) + sum(l, r, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll sum(ll pref) {
        return sum(0, pref, 0, 0, size);
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
            ll l, r, vv;
            cin >> l >> r >> vv;
            st.setRange(l, r, vv);
        } else {
            ll k;
            cin >> k;
            cout << st.sum(k + 1) << '\n';
        }
    }

    return 0;
}
