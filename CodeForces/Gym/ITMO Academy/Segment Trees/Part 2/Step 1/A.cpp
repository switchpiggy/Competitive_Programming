#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set(ll i, ll val, ll lx, ll rx, ll x) {
        if(rx - lx == 1) {
            v[x] += val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, lx, (lx + rx)/2, 2 * x + 1);
        else set(i, val, (lx + rx)/2, rx, 2 * x + 2);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void set(ll i, ll val) {
        set(i, val, 0, size, 0);
    }

    void rangeSet(ll l, ll r, ll val) {
        set(l, val);
        set(r, -val);
    }

    ll prefixSum(ll r, ll x, ll lx, ll rx) {
        if(rx <= r) return v[x];
        if(lx >= r) return 0;
        return prefixSum(r, 2 * x + 1, lx, (lx + rx)/2) + prefixSum(r, 2 * x + 2, (lx + rx)/2 , rx);
    }

    ll prefixSum(ll r) {
        return prefixSum(r, 0, 0, size);
    }
};

ll n, m, l, r, val;
segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    st.init(n);
    for(ll i = 0; i < m; ++i) {
        ll t;
        cin >> t;
        if(t == 2) {
            cin >> l;
            cout << st.prefixSum(l + 1) << '\n';
        } else {
            cin >> l >> r >> val;
            st.rangeSet(l, r, val);
        }
    }
}