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

    void set(ll i, ll x, ll lx, ll rx) {
        if(rx - lx == 1) {
            v[x] = 1 - v[x];
            return;
        }

        if(i < (lx + rx)/2) set(i, 2 * x + 1, lx, (lx + rx)/2);
        else set(i, 2 * x + 2, (lx + rx)/2, rx);

        v[x] = v[2 * x + 1] + v[2 * x + 2];

        return;
    }

    void set(ll i) {
        set(i, 0, 0, size);
        return;
    }

    ll find(ll k, ll lx, ll rx, ll x, ll cur) {
        if(rx - lx == 1) {
            return lx;
        }

        if(v[2 * x + 1] + cur >= k) {
            return find(k, lx, (lx + rx)/2, 2 * x + 1, cur);
        } else return find(k, (lx + rx)/2, rx, 2 * x + 2, cur + v[2 * x + 1]);
    }

    ll find(ll k) {
        return find(k, 0, size, 0, 0);
    }
};

ll n, m, a, t, k;
segTree st;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    st.init(n);
    for(ll i = 0; i < n; ++i) {
        cin >> a;
        if(a) st.set(i);
    }

    for(ll i = 0; i < m; ++i) {
        cin >> t;
        if(t == 1) {
            cin >> k;
            st.set(k);
        } else {
            cin >> k;
            cout << st.find(k + 1) << '\n';
        }
    }

    return 0;
}