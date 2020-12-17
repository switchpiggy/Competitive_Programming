#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, q, x, t, a, b, k;

struct segTree {
    ll size;
    vector<ll> v;
    vector<ll> op;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
        op.assign(size * 2, 0);
    }

    void add(ll l, ll r, ll val, ll x, ll lx, ll rx) {
        if(rx <= l || lx >= r) return;
        if(l <= lx && rx <= r) {
            v[x] += val;
            if(rx > lx + 1) op[x] += val;
            return;
        }

        add(l, r, val, 2 * x + 1, lx, (lx + rx)/2);
        add(l, r, val, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];
    }

    void add(ll l, ll r, ll val) {
        add(l, r, val, 0, 0, size);
    }

    ll get(ll i, ll x, ll lx, ll rx) {
        if(rx - lx == 1) return v[x];
        if(i < (lx + rx)/2) return op[x] + get(i, 2 * x + 1, lx, (lx + rx)/2);
        return op[x] + get(i, 2 * x + 2, (lx + rx)/2, rx);
    }

    ll get(ll i) {
        return get(i, 0, 0, size);
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    st.init(n);

    for(ll i = 0; i < n; ++i) {
        cin >> x;
        st.add(i, i + 1, x);
    }

    for(ll i = 0; i < q; ++i) {
        cin >> t;
        if(t == 1) {
            cin >> a >> b >> k;
            st.add(a - 1, b, k);
        } else {
            cin >> k;
            cout << st.get(k - 1) << '\n';
        }
    }

    return 0;
}