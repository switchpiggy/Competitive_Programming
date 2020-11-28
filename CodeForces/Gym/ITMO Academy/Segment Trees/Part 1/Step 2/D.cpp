#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, b, c;

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, INT_MIN);
    }

    void set(ll i, ll x, ll val, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(i < (lx + rx)/2) set(i, 2 * x + 1, val, lx, (lx + rx)/2);
        else set(i, 2 * x + 2, val, (lx + rx)/2, rx);
        
        v[x] = max(v[2 * x + 1], v[2 * x + 2]);

        return;
    }

    void set(ll i, ll x) {
        set(i, 0, x, 0, size);
    }

    ll lowerBound(ll x, ll lx, ll rx, ll val, ll l) {
        if(rx <= l) return LONG_LONG_MAX;
        if(rx - lx == 1) {
            if(v[x] >= val) return lx;
            return LONG_LONG_MAX;
        }

        if(lx >= l) {
            if(v[2 * x + 1] >= val) return lowerBound(2 * x + 1, lx, (lx + rx)/2, val, l);
            return lowerBound(2 * x + 2, (lx + rx)/2, rx, val, l);
        } else {
            return min(lowerBound(2 * x + 1, lx, (lx + rx)/2, val, l), lowerBound(2 * x + 2, (lx + rx)/2, rx, val, l));
        }

        return LONG_LONG_MAX;
    }

    ll lowerBound(ll val, ll l) {
        ll cur = lowerBound(0, 0, size, val, l);
        if(cur == LONG_LONG_MAX) return -1;
        return cur;
    }
};

segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    st.init(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a;
        st.set(i, a);
    }

    for(ll i = 0; i < m; ++i) {
        cin >> a;
        if(a == 1) {
            cin >> b >> c;
            st.set(b, c);
        } else {
            cin >> b >> c;
            cout << st.lowerBound(b, c) << '\n';
        }
    }

    return 0;
}