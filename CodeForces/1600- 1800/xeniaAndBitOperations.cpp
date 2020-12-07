#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
ll n, m, a, l, r;

struct segTree {
    ll size;
    vector<ll> v;

    void init(ll x) {
        size = 1;
        while(size <= x) size *= 2;
        v.assign(size * 2, 0);
    }

    void set(ll i, ll val, ll x, ll lx, ll rx, ll depth) {
        if(rx - lx == 1) {
            v[x] = val;
            return;
        }

        if(i < (lx + rx)/2) set(i, val, 2 * x + 1, lx, (lx + rx)/2, depth - 1);
        else set(i, val, 2 * x + 2, (lx + rx)/2, rx, depth - 1);

        if(depth%2) v[x] = v[2 * x + 1] | v[2 * x + 2];
        else v[x] = v[2 * x + 1] ^ v[2 * x + 2];

        return;
    }

    void set(ll i, ll val) {
        set(i, val, 0, 0, size, n - 1);
    }

    ll getAns() {
        return v[0];
    }
};

segTree st;

ll fastpow(ll x, ll y) {
    if(!y) return 1;
    ll recurse = fastpow(x, y/2);
    if(y%2) return recurse * recurse * x;
    return recurse * recurse;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll maxn = fastpow(2, n);
    st.init(maxn);

    for(ll i = 0; i < maxn; ++i) {
        cin >> a;
        st.set(i, a);
    }

    for(ll i = 0; i < m; ++i) {
        cin >> l >> r;
        l--;
        st.set(l, r);

        cout << st.getAns() << '\n';
    }

    return 0;
}