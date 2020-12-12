#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a[100007], l, r, c;

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void add(ll l, ll r, ll val, ll x, ll lx, ll rx) {
        if(rx <= l || lx >= r) return;
        if(l <= lx && rx <= r) {
            v[x] = max(v[x], val);
            return;
        }

        add(l, r, val, 2 * x + 1, lx, (lx + rx)/2);
        add(l, r, val, 2 * x + 2, (lx + rx)/2, rx);
    }

    void add(ll l, ll r, ll val) {
        add(l, r, val, 0, 0, size);
    }

    ll get(ll i, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            return v[x];
        }

        if(i < (lx + rx)/2) return max(v[x], get(i, 2 * x + 1, lx, (lx + rx)/2));
        else return max(v[x], get(i, 2 * x + 2, (lx + rx)/2, rx));
    }

    ll get(ll i) {
        return get(i, 0, 0, size);
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
            cin >> c;
            cout << st.get(c) << '\n';
        }
    }

    return 0;
}